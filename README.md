# CGame
Some games I have written in C, and a small game engine for them.


## Compiling
To compile everything just do `make` or `make all`.  
To compile a specific game, do `make game_name`. For example `make template`.  

This will create executables in the `bin` directory for the compiled games.

To remove all the binaries, do `make clean`.


## Getting started
To create your own game here, go into the `src` directory. Now copy the `template.c` file and call it something like `my_game.c`.

Now you have created an entry point for your game, to be able to build it, go back into the root of the repository, and open up
`Makefile`. In there you can copy the rule `template`, and call it something like `my_game`. Make sure to go through the rule,
and replace any mention to things like `template` and `template.o` is replaced with `my_game` and `my_game.o`.

Also, don't forget to add your new rule to `all` and `.PHONY`.


## Games
Here are the games that have been implemented here.

TODO: implement some games.
