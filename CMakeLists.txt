cmake_minimum_required(VERSION 3.10)
set(This project)
project(${This} C CXX)

# Imposta lo standard C++ (ad esempio C++11)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE on)
enable_testing()

# Aggiungi Google Test come sotto-progetto
add_subdirectory(googletest)
set(Headers
Observer.h 
Product.h 
ShoppingList.h 
Subject.h 
User.h 
)
set(Sources
Main.cpp
ShoppingList.cpp 
User.cpp
)
add_library(${This} STATIC ${Sources} ${Headers})
add_subdirectory(test)
