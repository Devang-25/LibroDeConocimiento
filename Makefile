# Variables
BUILD_DIR = ./build
BIN_DIR = ./bin
SRC_INCLUDE_DIR = ./src

CC = g++
CFLAGS = -I$(SRC_INCLUDE_DIR) -Wall

CPP =  \
 $(wildcard src/*.cpp) \
 $(wildcard src/Help/*.cpp)
OBJ = $(CPP:%.cpp=$(BUILD_DIR)/%.o)
DEP = $(OBJ:%.o=%.d) # or can be as above : DEP = $(CPP:%.cpp=$(BUILD_DIR)/%.d)
TARGET = a.out

# Artificial targets
.PHONY : all clean

# Primary rule
all : $(BIN_DIR)/$(TARGET)

# Setup build and bin directories
# buildDirectory : $(BUILD_DIR)

# $(BUILD_DIR) :
# 	mkdir -p $(BUILD_DIR)

# binDirectory : $(BIN_DIR)

# $(BIN_DIR) :
# 	mkdir -p $(BIN_DIR)

# Setup target executable
$(BIN_DIR)/$(TARGET) : $(OBJ)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $^ -o $@

-include $(DEP)

# Setup object files
$(BUILD_DIR)/%.o : %.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

# Clean rule
clean :
	rm -rf $(BUILD_DIR)
	rm -rf $(BIN_DIR)
