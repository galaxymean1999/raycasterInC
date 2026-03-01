# Name of your final executable
TARGET = a

# Compiler
CC = gcc

# Compiler flags: 
# -Wall (show all warnings) 
# -std=c99 (use C99 standard)
CFLAGS = -Wall -std=c99 -Wno-missing-braces

# Search paths for headers and libraries (where we installed raylib)
INCLUDES = -I/usr/local/include
LDFLAGS = -L/usr/local/lib

# Libraries to link against
# Order matters: -lraylib must come before the system libs
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Source files
SRC = main.c ray.c ray.h

# Default rule: This runs when you just type 'make'
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS) $(INCLUDES) $(LDFLAGS) $(LIBS)

# Clean rule: Removes the compiled file so you can start fresh
clean:
	rm -f $(TARGET)