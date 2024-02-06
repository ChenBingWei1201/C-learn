#include <stdio.h>
#include <string.h>

struct student {
  char *name;
  int age;
  int score;
};

// use typedef to define a new type
typedef struct {
  char *name;
  int age;
} person;

int main() {
  struct student st = {"zhangsan", 20, 90};
  printf("name = %s, age = %d, score = %d\n", st.name, st.age, st.score);
  strcpy(st.name, "lisi");
  st.age = 30;
  st.score = 100;
  printf("name = %s, age = %d, score = %d\n", st.name, st.age, st.score);

  // don't need to use struct keyword
  person john;
  john.name = "John";
  john.age = 25;
  printf("name = %s, age = %d\n", john.name, john.age);
  return 0;
}
