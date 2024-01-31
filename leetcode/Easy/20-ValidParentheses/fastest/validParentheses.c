#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char *s) {
  long int l;
  char *stack, c;
  int sp = 0;

  if (!s || !*s)
    return true;

  l = strlen(s);
  stack = malloc(l * sizeof(char));

  while ((c = *s++)) {
    switch (c) {
    case '(':
    case '{':
    case '[':
      stack[sp++] = c;
      break;
    case ')':
      if (sp == 0 || stack[--sp] != '(') {
        free(stack);
        return false;
      }
      break;
    case '}':
      if (sp == 0 || stack[--sp] != '{') {
        free(stack);
        return false;
      }
      break;
    case ']':
      if (sp == 0 || stack[--sp] != '[') {
        free(stack);
        return false;
      }
      break;
    default:
      break;
    }
  }

  free(stack);
  return sp == 0 ? true : false;
}

int main() {
  char *s = "[([]])";
  printf("%d\n", isValid(s));
  return 0;
}
