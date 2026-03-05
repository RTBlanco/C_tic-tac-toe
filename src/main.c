#include <stdlib.h>
#include <stdio.h>

int check_winner(int player, int arr[3][3]);
void display_board(int arr[3][3], int player);
void postion_select(int arr[3][3], int player);

int main() {
  int matrix[3][3] = {
    {1,0,0},
    {0,0,0},
    {0,0,0},
  };

  int player1 = 1, player2 =  2;

  int winner = 0;
  while(winner == 0) {
    display_board(matrix, player1);
    postion_select(matrix, player1);

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
  system("clear");

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
      printf("%s%c", i + 1 == 3 ? "   " : "___" ,x + 1 == 3 ? '\0' : '|');

    }
    printf("\n");
  }


  printf("=====");
  printf("=====");
  printf("PLAYER %d", player);
  printf("=====");
  printf("=====\n");
}

void postion_select(int arr[3][3], int player) {

  char user_input[3]; 
  int first_index;
  int second_index;

  printf("Enter Select (NUM LETTER): ");
  fgets(user_input, 3, stdin);

  first_index = *user_input - '0';
  second_index = user_input[1] - 65;

  printf("first: %lu \nsecond: %lu \n",first_index, second_index);

  arr[first_index][second_index] = player;
  // i need to convert something like string 1a to int 0 0 
  // using ascii i guess i can narrow down their number value
}