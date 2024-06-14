#include <stdio.h>
#include <stdbool.h>

#define N 4


bool place(int board[N][N], int row, int col) {
  int i, j;
  for (i = 0; i < col; i++) {
    if (board[row][i]) {
      return false;
    }
  }
  for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j]) {
      return false;
    }
  }
  return true;
}

bool nQueen(int board[N][N], int col) {
  int i;
  if (col >= N) {
    return true;
  }
  for (i = 0; i < N; i++) {
    if (place(board, i, col)) {
      board[i][col] = 1;
      if (nQueen(board, col + 1)) {
        return true;
      }
      board[i][col] = 0;
    }
  }
  return false;
}

int main() {
  int board[N][N] = {0};
  if (!nQueen(board, 0)) {
    printf("Solution does not exist\n");
    return 0;
  }
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
  return 0;
}
