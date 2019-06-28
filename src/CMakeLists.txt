cmake_minimum_required(VERSION 3.10.2)
project(libro_src)

# CMAKE_CURRENT_SOURCE_DIR is just equivalent to the current directory . and just written explicitly
# here to be more descriptive than writing as <include_directories(.)>. The <include_directories(x)>
# will affect all targets in this CMakeList as well as those in all subdirectories added after the
# point of its call. So all subdirectories after this command will have the current directory . which
# is specifically ./LibroDeConocimiento/src added to their include path automatically.
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(CoderByte)
add_subdirectory(Help)

set(libro_src_cpp
    Dispatcher.cpp
    main.cpp)

add_executable(libro_src ${libro_src_cpp})

target_link_libraries(libro_src libro_src_coderbyte)
target_link_libraries(libro_src libro_src_help)
