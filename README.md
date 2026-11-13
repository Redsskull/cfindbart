# Find Bart

A small game about my cat stealing a spaceship, built in C while I learn the
language. I'm sharing the work as it grows, including the rough edges.

Run from this directory so the game can find `data/worlds.json`. During the
current file-loading experiment, it prints that document before starting the
game. It collects up to 8,191 bytes of text and rejects larger files. JSON
parsing is not implemented yet: gameplay still uses the built-in world text.

Read a clue, choose between a robot megacity, a desert world, and a spooky world,
then search for Bart. The terminal version has world descriptions, search scenes,
and replay. The longer-term goal is a small graphical game.

## Build and play

You need a C compiler such as GCC. From this directory:

```sh
gcc -std=c17 -Wall -Wextra -Wpedantic findbart.c -o findbart
./findbart
```

Enter `1`, `2`, or `3` to choose a world. After the result, enter `y` or `Y`
to play again, or another answer to quit.

## Work in progress

One guess per round, deliberately simple clues, and no graphics yet. Very long
replay answers can spill into the next round; end-of-input currently exits as
an error. These are known limitations, not finished behaviour.
