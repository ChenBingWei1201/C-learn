#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longestCommonPrefix(char **strs, int strsSize) {
  if (strsSize == 0) {
    return "";
  }
  int len = strlen(strs[0]);
  for (int i = 1; i < strsSize; i++) {
    int j = 0;
    for (; j < len && j < strlen(strs[i]); j++) {
      if (strs[0][j] != strs[i][j]) {
        break;
      }
    }
    len = j;
  }

  char *result = (char *)malloc((len + 1) * sizeof(char)); // Allocate memory
  if (result == NULL) {
    printf("Memory allocation failed\n");
    exit(1);
  }
  strncpy(result, strs[0], len); // Copy characters
  result[len] = '\0';            // Null-terminate the string
  return result;
}

int main() {
  char *strs[] = {"flower", "flow", "flight"};
  int strsSize = 3;
  char *result = longestCommonPrefix(strs, strsSize);
  printf("%s\n", result);
  free(result);
  return 0;
}
