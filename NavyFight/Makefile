
CC = gcc
CFLAGS = -Iinclude -Icli-lib/include -Wall
SOURCES = src/main.c src/game.c cli-lib/src/keyboard.c cli-lib/src/screen.c cli-lib/src/timer.c
TARGET = build/batalha-naval

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)
