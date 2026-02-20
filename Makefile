TARGET = src/build/libdevice.a

TEST = src/build/test

CC = clang

CC_FLAGS = -std=c89 -O2 -pedantic -Wall -Wextra -Werror

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, src/build/obj/%.o, $(SRC))

.PHONY: all clean

all: $(TARGET) $(TEST)

src/build/obj/%.o: src/%.c
	@echo "CC: $@"
	@mkdir -p $(dir $@)
	@$(CC) -c $(CC_FLAGS) $< -o $@

$(TARGET): $(OBJ)
	@echo "LD: $@"
	@mkdir -p $(dir $@)
	@ar rcs $@ $^

$(TEST) : src/test.c
	@echo "LD: $@"
	@mkdir -p $(dir $@)
	@$(CC) $(CC_FLAGS) $< -o $@ -L./src/build -ldevice

clean:
	@rm -rf src/build
