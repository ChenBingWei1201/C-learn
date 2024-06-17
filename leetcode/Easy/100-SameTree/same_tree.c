#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *create_new_node(int val) {
  struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  if (node == NULL) {
    printf("Memory allocation failed\n");
    return NULL;
  }
  node->val = val;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void insert(int val, struct TreeNode *root) {}

bool preorder(struct TreeNode *root1, struct TreeNode *root2) {
  if (root1 == NULL || root2 == NULL) {
    return false;
  }
  if (root1->val != root2->val) {
    return false;
  }
  preorder(root1->left, root2->left);
  preorder(root1->right, root2->right);
  return true;
}

// bool isSameTree(struct TreeNode *p, struct TreeNode *q) {}

int main() {
  int array[] = {41, 67, 34, 0,  69, 24, 78, 58, 62, 64, 5,  45, 81,
                 27, 61, 91, 95, 42, 27, 36, 91, 4,  2,  53, 92, 82,
                 21, 16, 18, 95, 47, 26, 71, 38, 69, 12, 67, 99, 35,
                 94, 3,  11, 22, 33, 73, 64, 41, 11, 53, 68};

  return 0;
}
