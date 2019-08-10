# Variables
BUILD_DIRECTORY = ./build
SRC_DIR = src

CC = g++
CFLAGS = -I$(SRC_DIR) -std=c++17 -g -Wall -Wextra -Werror -pedantic

# Artificial targets
.PHONY : all clean buildDirectory

# Primary rule
all : buildDirectory $(BUILD_DIRECTORY)/a.out

# Setup build directory
buildDirectory : $(BUILD_DIRECTORY)

$(BUILD_DIRECTORY) :
	mkdir -p $(BUILD_DIRECTORY)

# Setup target executable
$(BUILD_DIRECTORY)/a.out : $(BUILD_DIRECTORY)/main.o \
							$(BUILD_DIRECTORY)/FileHandler.o \
							$(BUILD_DIRECTORY)/MagicSquareFinder.o \
							$(BUILD_DIRECTORY)/MatrixOutputter.o
	$(CC) $(CFLAGS) $^ -o $@

# Setup object files
$(BUILD_DIRECTORY)/main.o : src/main.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIRECTORY)/FileHandler.o : src/FileHandler.cpp src/FileHandler.hpp
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIRECTORY)/MagicSquareFinder.o : src/MagicSquareFinder.cpp src/MagicSquareFinder.hpp
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIRECTORY)/MatrixOutputter.o : src/MatrixOutputter.cpp src/MatrixOutputter.hpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean :
	rm -rf $(BUILD_DIRECTORY)
