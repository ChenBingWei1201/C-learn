#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Define Node structure for the Binary Search Tree
struct Node {
  int val;
  struct Node *leftNode;
  struct Node *rightNode;
};

// Define BinarySearchTree structure
struct BinarySearchTree {
  struct Node *root;
};

// Define QueueNode structure for the BFS Queue
struct QueueNode {
  struct Node *data;
  struct QueueNode *next;
};

// Define Queue structure
struct Queue {
  struct QueueNode *front, *rear;
};

// Function to create a new queue node
struct QueueNode *createQueueNode(struct Node *node) {
  struct QueueNode *newNode =
      (struct QueueNode *)malloc(sizeof(struct QueueNode));
  if (newNode == NULL) {
    printf("Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  newNode->data = node;
  newNode->next = NULL;
  return newNode;
}

// Function to create an empty queue
struct Queue *createQueue() {
  struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
  if (queue == NULL) {
    printf("Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  queue->front = queue->rear = NULL;
  return queue;
}

// Function to enqueue a node
void enqueue(struct Queue *queue, struct Node *node) {
  struct QueueNode *newNode = createQueueNode(node);
  if (queue->rear == NULL) {
    queue->front = queue->rear = newNode;
  } else {
    queue->rear->next = newNode;
    queue->rear = newNode;
  }
}

// Function to dequeue a node
struct Node *dequeue(struct Queue *queue) {
  if (queue->front == NULL)
    return NULL;
  struct QueueNode *temp = queue->front;
  struct Node *data = temp->data;
  queue->front = queue->front->next;
  if (queue->front == NULL)
    queue->rear = NULL;
  free(temp);
  return data;
}

// Function to perform BFS traversal
void bfs(struct Node *root) {
  if (root == NULL)
    return;

  struct Queue *queue = createQueue();
  enqueue(queue, root);

  while (queue->front != NULL) {
    struct Node *current = dequeue(queue);
    printf("%d, ", current->val);

    if (current->leftNode != NULL)
      enqueue(queue, current->leftNode);
    if (current->rightNode != NULL)
      enqueue(queue, current->rightNode);
  }
  printf("\n");
}

// Function to create a new node
struct Node *createNode(int val) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  if (node == NULL) {
    printf("Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  node->val = val;
  node->leftNode = NULL;
  node->rightNode = NULL;
  return node;
}

// Function to insert a node into the BST
void insert(struct Node **root, int val) {
  if (*root == NULL) {
    *root = createNode(val);
  } else {
    if (val < (*root)->val)
      insert(&((*root)->leftNode), val);
    else if (val > (*root)->val)
      insert(&((*root)->rightNode), val);
    else
      printf("Value already exists: %d\n", val);
  }
}

// Function to free memory allocated for the tree nodes
void freeTree(struct Node *root) {
  if (root == NULL)
    return;
  freeTree(root->leftNode);
  freeTree(root->rightNode);
  free(root);
}

int main() {
  int array[] = {41, 67, 34, 0,  69, 24, 78, 58, 62, 64, 5,  45, 81,
                 27, 61, 91, 95, 42, 27, 36, 91, 4,  2,  53, 92, 82,
                 21, 16, 18, 95, 47, 26, 71, 38, 69, 12, 67, 99, 35,
                 94, 3,  11, 22, 33, 73, 64, 41, 11, 53, 68};

  struct BinarySearchTree *bst =
      (struct BinarySearchTree *)malloc(sizeof(struct BinarySearchTree));
  if (bst == NULL) {
    printf("Memory allocation failed\n");
    return 1;
  }
  bst->root = NULL;

  for (size_t i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
    printf("Insert: %d\n", array[i]);
    insert(&(bst->root), array[i]);
  }

  printf("BFS Traversal:\n");
  bfs(bst->root);

  freeTree(bst->root);
  free(bst);

  return 0;
}
