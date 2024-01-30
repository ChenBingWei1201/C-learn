#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    } else {
        long int y = 0;
        long int z = x;
        while (z != 0) {
            y = y * 10 + z % 10;
            z = z / 10;
        }
        return x == y;
      }
}

int main() {
    int x;
    scanf("%d", &x);
    bool result = isPalindrome(x);
    printf("%d\n", result);
    return 0;
}
