#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct LinkedList {
  struct Node *head;
  void (*insert)(struct LinkedList *list, int data, int position);
  void (*delete)(struct LinkedList *list, int position);
  void (*addFront)(struct LinkedList *list, int data);
  void (*addBack)(struct LinkedList *list, int data);
  void (*show)(struct LinkedList *list);
};

void insert(struct LinkedList *list, int data, int position) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (list->head == NULL) {
    list->head = newNode;
  } else {
    struct Node *temp = list->head;
    for (int i = 0; i < position - 1; i++) {
      temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
  }
}

void delete(struct LinkedList *list, int position) {
  struct Node *temp = list->head;
  for (int i = 0; i < position - 1; i++) {
    temp = temp->next;
  }
  struct Node *deletedNode = temp->next;
  temp->next = deletedNode->next;
  free(deletedNode);
}

void addFront(struct LinkedList *list, int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = list->head;
  list->head = newNode;
}

void addBack(struct LinkedList *list, int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (list->head == NULL) {
    list->head = newNode;
  } else {
    struct Node *temp = list->head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void show(struct LinkedList *list) {
  struct Node *temp = list->head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  struct LinkedList *list =
      (struct LinkedList *)malloc(sizeof(struct LinkedList));
  list->head = NULL;
  list->insert = insert;
  list->delete = delete;
  list->addFront = addFront;
  list->addBack = addBack;
  list->show = show;

  int data, position;
  int choice;
  while (1) {
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Add Front\n");
    printf("4. Add Back\n");
    printf("5. Show\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter data and position: ");
      scanf("%d %d", &data, &position);
      list->insert(list, data, position);
      break;
    case 2:
      printf("Enter position: ");
      scanf("%d", &position);
      list->delete (list, position);
      break;
    case 3:
      printf("Enter data: ");
      scanf("%d", &data);
      list->addFront(list, data);
      break;
    case 4:
      printf("Enter data: ");
      scanf("%d", &data);
      list->addBack(list, data);
      break;
    case 5:
      list->show(list);
      break;
    case 6:
      exit(0);
    default:
      printf("Invalid choice\n");
    }
  }

  return 0;
}
