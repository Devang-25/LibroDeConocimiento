file(GLOB libro_src_coderbyte_cpp
    "*.cpp"
    "Challenges/*.cpp"
    "Challenges/EasyDifficulty/*.cpp")

# Do not overthink about the .. in <include_directories(..)>, it is just the parent directory.
# This command is not needed anymore as ../CMakeLists.txt already included this.
# include_directories(..)

add_library(libro_src_coderbyte ${libro_src_coderbyte_cpp})

# The target_include_directories is used if you want that during target_link_libraries, it will have
# automatically those include directories added. So in case of fire caused by #include errors, do below.
# target_include_directories(libro_src_coderbyte PUBLIC ../your/included/directories/for/this/library)
