cmake_minimum_required(VERSION 3.30)
project(Abstraction_and_Encapsulation)

set(CMAKE_CXX_STANDARD 20)

add_executable(Abstraction_and_Encapsulation main.cpp
        Functions.h
        Class/Employee.cpp
        Class/Employee.h
        Class/EmployeeTypes.cpp
        Class/EmployeeTypes.h
        Class/Company.cpp
        Class/Company.h
        Functions.cpp)
