# Keep this up to date with setup process in https://github.com/google/googletest
# Please see googletest/googletest README file

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
# if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include") # I have included this for the subdirectories to see
# endif()

# Set the variables that you need to pass to the subdirectories. The idea is to include all cpp files
# of all subdirectories so that we can run here all tests within this libro_test executable.
set(parent_libro_test_coderbyte_cpp "")

# Add the subdirectories. Each subdirectory will create their own executable. At the same time, they
# will be included also into this common libro_test executable because each subdirectory will modify
# their respective parent_libro_test_*_cpp variable with all their cpp files that will be later used
# during the creation of common libro_test executable here below.
add_subdirectory(CoderByte)

# Add the test cpp files from this directory
file(GLOB libro_test_cpp "*.cpp")

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(
    libro_test
    ${libro_test_cpp}
    ${parent_libro_test_coderbyte_cpp})
target_link_libraries(libro_test gtest_main)
add_test(NAME libro_test COMMAND libro_test)
