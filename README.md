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

Enter `1`, `2`, or `3` to choose a world. After the result, enter `y` or `Y`
to play again, or another answer to quit.
The compiled executable is not tracked in Git.

## Current version and limitations

- One guess per round, with in-program replay. No graphics yet.
- Bart's location is selected with `rand() % 3`, seeded once using the current
  time. This is suitable for a casual game, not security-sensitive randomness.
- Launches in the same second use the same seed. Different seeds can still
  select the same planet.
- Planet input requires exactly `1`, `2`, or `3` followed by Enter; invalid
  answers are rejected and retried.
- Replay checks only the first character, so answers beginning with `y` or `Y`
  replay. Very long replay answers can leave input for the next round.
- End-of-input currently exits with a failure status, even for a normal EOF.

The longer-term idea is a graphical game with three clickable planets, a
result, and a Play Again button. The terminal logic is being developed first.
