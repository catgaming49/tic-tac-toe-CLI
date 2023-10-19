BIN_DIR := ./bin
BUILD_DIR := ./build
SRC_DIR := ./src
HEADER_DIR := ./include

.PHONY: all
all: $(BIN_DIR)/main

$(BUILD_DIR)/gameutils.o: $(SRC_DIR)/gameutils.c
	gcc -c $(SRC_DIR)/gameutils.c -o $(BUILD_DIR)/gameutils.o

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.c $(HEADER_DIR)/gameutils.h
	gcc -c $(SRC_DIR)/main.c -o $(BUILD_DIR)/main.o -I$(HEADER_DIR)

$(BIN_DIR)/main: $(BUILD_DIR)/main.o $(BUILD_DIR)/gameutils.o
	gcc $(BUILD_DIR)/main.o $(BUILD_DIR)/gameutils.o -o $(BIN_DIR)/main

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)/*.o
.PHONY rm: clean
	rm -r $(BIN_DIR)/*

