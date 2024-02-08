#include <stdio.h>

struct GenericContainer {
  void *data;
};

int main() {
  // Define a generic container for integers
  struct GenericContainer container_int;
  int value = 42;
  container_int.data = &value;

  // Define a generic container for characters
  struct GenericContainer container_char;
  char character = 'A';
  container_char.data = &character;

  // Retrieve data from the containers
  int *ptr_int = (int *)container_int.data;
  printf("Value from container_int: %d\n", *ptr_int);

  char *ptr_char = (char *)container_char.data;
  printf("Value from container_char: %c\n", *ptr_char);

  return 0;
}
