cmake_minimum_required(VERSION 3.10)
set(This test)
set(Sources
product_test.cpp
run_tests.cpp
shoppingList_test.cpp 
user_test.cpp
)

add_executable(
    ${This} ${Sources}
)

target_link_libraries(
    ${This} PUBLIC 
    gtest_main
    my_test
)

add_test(
    NAME ${This}
    COMMAND ${This}
)