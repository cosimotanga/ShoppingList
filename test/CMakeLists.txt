cmake_minimum_required(VERSION 3.10)
project(my_test)

set(Sources
    product_test.cpp
    shoppingList_test.cpp 
    user_test.cpp
)

add_executable(my_test ${Sources})

# Link with the main library and Google Test
target_link_libraries(my_test PRIVATE gtest_main project)

add_test(
    NAME my_test
    COMMAND my_test
)

# Set runtime library for Debug and Release
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
