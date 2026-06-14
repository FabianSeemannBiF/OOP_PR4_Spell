cmake_minimum_required(VERSION 4.2)
project(OOP_PR4_Spell)

set(CMAKE_CXX_STANDARD 14)

include_directories(includes)

add_executable(OOP_PR4_Spell
        includes/Spell.h
        src/Spell.cpp
        main.cpp)
