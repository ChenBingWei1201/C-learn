#include <stdio.h>

int main() {
  int stack[10];
  int top = -1;
  int i;
  for (i = 0; i < 10; i++)
    stack[++top] = i;

  for (i = 0; i < 10; i++) {
    printf("%d\n", stack[top--]);
  }
  return 0;
}
