# CGame
Some games I have written in C, and a small game engine for them.


## Compiling
To compile everything just do `make` or `make all`.  
To compile a specific game, do `make game_name`. For example `make template`.  

This will create executables in the `bin` directory for the compiled games.

To remove all the binaries, do `make clean`.


## Getting started
To create your own game here, copy the `Template` directory, and rename it to for example `MyGame`.
Now go inside the `Makefile` file, and add in a new rule like this:
```make
# Build MyGame.
MYGAME_SRC_FILES := $(shell find ./MyGame -name "*.c")
MYGAME_OBJ_FILES := $(patsubst %.c, ${OBJ_DIR}/%.o, ${MYGAME_SRC_FILES})
mygame: bin_dir engine ${TEMPLATE_OBJ_FILES}
	${LD} -o ${BIN_DIR}/template ${ENGINE_OBJ_FILES} ${MYGAME_OBJ_FILES} ${LDFLAGS}
```
Don't forget to replace the example name of the game (here it's `MyGame`) with your actual game name.  
Also, add the rule (in this case `mygame`) to the `all` and `.PHONY` rules.

Now you can work on your game inside the folder you created.


## Games
Here are the games that have been implemented here.

TODO: implement some games.
