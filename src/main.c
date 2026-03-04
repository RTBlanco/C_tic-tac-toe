#include <stdlib.h>
#include <stdio.h>

int check_winner(int player, int arr[3][3]);

int main() {
  int matrix[3][3] = {
    {0,0,0},
    {0,0,0},
    {0,0,0},
  };



  printf("Hello World\n");
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