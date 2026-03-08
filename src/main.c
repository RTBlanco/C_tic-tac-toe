#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int check_winner(int arr[3][3] ,int player);
void display_board(int arr[3][3], int player);
int postion_select(int arr[3][3], int player, int *turn);

int main() {
  int matrix[3][3] = {
    {0,0,0},
    {0,0,0},
    {0,0,0},
  };

  int player1 = 120, player2 =  111; 
  int filled = 0;
  int running = 0;
  int turn = 0;
  int *turn_ptr = &turn; 
  int *current_player = &player1;

  while(running == 0) {
    filled ++;
    
    display_board(matrix, *current_player);
    if(postion_select(matrix, *current_player, turn_ptr) == 0){
      display_board(matrix, *current_player);
      printf("Winner is PLAYER %c\n", *current_player);
      running = 1;
    } else if (filled == 9) {
      display_board(matrix, *current_player);
      printf("Tie Game !!\n");
      running = 1;
    }
    current_player = turn % 2 ? &player2 : &player1;
    
  }

  return 0;
}

int check_winner(int arr[3][3], int player) {
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
  printf("\033[H\033[J");
  printf("\n\n");
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
  printf(" PLAYER %c ", player);
  printf("=====");
  printf("=====\n");
}


int postion_select(int arr[3][3], int player, int *turn) {

  char user_input[4]; 
  int first_index;
  int second_index;

  printf("Enter Select (NUM LETTER): ");
  fgets(user_input, sizeof(user_input), stdin);

  first_index = (*user_input - '0') - 1;
  second_index = toupper(user_input[1]) - 65;

  if (arr[first_index][second_index] == 0) {
    arr[first_index][second_index] = player;
    (*turn) ++;
    return check_winner(arr, player) ;
  }


  return 1;
}