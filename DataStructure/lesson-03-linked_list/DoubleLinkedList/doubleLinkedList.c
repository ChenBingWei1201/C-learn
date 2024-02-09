#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
};

struct DoubleLinkedList {
  struct Node *head;
  struct Node *tail;
  void (*addFront)(struct DoubleLinkedList *self, int data);
  void (*addBack)(struct DoubleLinkedList *self, int data);
  void (*removeFront)(struct DoubleLinkedList *self);
  void (*removeBack)(struct DoubleLinkedList *self);
  void (*insert)(struct DoubleLinkedList *self, int data, int index);
  void (*removeAt)(struct DoubleLinkedList *self, int index);
};

void addFront(struct DoubleLinkedList *self, int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = self->head;
  newNode->prev = NULL;
  if (self->head != NULL) {
    self->head->prev = newNode;
  } else {
    self->tail = newNode;
  }
  self->head = newNode;
}

void addBack(struct DoubleLinkedList *self, int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = self->tail;
  if (self->tail != NULL) {
    self->tail->next = newNode;
  } else {
    self->head = newNode;
  }
  self->tail = newNode;
}

void removeFront(struct DoubleLinkedList *self) {
  if (self->head != NULL) {
    struct Node *temp = self->head;
    self->head = self->head->next;
    if (self->head != NULL) {
      self->head->prev = NULL;
    } else {
      self->tail = NULL;
    }
    free(temp);
  } else {
    printf("The list is empty! Please add new node!\n");
  }
}

void removeBack(struct DoubleLinkedList *self) {
  if (self->tail != NULL) {
    struct Node *temp = self->tail;
    self->tail = self->tail->prev;
    if (self->tail != NULL) {
      self->tail->next = NULL;
    } else {
      self->head = NULL;
    }
    free(temp);
  } else {
    printf("The list is empty! Please add new node!\n");
  }
}

void insert(struct DoubleLinkedList *self, int data, int index) {
  if (index == 0) {
    addFront(self, data);
  } else {
    struct Node *current = self->head;
    for (int i = 0; i < index - 1; i++) {
      if (current == NULL) {
        return;
      }
      current = current->next;
    }
    if (current == NULL) {
      addBack(self, data);
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next == NULL) {
      self->tail = newNode;
    } else {
      current->next->prev = newNode;
    }
    current->next = newNode;
  }
}

void removeAt(struct DoubleLinkedList *self, int index) {
  if (index == 0) {
    removeFront(self);
  } else {
    struct Node *current = self->head;
    for (int i = 0; i < index - 1; i++) {
      if (current == NULL) {
        return;
      }
      current = current->next;
    }
    if (current == NULL || current->next == NULL) {
      return;
    }
    struct Node *temp = current->next;
    current->next = temp->next;
    if (temp->next == NULL) {
      self->tail = current;
    } else {
      temp->next->prev = current;
    }
    free(temp);
  }
}

void printList(struct DoubleLinkedList *self) {
  struct Node *current = self->head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
  struct DoubleLinkedList *list =
      (struct DoubleLinkedList *)malloc(sizeof(struct DoubleLinkedList));
  list->head = NULL;
  list->tail = NULL;
  list->addFront = addFront;
  list->addBack = addBack;
  list->removeFront = removeFront;
  list->removeBack = removeBack;
  list->insert = insert;
  list->removeAt = removeAt;

  int data, position;
  int choice;
  while (1) {
    printf("1. Add Front\n");
    printf("2. Add Back\n");
    printf("3. Remove Front\n");
    printf("4. Remove Back\n");
    printf("5. Insert\n");
    printf("6. Remove At\n");
    printf("7. Print List\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter data: ");
      scanf("%d", &data);
      list->addFront(list, data);
      break;
    case 2:
      printf("Enter data: ");
      scanf("%d", &data);
      list->addBack(list, data);
      break;
    case 3:
      list->removeFront(list);
      break;
    case 4:
      list->removeBack(list);
      break;
    case 5:
      printf("Enter data: ");
      scanf("%d", &data);
      printf("Enter position: ");
      scanf("%d", &position);
      list->insert(list, data, position);
      break;
    case 6:
      printf("Enter position: ");
      scanf("%d", &position);
      list->removeAt(list, position);
      break;
    case 7:
      printList(list);
      break;
    case 8:
      free(list);
      return 0;
    default:
      printf("Invalid choice\n");
    }
  }
  return 0;
}
