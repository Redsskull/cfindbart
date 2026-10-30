#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int get_world_choice(void);

int main(void) {
  // Seed the random selection to be random by getting current time. NULL looks
  // scary but it means it doesn't need to be save other than to the seed.
  srand((unsigned int)time(NULL));
  // first, let's create an array with our wounsigned int)time(NULL));))ray
  // where each row is an array of charactyers(up to 8)
  char world_names[3][8] = {"Machina", "Sirocco", "Gloam"};
  while (1) {
    printf("Bart the mischievous cat has stolen our spaceship and crashed into "
           "one of the planets in our star system. We have to find him! Where "
           "will you land to help Bart?\n");
    // Loop over 3 times to select the row based on i(+1 to offest), then %s by
    // how it's programmed will loop and display the characters in the column of
    // i
    for (int i = 0; i < 3; i++) {
      printf("Choice %d: %s\n", i + 1, world_names[i]);
    }

    int selected_index = get_world_choice();

    printf("You search %s\n", world_names[selected_index]);
    // Bart is chosen at random betyween 0,1,2
    int bart_index = rand() % 3;
    // Checking to see if user selection marches the location of Bart.
    if (selected_index == bart_index) {
      printf(
          "Bart is here. He is sorry for stealing our stuff, he just wanted a "
          "licky stick and pats!\n");
    } else {
      printf("Bart is not here, you lost the cat and he doesn't love you "
             "anymore\n");
    }
    printf("The search is over\n");
    // adding replay function
    char replay[16];
    printf("Would you like to play again? Enter y to replay, or anything else "
           "to quit: ");
    fflush(stdout);
    if (fgets(replay, sizeof replay, stdin) == NULL) {
      printf("Could not read input. The program will now exit.\n");
      exit(EXIT_FAILURE);
    }
    if (replay[0] != 'y' && replay[0] != 'Y') {
      printf("Bart will miss you. He looks up to you.\n");
      break;
    }
  }
  return 0;
}

int get_world_choice(void) {
  // Define the input char
  char input[16];
  while (1) {
    printf("Enter your choice: ");
    fflush(stdout);
    // Read input here; exit if fgets returns NULL.
    if (fgets(input, sizeof input, stdin) == NULL) {
      printf("Could not read input. The program will now exit.\n");
      exit(EXIT_FAILURE);
    }

    if (input[0] < '1' || input[0] > '3' || input[1] != '\n') {
      printf("Please enter exactly 1, 2, or 3.\n");
      if (strchr(input, '\n') == NULL) {
        int character = getchar();

        while (character != '\n' && character != EOF) {
          character = getchar();
        }
      }
      continue;
    }

    return input[0] - '0' - 1;
  }
}
