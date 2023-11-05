cmake_minimum_required(VERSION 3.8)

project(lab2_zal)

add_library(Lab2 INTERFACE)
target_include_directories(Lab2 INTERFACE include)
set_target_properties(Lab2 PROPERTIES
    INTERFACE_COMPILE_FEATURES cxx_std_17
)

add_executable(zad1 "test.cpp" "zad1.cpp")
add_executable(zad2 "test.cpp" "zad2.cpp")
add_executable(zad3 "test.cpp" "zad3.cpp")

target_link_libraries(zad1 Lab2)
target_link_libraries(zad2 Lab2)
target_link_libraries(zad3 Lab2)
