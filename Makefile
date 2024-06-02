CC := gcc
LD := gcc

CFLAGS := $(shell cat compile_flags.txt)

LDFLAGS := -L./thirdparty/Raylib \
		   -l:libraylib.a -lm

BIN_DIR := bin
OBJ_DIR := ${BIN_DIR}/obj

.PHONY: all clean bin_dir engine engine_lib template

# Compile everything.
all: template

# Clean up the bin directory.
clean:
	rm -rf ${BIN_DIR}




# Build the template project.
TEMPLATE_SRC_FILES := $(shell find ./Template -name "*.c")
TEMPLATE_OBJ_FILES := $(patsubst %.c, ${OBJ_DIR}/%.o, ${TEMPLATE_SRC_FILES})
template: bin_dir engine ${TEMPLATE_OBJ_FILES}
	${LD} -o ${BIN_DIR}/template ${ENGINE_OBJ_FILES} ${TEMPLATE_OBJ_FILES} ${LDFLAGS}



# Create the bin directory.
bin_dir:
	mkdir -p ${BIN_DIR}

# Compile the engine obj files
ENGINE_SRC_FILES := $(shell find ./CGame -name "*.c")
ENGINE_OBJ_FILES := $(patsubst %.c, ${OBJ_DIR}/%.o, ${ENGINE_SRC_FILES})
engine: bin_dir ${ENGINE_OBJ_FILES}

engine_lib: bin_dir ${ENGINE_OBJ_FILES}
	ar rcs ${BIN_DIR}/libcgame.a ${ENGINE_OBJ_FILES}

# Compile obj files.
${OBJ_DIR}/%.o: %.c | bin_dir
	@mkdir -p $(dir $@)
	${CC} ${CFLAGS} -c -o $@ $<
