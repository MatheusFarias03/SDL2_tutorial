# Compiler
CXX := g++
# Compiler flags
CXXFLAGS := -std=c++11 -Wall -Wextra

# Directories
SRC_DIR := src
INCLUDE_DIR := include
BUILD_DIR := build
BIN_DIR := $(BUILD_DIR)/bin

# Files
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))
INCLUDE_FILES := $(wildcard $(INCLUDE_DIR)/*.hpp)
BIN := $(BIN_DIR)/sdl2_tutorial.run

# Default target
all: $(BIN)

# Build target
$(BIN): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ -lSDL2

# Object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
