// main.cpp
#include "grammar.h"
#include "first.h"
#include "follow.h"
#include "table.h"
#include "parser.h"
#include "utils.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // ====================================================
    // 1. Cargar la gramática desde archivo
    // ====================================================
    Grammar gramatica;
    if (!gramatica.loadFromFile("gramatica.txt")) {
        cerr << "Error al cargar la gramática.\n";
        return 1;
    }

    cout << "=== Gramática cargada ===\n";
    gramatica.print();  // Imprime todas las reglas de la gramática

    // ====================================================
    // 2. Calcular conjuntos First
    // ====================================================
    First primeros(gramatica);
    primeros.compute();  // Calcula First para cada no terminal
    cout << "\n=== Conjuntos First ===\n";
    primeros.print();    // Muestra First de cada no terminal

    // ====================================================
    // 3. Calcular conjuntos Follow
    // ====================================================
    Follow siguientes(gramatica, primeros);
    siguientes.compute();  // Calcula Follow para cada no terminal usando First
    cout << "\n=== Conjuntos Follow ===\n";
    siguientes.print();    // Muestra Follow de cada no terminal

    // ====================================================
    // 4. Construir tabla LL(1)
    // ====================================================
    Table tablapredictiva(gramatica, primeros, siguientes);  // Crea la tabla de análisis LL(1)
    cout << "\n=== Tabla LL(1) ===\n";
    tablapredictiva.print();            // Muestra la tabla en formato legible

    // ====================================================
    // 5. Inicializar parser y parsear entrada
    // ====================================================
    int startId = tablapredictiva.getNonTerminalId(gramatica.initialState);
    Parser parseLL1(tablapredictiva,startId);   // Crear parser

    // Entrada tokenizada (terminales según la gramática)
    vector<string> entrada = {"1", "3" , "$"};  

    cout << "\n=== Parseando entrada ===\n";
    bool valor = parseLL1.parse(entrada);  // Ejecuta el parseo LL(1)

    return 0;
}
