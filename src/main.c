#include <stdlib.h>
#include <stdio.h>

int check_winner(int player, int arr[3][3]);
void display_board(int arr[3][3], int player);
void postion_select(int arr[3][3], int player, int *winner_ptr);

int main() {
  int matrix[3][3] = {
    {120,111,0},
    {0,0,0},
    {0,0,111},
  };

  int player1 = 120, player2 =  111;

  int winner = 0;
  int *winner_ptr = &winner; 

  while(winner == 0) {
    // system("clear");
    printf("\033[H\033[J");
    printf("\n\n");
    display_board(matrix, player1);
    postion_select(matrix, player1, winner_ptr);
  }

  // display_board(matrix, player1);  
  return 0;
}

int check_winner(int player, int arr[3][3]) {
  for (int i = 0; i < 3; i++ ) {
    if (arr[i][0] == player && arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]) {
      return 0;
    }

    if (arr[0][i] == player && arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]) {
      return 0;
    }
  }

  if (arr[0][0] == player && arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) {
    return 0;
  }

  if (arr[0][2] == player && arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) {
    return 0;
  }

  return 1;
}

void display_board(int arr[3][3], int player) {
  printf("====");
  printf("====");
  printf("TIC TAC TOE");
  printf("====");
  printf("====\n");
  for (int i = 0; i < 27; i ++ ) { printf("="); }
  printf("\n");


  
  printf("         A   B   C\n");
  for (int i = 0; i < 3; i ++) {
    printf("  %d     ", i + 1);
    for (int x = 0; x < 3 ; x ++) {
      char slot[4];
      if (arr[i][x] != 0) {
        snprintf(slot, sizeof(slot), i == 2 ? " %c " : "_%c_", arr[i][x]);
      } else {
        strcpy(slot, i == 2 ? "   " : "___");
      }

      printf("%s", slot);
      if (x < 2) {
        printf("|");
      }

    }
    printf("\n");
  }


  printf("=====");
  printf("=====");
  printf("PLAYER %d", player);
  printf("=====");
  printf("=====\n");
}

void postion_select(int arr[3][3], int player, int *winner_ptr) {

  char user_input[3]; 
  int first_index;
  int second_index;

  printf("Enter Select (NUM LETTER): ");
  fgets(user_input, 3, stdin);

  first_index = (*user_input - '0') - 1;
  second_index = user_input[1] - 65;

  printf("first: %d \nsecond: %d \n",first_index, second_index);

  arr[first_index][second_index] = player;

  // testing to see if game loops closes
  if (first_index == 0) {
    *winner_ptr = 1;
  }
  // i need to convert something like string 1a to int 0 0 
  // using ascii i guess i can narrow down their number value
}