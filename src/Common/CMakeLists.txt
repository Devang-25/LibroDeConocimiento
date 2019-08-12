file(GLOB libro_src_common_cpp
    "*.cpp"
    "File/*.cpp")

add_library(libro_src_common ${libro_src_common_cpp})
