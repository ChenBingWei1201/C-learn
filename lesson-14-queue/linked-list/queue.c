#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Queue {
  struct Node *front;
  struct Node *rear;
};

struct Queue *createQueue() {
  struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
  q->front = q->rear = NULL;
  return q;
}

void enQueue(struct Queue *q, int data) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = data;
  temp->next = NULL;
  if (q->rear == NULL) {
    q->front = q->rear = temp;
    return;
  }
  q->rear->next = temp;
  q->rear = temp;
}

void deQueue(struct Queue *q) {
  if (q->front == NULL) {
    printf("\nQueue is empty");
    return;
  }
  struct Node *temp = q->front;
  q->front = q->front->next;
  if (q->front == NULL) {
    q->rear = NULL;
  }
  free(temp);
}

void printQueue(struct Queue *q) {
  struct Node *temp = q->front;
  if (temp == NULL) {
    printf("\nQueue is empty");
    return;
  } else {
    while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
    }
  }
  printf("\n");
}

int main() {
  struct Queue *q = createQueue();
  int choice;
  while (1) {
    printf("\nQueue Menu\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter "
           "your choice: ");
    scanf("%d", &choice);
    if (choice == 1) {
      int data;
      printf("Enter data: ");
      scanf("%d", &data);
      enQueue(q, data);
    } else if (choice == 2) {
      deQueue(q);
    } else if (choice == 3) {
      printQueue(q);
    } else if (choice == 4) {
      break;
    }
  }
  printf("Queue Front: %d, Queue Rear: %d", q->front->data, q->rear->data);
  return 0;
}
