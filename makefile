# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2 -lm

# Directories
SRC_DIR = .
BUILD_DIR = .

# Source file
SRC = $(SRC_DIR)/file_io.c

# Output executables
TARGET = $(BUILD_DIR)/file_io
STATIC_TARGET = $(BUILD_DIR)/ass1_static_linked

# Default target: Build both executables
all: $(TARGET) $(STATIC_TARGET)

# Build the main executable
$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS)

# Build the statically linked executable
$(STATIC_TARGET): $(SRC)
	$(CC) $(SRC) -o $(STATIC_TARGET) -static $(CFLAGS)

# Clean up generated files
clean:
	rm -f $(TARGET) $(STATIC_TARGET)

# Rebuild the project
rebuild: clean all

# Run the program
run: $(TARGET)
	./$(TARGET)

# Phony targets (not actual files)
.PHONY: all clean rebuild run

