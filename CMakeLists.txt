cmake_minimum_required(VERSION 4.4)
project(c_learning C)

set(CMAKE_C_STANDARD 17)

add_executable(c_learning
        first_calc/first_calc.c
        mini_statistics_engine/mini_statistics_engine.c
        main.c
        first_calc/first_calc.h
        mini_statistics_engine/mini_statistics_engine.h
        own_tools/input_int.c
        own_tools/own_tools.h
        mini_inventory/mini_inventory.c
        mini_inventory/mini_inventory.h
        own_tools/input_str.c
        text_analyzer/text_analyzer.c
        text_analyzer/text_analyzer.h)
