#include <stdio.h>

int main() {
  // A pointer is a variable that stores the memory address of another variable as its value.
  int a = 10;
  int *p = &a;

  printf("The value of a is %d\n", a);
  printf("The address of a is %p\n", &a);
  printf("The address of a is %p\n", p);
  // dereference:
  printf("The value of a is %d\n", *p);
  
  // Array
  int myNumbers[4] = {25, 50, 75, 100};

  // Get the memory address of the myNumbers array
  printf("%p\n", myNumbers);

  // Get the memory address of the first array element
  printf("%p\n", &myNumbers[0]);

  int *ptr = myNumbers;
  for (int i = 0; i < 4; i++) {
    printf("%d\n", *(ptr + i));
  }

  return 0;
}
