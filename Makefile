# Variables
BUILD_DIRECTORY = build
INCLUDE_DIR1 = .
INCLUDE_DIR2 = src

# Artificial targets
.PHONY : all clean buildDirectory

# Primary rule
all : buildDirectory $(BUILD_DIRECTORY)/a.out

# Setup build directory
buildDirectory : $(BUILD_DIRECTORY)

$(BUILD_DIRECTORY) :
	mkdir -p $(BUILD_DIRECTORY)

# Setup target executable
$(BUILD_DIRECTORY)/a.out : $(BUILD_DIRECTORY)/main.o $(BUILD_DIRECTORY)/dispatcher.o
	g++ $^ -o $@

# Setup object files
$(BUILD_DIRECTORY)/main.o : src/main.cpp
	g++ -I$(INCLUDE_DIR1) -I$(INCLUDE_DIR2) -c $< -o $@

$(BUILD_DIRECTORY)/dispatcher.o : src/Dispatcher.cpp src/Dispatcher.hpp
	g++ -I$(INCLUDE_DIR1) -I$(INCLUDE_DIR2) -c $< -o $@

# Clean rule
clean :
	rm -rf $(BUILD_DIRECTORY)
