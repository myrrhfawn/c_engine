# name of the executable
TARGET = bin/c_engine

# Directories with source code and headers
SRC_DIR = src
INC_DIR = include

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -I$(INC_DIR) -lncurses

# Search for all source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:.cpp=.o)

# compile all files
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# compile one file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean the project
clean:
	rm -f $(TARGET) $(OBJS)
