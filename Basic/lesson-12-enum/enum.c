#include <stdio.h>

enum weekday {
  SUN, 
  MON,
  TUE, 
  WED, 
  THU,
  FRI, 
  SAT
};

int main()
{
  enum weekday today = THU;
  enum weekday tomorrow = FRI;

  printf("Today is %d\n", today);
  printf("Tomorrow is %d\n", tomorrow);
  return 0;
}

