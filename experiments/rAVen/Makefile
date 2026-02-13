# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic `pkg-config --cflags gtk+-3.0 libavformat libavcodec libavutil`
INCLUDES = -I../raylib/build/raylib/include
LIBS = `pkg-config --libs gtk+-3.0 libavformat libavcodec libavutil` -lraylib -lglfw -lm -ldl -lpthread -lmagic

# Target executable
TARGET = raven
SRC = main.c

# Build target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(INCLUDES) $(CFLAGS)  -o $(TARGET) $(SRC) $(LIBS)

# Clean up build files
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean
