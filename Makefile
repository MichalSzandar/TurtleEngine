# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude -Iinclude/imgui -Iinclude/imgui-sfml

# Directories
SRC_DIR = src
BIN_DIR = bin
BUILD_DIR = build
TEST_DIR = tests
INCLUDE_DIR = include
LIB_DIR = lib

# SFML and OpenGL Libraries
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lGL -lGLU

# Source files
SRCS = $(wildcard $(SRC_DIR)/**/*.cpp) $(wildcard $(SRC_DIR)/*.cpp) \
       include/imgui/imgui.cpp include/imgui/imgui_draw.cpp include/imgui/imgui_tables.cpp include/imgui/imgui_widgets.cpp \
       include/imgui-sfml/imgui-SFML.cpp include/ImGuiFileDialog-0.6.6.1/ImGuiFileDialog.cpp
OBJS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SRCS))
TARGET = $(BIN_DIR)/SFML_Game

# Build rules
all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR) $(BUILD_DIR):
	mkdir -p $@

clean:
	rm -rf $(BIN_DIR) $(BUILD_DIR)

.PHONY: all clean
