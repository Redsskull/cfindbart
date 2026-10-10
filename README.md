# Find Bart

A small terminal guessing game written in C. Bart has stolen a spaceship and
crashed on one of three worlds: Machina, Sirocco, or Gloam. Choose a world and
find out whether you found him.

## Build and play

You need a C compiler such as GCC. From this directory:

```sh
gcc -std=c17 -Wall -Wextra -Wpedantic findbart.c -o findbart
./findbart
```

Enter `1`, `2`, or `3` to choose a world. Run the program again for another game.
The compiled executable is not tracked in Git.

## Current version and limitations

- One guess per launch; no in-program replay or graphics yet.
- Bart's location is selected with `rand() % 3`, seeded once using the current
  time. This is suitable for a casual game, not security-sensitive randomness.
- Launches in the same second use the same seed. Different seeds can still
  select the same planet.
- Input reads a single character, not a complete validated line. For example,
  input beginning with `1` is treated as choice 1 even if more characters follow.

The longer-term idea is a graphical game with three clickable planets, a
result, and a Play Again button. The terminal logic is being developed first.
