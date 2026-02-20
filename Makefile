TARGET = src/build/device.a

CC = clang

CC_FLAGS = -std=c89 -O2 -pedantic -Wall -Wextra -Werror

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, src/build/obj/%.o, $(SRC))

.PHONY: all clean

all: $(TARGET)

src/build/obj/%.o: src/%.c
	@echo "CC: $@"
	@mkdir -p $(dir $@)
	@$(CC) -c $(CC_FLAGS) $< -o $@

$(TARGET): $(OBJ)
	@echo "LD: $@"
	@mkdir -p $(dir $@)
	@ar rcs $@ $^

clean:
	@rm -rf src/build
