cmake_minimum_required(VERSION 2.8)

project("cop")

include_directories(include)

add_definitions(-std=c++14
                -Wall
                -Werror
                -g
                -fPIC
                -O2
                )


# add_subdirectory(examples)
add_subdirectory(tests)

