#include <stdio.h>
#include <stdlib.h>

// Define the structure of the stack
struct Stack {
  int *items;
  int top;
  int capacity;
  void (*push)(struct Stack *, int);
  int (*pop)(struct Stack *);
  void (*setSized)(struct Stack *, int);
};

// Function prototypes
void push(struct Stack *stack, int value);
int pop(struct Stack *stack);
void setSized(struct Stack *stack, int size);

// Function to push an element onto the stack
void push(struct Stack *stack, int value) {
  if (stack->top == stack->capacity - 1) {
    // Stack is full, need to resize
    stack->capacity *= 2;
    stack->items = realloc(stack->items, stack->capacity * sizeof(int));
  }
  stack->items[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
  if (stack->top == -1) {
    printf("Stack underflow\n");
    return -1;
  }
  return stack->items[stack->top--];
}

// Function to set the size of the stack
void setSized(struct Stack *stack, int size) {
  stack->capacity = size;
  // if (stack->items) {
  //   free(stack->items);
  // }
  stack->items = (int *)malloc(stack->capacity * sizeof(int));
  if (stack->items == NULL) {
    printf("Memory allocation failed\n");
    exit(1);
  }
}

int main() {
  // Create a stack instance
  struct Stack stack;
  stack.top = -1;
  stack.push = push;
  stack.pop = pop;
  stack.setSized = setSized;

  int size;
  printf("Enter the size of the stack: ");
  scanf("%d", &size);

  // Set the size of the stack
  stack.setSized(&stack, size); // Set the size

  int element;
  printf("Enter elements to push onto the stack (separate by spaces):\n");
  for (int i = 0; i < size; i++) {
    scanf("%d", &element);
    stack.push(&stack, element);
  }

  // Pop elements from the stack and print them
  printf("Popped elements from the stack:\n");
  while (stack.top != -1) {
    printf("%d\n", stack.pop(&stack));
  }

  free(stack.items); // Free dynamically allocated memory

  return 0;
}
