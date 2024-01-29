#include <stdio.h>
#include <string.h>

int romanToInt(char* s) {
  int sum = 0;
  for (int i = 0; i < strlen(s); i++) {
    switch (s[i]) {
      case 'I':
        if (s[i + 1] == 'V' || s[i + 1] == 'X')
          sum -= 1;
        else
          sum += 1;
        break;
      case 'V':  
        sum += 5;
        break;
      case 'X':
        if (s[i + 1] == 'L' || s[i + 1] == 'C')
          sum -= 10;
        else
          sum += 10;
        break;
      case 'L':
        sum += 50;
        break;
      case 'C':
        if (s[i + 1] == 'D' || s[i + 1] == 'M')
          sum -= 100;
        else
          sum += 100;
        break;
      case 'D':
        sum += 500;
        break;
      case 'M':
        sum += 1000;
        break;
    }
  } 
  return sum;
}

int main() {
  char* s = "MCMXCIV";
  int result = romanToInt(s);
  printf("%d\n", result);
  return 0;
}
