file(GLOB libro_src_challenges_cpp
    "*.cpp"
    "CoderByte/*.cpp"
    "CoderByte/EasyDifficulty/*.cpp"
    "CoderByte/HardDifficulty/*.cpp"
    "CoderByte/MediumDifficulty/*.cpp"
    "ProjectEuler/*.cpp"
    "Self/*.cpp")

# Do not overthink about the .. in <include_directories(..)>, it is just the parent directory.
# This command is not needed anymore as ../CMakeLists.txt already included this.
# include_directories(..)

# This add_library can be instructed to either create static .a library or shared .so library. But
# since the size of executable nor the platform dependency is not a big issue for the purpose of this
# project, then I would choose to make it simple by letting it be the default value, which is currrrently
# as static .a library.
add_library(libro_src_challenges ${libro_src_challenges_cpp})

# The next command recompiles the src codes but now with the additional defined macro flag DONT_PRINT_TO_SCREEN.
# This library should be the one linked to the tests! Why? Because linking tests against the library
# without this defined macro flag would result to printing everything that the src code processes into
# the screen while being invoked by the tests which is not necessary when testing. Search the src code
# for more info about handling this macro flag DONT_PRINT_TO_SCREEN.
add_library(libro_src_challenges_FOR_TESTING ${libro_src_challenges_cpp})
target_compile_definitions(libro_src_challenges_FOR_TESTING PUBLIC DONT_PRINT_TO_SCREEN)

# The target_include_directories is used if you want that during target_link_libraries, it will have
# automatically those include directories added. So in case of fire caused by #include errors, do below.
# target_include_directories(libro_src_challenges PUBLIC ../your/included/directories/for/this/library)
