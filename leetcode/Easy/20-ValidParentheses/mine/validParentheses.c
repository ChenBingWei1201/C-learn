#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  char val;
  struct Node *next;
};

void push(struct Node **head, char val) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->val = val;
  newNode->next = *head;
  *head = newNode;
}

char pop(struct Node **head) {
  if (*head == NULL) {
    return '\0';
  }
  struct Node *temp = *head;
  char val = temp->val;
  *head = temp->next;
  free(temp);
  return val;
}

bool isValid(char *s) {
  struct Node *head = NULL;
  for (; *s != '\0'; s++) {
    if (*s == '(' || *s == '[' || *s == '{') {
      printf("%ld\n", sizeof(s));
      push(&head, *s);
    } else {
      char val = pop(&head);
      if ((*s == ')' && val != '(') || (*s == ']' && val != '[') ||
          (*s == '}' && val != '{')) {
        return false;
      }
    }
  }
  return head == NULL;
}

int main() {
  char *s = "[([]])";
  printf("%d\n", isValid(s));
  return 0;
}
