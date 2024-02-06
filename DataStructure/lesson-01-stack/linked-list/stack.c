#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

void push(int x);
void pop();
int top();
int empty();

int main() {
  push(2);
  printf("%d\n", top());
  push(3);
  printf("%d\n", top());
  push(4);
  printf("%d\n", top());
  pop();
  printf("%d\n", top());
  return 0;
}

struct node *head = NULL;

void push(int x) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = x;
  temp->next = head;
  head = temp;
}

void pop() {
  struct node *temp = head;
  head = head->next;
  free(temp);
}

int top() { return head->data; }

int empty() { return head == NULL; }
