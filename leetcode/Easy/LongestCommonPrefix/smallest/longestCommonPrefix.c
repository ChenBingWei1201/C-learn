#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longestCommonPrefix(char **strs, int strsSize) {
  if (strsSize == 0)
    return "";

  char *prefix = strdup(strs[0]); // Initialize the prefix with the first string

  for (int i = 1; i < strsSize; i++) {
    // While the current string doesn't start with the current prefix
    while (strncmp(strs[i], prefix, strlen(prefix)) != 0) {

      prefix[strlen(prefix) - 1] = '\0';
    }
  }

  return prefix; // Return the final common prefix
}
int main() {
  char *strs[] = {"flower", "flow", "flight"};
  int strsSize = 3;
  char *result = longestCommonPrefix(strs, strsSize);
  printf("%s\n", result);
  free(result);
  return 0;
}
