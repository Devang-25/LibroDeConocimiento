# This CMake tool was made to work with commit 25d4ffc0b578e9513fe9f54301623e2ad4d0a717

# Although it worked, this will still be not used for this project to avoid unneccessary complexity
# of the build system, and thus, this will not be maintained.

# In case there is a need to use CMake for this project in the future, just do the following:
# Step 1: rm Makefile # this is the current manually maintained Makefile which we are going replace soon with the CMake generated one
# Step 2: rm .CMakeLists_generated_Makefile # this is the Makefile produced with commit 25d4ffc0b5 that is here just for reading reference
# Step 3: mv .CMakeLists.txt CMakeLists.txt # to enable this txt file which is currently hidden
# Step 4: vim CMakeLists.txt # update this file to support the latest changes
# Step 5: cmake . # to configure cmake in this repository
# Step 6: make # to build the repository
# Step 7: make # and whenever any source file or this CMakeLists.txt is changed, just do <make>, no need of reinvoking <cmake .>

cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES
    ./src/Dispatcher.cpp
    ./src/main.cpp
    ./src/CoderByte/Challenges/EasyDifficulty/FirstFactorial.cpp
    ./src/CoderByte/Challenges/EasyDifficulty/LongestWord.cpp
    ./src/CoderByte/Challenges/EasyDifficulty/SimpleAdding.cpp
    ./src/CoderByte/Challenges/EasyDifficulty/LetterChanges.cpp
    ./src/CoderByte/Challenges/EasyDifficulty/FirstReverse.cpp
    ./src/CoderByte/Challenges/ChallengesGetter.cpp
    ./src/CoderByte/CoderByteController.cpp
    ./src/Help/HelpController.cpp)

add_compile_options(-I. -I./src) # or use set # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I. -I./src")

project(libro)

add_executable(libro ${SOURCE_FILES})
