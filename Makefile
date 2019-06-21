# Variables
BUILD_DIR = build
INCLUDE_DIR1 = .
INCLUDE_DIR2 = src

# Artificial targets
.PHONY : all clean buildDirectory

# Primary rule
all : buildDirectory $(BUILD_DIR)/a.out

# Setup build directory
buildDirectory : $(BUILD_DIR)

$(BUILD_DIR) :
	mkdir -p $(BUILD_DIR)

# Setup target executable
$(BUILD_DIR)/a.out : $(BUILD_DIR)/main.o $(BUILD_DIR)/Dispatcher.o $(BUILD_DIR)/HelpController.o
	g++ $^ -o $@

# Setup object files
$(BUILD_DIR)/main.o : src/main.cpp
	g++ -I$(INCLUDE_DIR1) -I$(INCLUDE_DIR2) -c $< -o $@

$(BUILD_DIR)/Dispatcher.o : src/Dispatcher.cpp src/Dispatcher.hpp
	g++ -I$(INCLUDE_DIR1) -I$(INCLUDE_DIR2) -c $< -o $@

$(BUILD_DIR)/HelpController.o : src/Help/HelpController.cpp src/Help/HelpController.hpp
	g++ -I$(INCLUDE_DIR1) -I$(INCLUDE_DIR2) -c $< -o $@

# Clean rule
clean :
	rm -rf $(BUILD_DIR)
