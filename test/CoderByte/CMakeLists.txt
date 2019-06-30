# Get all cpp files and put to local variable libro_test_coderbyte_cpp
file(GLOB libro_test_coderbyte_cpp
    "Challenges/EasyDifficulty/*.cpp")

# Modify the parent variable parent_libro_test_coderbyte_cpp by adding the cpp files from here. The
# cpp files from here will be used to create the common executable that will run all tests.
set(parent_libro_test_coderbyte_cpp
    "${parent_libro_test_coderbyte_cpp}"
    "${libro_test_coderbyte_cpp}"
    PARENT_SCOPE)

# Create an executable sepcific for the tests in this subdirectory CoderByte. This will be a separate
# executable from the common one that will be created by the parent directory which will include all
# tests from all the subdirectories, including this CoderByte. If you would also notice, I used
# quotations "" within the argument libro_test_coderbyte_cpp below because if it is empty, then it is
# substituted with totally nothing thus the add_executable command compiles error due to lack of
# arguments. But actually, the quotations are not neccesary, just here for reference.
add_executable(libro_test_coderbyte "${libro_test_coderbyte_cpp}")

target_link_libraries(libro_test_coderbyte gtest_main)
target_link_libraries(libro_test_coderbyte libro_src_coderbyte_FOR_TESTING)
