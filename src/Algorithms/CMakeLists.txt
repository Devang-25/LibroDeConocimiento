file(GLOB libro_src_algorithms_cpp
    "*.cpp"
    "Graph/*.cpp")

add_library(libro_src_algorithms ${libro_src_algorithms_cpp})

add_library(libro_src_algorithms_FOR_TESTING ${libro_src_algorithms_cpp})
target_compile_definitions(libro_src_algorithms_FOR_TESTING PUBLIC DONT_PRINT_TO_SCREEN)
