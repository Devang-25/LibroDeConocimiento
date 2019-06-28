# This manually written Makefile will not anymore be maintained. The project will now be using CMake
# for the automatic generation of Makefile.

# Variables
BUILD_DIR = ./build
BIN_DIR = ./bin
SRC_DIR = ./src

CPP =  \
 $(wildcard src/*.cpp) \
 $(wildcard src/CoderByte/*.cpp) \
 $(wildcard src/CoderByte/Challenges/*.cpp) \
 $(wildcard src/CoderByte/Challenges/EasyDifficulty/*.cpp) \
 $(wildcard src/Help/*.cpp)
OBJ = $(CPP:%.cpp=$(BUILD_DIR)/%.o)
DEP = $(OBJ:%.o=%.d)
TARGET = a.out

CC = g++
CFLAGS = -I$(SRC_DIR) -Wall

# Artificial targets
.PHONY : all clean

# Primary rule
all : $(BIN_DIR)/$(TARGET)

# Setup target executable
$(BIN_DIR)/$(TARGET) : $(OBJ)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $^ -o $@

# Setup object files
$(BUILD_DIR)/%.o : %.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

# Clean rule
clean :
	rm -rf $(BUILD_DIR)
	rm -rf $(BIN_DIR)

# include
-include $(DEP)
