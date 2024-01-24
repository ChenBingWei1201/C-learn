#include <stdio.h>

int main() {
  
  // Create an int and a char variable
  int myNum;
  char myChar;

  // Ask the user to type a number AND a character
  printf("Type a number AND a character and press enter: \n");

  // Get and save the number AND character the user types
  scanf("%d %c", &myNum, &myChar);

  // Print the number
  printf("Your number is: %d\n", myNum);

  // Print the character
  printf("Your character is: %c\n", myChar);

  /*
    If you want to print a string without spaces, you can use scanf()
    scanf() is used to read a string from a file
    It reads until a whitespace character is found (which is entered when you press enter)
  */
  // Create a string
  char firstName[30];

  // Ask the user to input some text
  printf("Enter your first name: \n");

  // Get and save the text
  scanf("%s", firstName);

  // Output the text
  printf("Hello %s", firstName);

  /* 
    If you want to print a string with spaces, you need to use fgets() instead of scanf()
    fgets() is used to read a string from a file
    It reads until a newline character is found (which is entered when you press enter)
    It stores the string in the first parameter
    It stops reading when it reaches the second parameter
    stdin is the standard input (the keyboard)
  */
  char fullName[30];

  printf("Type your full name: \n");
  fgets(fullName, sizeof(fullName), stdin);

  printf("Hello %s", fullName);
  printf("%p", fullName); // Print the memory address of the variable 
}

