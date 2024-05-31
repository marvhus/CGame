CC := gcc
LD := gcc

CFLAGS := -std=c11 -pedantic \
		  -I./src \
		  -Wall -Werror \
		  -ggdb

LDFLAGS := -L./lib/raylib-5.0_linux_amd64/lib \
		   -l:libraylib.a -lm

BIN_DIR := bin
SRC_DIR := src

SRC_FILES := $(wildcard ${SRC_DIR}/*/*.c)
OBJ_FILES := $(patsubst ${SRC_DIR}/%.c, ${BIN_DIR}/obj/%.o, ${SRC_FILES})

.PHONY: all clean make_bin_dir template

# Compile everything.
all: template

# Clean up the bin directory.
clean:
	rm -rf ${BIN_DIR}

# Create the bin directory.
make_bin_dir:
	mkdir -p ${BIN_DIR}

# Build the template project.
template: make_bin_dir ${OBJ_FILES} ${BIN_DIR}/obj/template.o
	${LD} -o ${BIN_DIR}/template ${OBJ_FILES} ${BIN_DIR}/obj/template.o ${LDFLAGS}

# Compile the obj files.
$(BIN_DIR)/obj/%.o: ${SRC_DIR}/%.c | make_bin_dir
	mkdir -p $(dir $@)
	${CC} ${CFLAGS} -c -o $@ $<
