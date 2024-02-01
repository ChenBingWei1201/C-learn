#include <stdio.h>
#include <string.h>

struct student {
  char name[20];
  int age;
  int score;
};

int main() {
  struct student st = {"zhangsan", 20, 90};
  printf("name = %s, age = %d, score = %d\n", st.name, st.age, st.score);
  strcpy(st.name, "lisi");
  st.age = 30;
  st.score = 100;
  printf("name = %s, age = %d, score = %d\n", st.name, st.age, st.score);
  return 0;
}

