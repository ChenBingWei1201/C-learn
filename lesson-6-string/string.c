#include <stdio.h>

int main() {
  char str[] = "Hello World!";
  printf("sizeof(str) = %ld\n", sizeof(str));
  
  for (int i = 0; i < 12; i++)
    printf("%c\n", str[i]);   
}
