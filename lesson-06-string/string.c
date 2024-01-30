#include <stdio.h>
#include <string.h>

int main() {
  /*char str[] = "Hello World!";
  printf("sizeof(str) = %ld\n", sizeof(str));

  for (int i = 0; i < 12; i++)
    printf("%c\n", str[i]);
  */
  /*char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
  printf("lenght: %ld\n", strlen(alphabet));
  printf("size: %ld", sizeof(alphabet));*/

  char str1[20] = "Hello ";
  char str2[] = "World!";

  // Concatenate str2 to str1 (the result is stored in str1)
  strcat(str1, str2);

  // Print str1
  printf("%s\n", str1);
  printf("%ld", sizeof(str1));
  return 0;
}
