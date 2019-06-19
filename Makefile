BUILD_DIRECTORY = build

.PHONY : all clean buildDirectory

all : buildDirectory $(BUILD_DIRECTORY)/a.out

buildDirectory : $(BUILD_DIRECTORY)

$(BUILD_DIRECTORY) :
	mkdir -p $(BUILD_DIRECTORY)

$(BUILD_DIRECTORY)/a.out : $(BUILD_DIRECTORY)/main.o
	g++ $^ -o $@

$(BUILD_DIRECTORY)/main.o : src/main.cpp
	g++ -c $< -o $@

clean :
	rm -rf $(BUILD_DIRECTORY)
