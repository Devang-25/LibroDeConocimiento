file(GLOB libro_src_coderbyte_cpp
    "*.cpp"
    "Challenges/*.cpp"
    "Challenges/EasyDifficulty/*.cpp")

# Do not overthink about the .. in <include_directories(..)>, it is just the parent directory.
# This command is not needed anymore as ../CMakeLists.txt already included this.
# include_directories(..)

add_library(libro_src_coderbyte ${libro_src_coderbyte_cpp})

# In case of fire caused by #include errors...
# target_include_directories(libro_src_coderbyte PUBLIC ..)
