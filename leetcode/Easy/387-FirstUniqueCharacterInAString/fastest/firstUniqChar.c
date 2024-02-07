#include <stdio.h>
#include <string.h>

int firstUniqChar(char *s) {
  int letter_counts[26] = {0};
  int n = strlen(s);

  for (int i = 0; i < n; ++i) {
    ++letter_counts[s[i] - 'a'];
  }

  for (int i = 0; i < n; ++i) {
    if (letter_counts[s[i] - 'a'] == 1) {
      return i;
    }
  }

  return -1;
}
int main() {
  char *s = "aabb";
  printf("%d\n", firstUniqChar(s));
  return 0;
}
