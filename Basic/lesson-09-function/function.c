#include <stdio.h>

int sum(int k);
int sum_pointer(int *k);

int main() {
  int k = 10;
  int result_pointer = sum_pointer(&k);
  printf("%d\n", result_pointer);
  int result = sum(k);
  printf("%d\n", result);
  return 0;
}

int sum(int k) {
  if (k > 0) {
    return k + sum(k - 1);
  } else {
    return 0;
  }
}

int sum_pointer(int *k) {
  if (*k > 0) {
    return ++(*k); // will change the value of k
  } else {
    return 0;
  }
}
