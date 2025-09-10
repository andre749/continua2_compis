cmake_minimum_required(VERSION 3.27)
project(Evaluaci�n_Continua_1___Prueba_2___version_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Evaluaci�n_Continua_1___Prueba_2___version_1
        first.cpp
        first.h
        follow.cpp
        follow.h
        grammar.cpp
        grammar.h
        main.cpp
        parser.cpp
        parser.h
        table.cpp
        table.h
        utils.h)
