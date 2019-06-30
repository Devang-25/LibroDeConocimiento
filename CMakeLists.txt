cmake_minimum_required(VERSION 3.10.2)
project(libro)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -Werror -pedantic)

add_subdirectory(src)
add_subdirectory(test)
