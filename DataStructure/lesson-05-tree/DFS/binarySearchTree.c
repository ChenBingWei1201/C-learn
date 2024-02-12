#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int val;
  bool isEmpty;
  struct Node *leftNode;
  struct Node *rightNode;
};

struct BinarySearchTree {
  struct Node *root;
};

struct Node *getEmptyNode(int val) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  if (node == NULL) {
    printf("Memory allocation failed\n");
    return NULL;
  }
  node->val = val;
  node->isEmpty = false;
  node->leftNode = NULL;
  node->rightNode = NULL;
  return node;
}

bool insert(struct Node **root, int val) {
  if (*root == NULL) {
    *root = getEmptyNode(val);
    if (*root == NULL)
      return false;
    return true;
  }

  if (val < (*root)->val)
    return insert(&((*root)->leftNode), val);
  else if (val > (*root)->val)
    return insert(&((*root)->rightNode), val);

  printf("Value already exists: %d\n", val);
  return false;
}

struct Node *getMaxInLeftTree(struct Node *root) {
  struct Node *now = root;
  while (now->rightNode != NULL) {
    now = now->rightNode;
  }
  return now;
}

bool removeAt(struct Node **root, int val) {
  if (*root == NULL)
    return false;

  if (val < (*root)->val)
    return removeAt(&((*root)->leftNode), val);
  else if (val > (*root)->val)
    return removeAt(&((*root)->rightNode), val);
  else {
    if ((*root)->leftNode == NULL) {
      struct Node *temp = (*root)->rightNode;
      free(*root);
      *root = temp;
      return true;
    } else if ((*root)->rightNode == NULL) {
      struct Node *temp = (*root)->leftNode;
      free(*root);
      *root = temp;
      return true;
    } else {
      struct Node *temp = getMaxInLeftTree((*root)->leftNode);
      (*root)->val = temp->val;
      return removeAt(&((*root)->leftNode), temp->val);
    }
  }
}

void inorder(struct Node *root) {
  if (root == NULL)
    return;
  inorder(root->leftNode);
  printf("%d, ", root->val);
  inorder(root->rightNode);
}

void preorder(struct Node *root) {
  if (root == NULL)
    return;
  printf("%d, ", root->val);
  preorder(root->leftNode);
  preorder(root->rightNode);
}

void posorder(struct Node *root) {
  if (root == NULL)
    return;
  posorder(root->leftNode);
  posorder(root->rightNode);
  printf("%d, ", root->val);
}

void deleteTree(struct Node *root) {
  if (root == NULL)
    return;
  deleteTree(root->leftNode);
  deleteTree(root->rightNode);
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
    if (!insert(&(bst->root), array[i])) {
      printf("Insert fail: %d\n", array[i]);
    }
  }
  printf("Inorder traversal: \n");
  inorder(bst->root);
  printf("\n");
  printf("Preorder traversal: \n");
  preorder(bst->root);
  printf("\n");
  printf("Postorder traversal: \n");
  posorder(bst->root);
  printf("\n");

  deleteTree(bst->root);
  free(bst);
  return 0;
}
