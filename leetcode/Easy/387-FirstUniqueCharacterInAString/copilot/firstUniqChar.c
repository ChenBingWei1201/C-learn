#include <stdio.h>
#include <string.h>

int firstUniqChar(char *s) {
  int i, j;
  int len = strlen(s);
  for (i = 0; i < len; i++) {
    for (j = 0; j < len; j++) {
      if (i != j && s[i] == s[j]) {
        break;
      }
    }
    if (j == len) {
      return i;
    }
  }
  return -1;
}

int main() {
  char *s = "loveleetcode";
  printf("%d\n", firstUniqChar(s));
  return 0;
}
