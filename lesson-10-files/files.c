#include <stdio.h>

int main() {
  FILE *fptr;
  /*fptr = fopen("files.txt", "a");

  fprintf(fptr, "\nHello World\n");

  fclose(fptr);*/
  
  fptr = fopen("files.txt", "r"); 
  if(fptr == NULL)
    printf("Not able to open the file.");
  char txt[100];
  while(fgets(txt, 100, fptr))
    printf("%s", txt);
  fclose(fptr); 
}
