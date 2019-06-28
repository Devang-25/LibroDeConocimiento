cmake_minimum_required(VERSION 3.10.2)
project(libro)

add_subdirectory(src)
add_subdirectory(test)

set(CMAKE_CXX_STANDARD 14)

add_compile_options(-Wall -Wextra -Werror -pedantic)
