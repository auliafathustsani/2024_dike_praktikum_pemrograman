# Variables
CXX = g++         # The C++ compiler
CXXFLAGS = -Wall  # Compiler flags: -Wall enables all warnings
TARGET = fibonacci  # The output program name
SRC = fibonacci.cpp  # The source file

# Default target to compile the program
all: $(TARGET)

# Rule to compile the source file
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Rule to run the program
run: $(TARGET)
	./$(TARGET)

# Rule to clean up the compiled files
clean:
	rm -f $(TARGET)

# Phony targets to avoid conflicts with files named "all", "run", or "clean"
.PHONY: all run clean
