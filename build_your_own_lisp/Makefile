# --- Project Configuration ---

# Directories
BIN_DIR     = bin
INCLUDE_DIR = include
O_DIR       = obj
SRC_DIR     = src

# Files
C_FILES := $(wildcard $(SRC_DIR)/*.c)
O_FILES := $(patsubst $(SRC_DIR)/%.c,$(O_DIR)/%.o,$(C_FILES))
TARGET   = $(BIN_DIR)/lispy

# Compiler & Flags
CC      = gcc
CFLAGS  = -Wall -Wextra -std=c99 -g
LDFLAGS = -ledit -lm

# --- Targets ---

# Default target: builds the executable
all: $(TARGET)

# The final executable target: depends on all object files
$(TARGET): $(O_FILES)
	@mkdir -p $(BIN_DIR)
	$(CC) $(LDFLAGS) $(O_FILES) -o $@
	@echo "Build successful: $(TARGET)"

# Pattern rule for compilation: turns any .c file into a .o file
$(O_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(O_DIR)
	@echo "Compiling $< -> $@"
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# --- Cleanup Targets ---

.PHONY: all clean install

clean:
	rm -rf $(BIN_DIR) $(O_DIR)
	@echo "Cleaned up build files."
