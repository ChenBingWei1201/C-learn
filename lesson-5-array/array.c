#include <stdio.h>

int main() {
  int a[5] = {1, 2, 3, 4, 5};
  for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
    printf("%d\n", a[i]);
  }

  int b[2][3] = {{1, 2, 3}, {4, 5, 6}};
  int row = sizeof(b)/sizeof(b[0]);
  int col = sizeof(b[0])/sizeof(b[0][0]);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      printf("%d ", b[i][j]);
    }
    printf("\n");
  }
  return 0;
}
