CC = gcc
CFLAGS = -Iinclude -Wall
BUILD_DIR = build
SRC_DIR = src
TARGET = $(BUILD_DIR)/cli_app

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/cli_app.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) -lcli

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

run: $(TARGET)
	./$(TARGET) greet --name Matheus
