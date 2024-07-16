cmake_minimum_required(VERSION 3.10)
set(This project)  # Main library name
project(project C CXX)

# Set the C++ standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE on)
enable_testing()

# Add Google Test as a subdirectory
add_subdirectory(googletest)

# Specify header files
set(Headers
    Observer.h 
    Product.h 
    ShoppingList.h 
    Subject.h 
    User.h 
)

# Specify source files
set(Sources
    Main.cpp
    ShoppingList.cpp 
    User.cpp
)

# Create a static library
add_library(${This} STATIC ${Sources} ${Headers})

# Add the include directories for the test
target_include_directories(${This} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)

# Add the test subdirectory
add_subdirectory(test)

# Set runtime library for Debug and Release
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")