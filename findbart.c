#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  // Seed the random selection to be random by getting current time. NULL looks
  // scary but it means it doesn't need to be save other than to the seed.
  srand((unsigned int)time(NULL));
  // first, let's create an array with our wounsigned int)time(NULL));))ray
  // where each row is an array of charactyers(up to 8)
  char world_names[3][8] = {"Machina", "Sirocco", "Gloam"};
  printf("Bart the mischievous cat has stolen our spaceship and crashed into "
         "one of the planets in our star system. We have to find him! Where "
         "will you land to help Bart?\n");
  // Loop over 3 times to select the row based on i(+1 to offest), then %s by
  // how it's programmed will loop and display the characters in the column of i
  for (int i = 0; i < 3; i++) {
    printf("Choice %d: %s\n", i + 1, world_names[i]);
  }
  // Here, I am getting the character typed by the user, which will be a number
  // but in character form. Then using -'0' will convert the character to a
  // number, and assign it to player_choice, unicode decoding.
  int typed_character = getchar();
  int player_choice = typed_character - '0';
  // Protection from out of bounds choices
  if (player_choice < 1 || player_choice > 3) {
    printf(
        "Please select a world between 1 and 3. The program will now exit\n");
    return 1;
  }
  // I have to reduce the selected index by 1 because the array starts at 0
  int selected_index = player_choice - 1;
  printf("You search %s\n", world_names[selected_index]);
  // Bart is chosen at random betyween 0,1,2
  int bart_index = rand() % 3;
  // Checking to see if user selection marches the location of Bart.
  if (selected_index == bart_index) {
    printf("Bart is here. He is sorry for stealing our stuff, he just wanted a "
           "licky stick and pats!\n");
  } else {
    printf(
        "Bart is not here, you lost the cat and he doesn't love you anymore\n");
  }
  printf("The search is over\n");
  return 0;
}
