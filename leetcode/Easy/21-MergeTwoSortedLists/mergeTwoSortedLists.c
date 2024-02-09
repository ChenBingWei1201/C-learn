#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
  if (list1 == NULL) {
    return list2;
  }
  if (list2 == NULL) {
    return list1;
  }
  struct ListNode *temp = list1;
  temp->next = list1->next;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = list2;
  struct ListNode *current = list1;
  bool swapped;
  int tempVal;
  do {
    current = list1;
    swapped = false;
    while (current->next != NULL) {
      if (current->val > current->next->val) {
        tempVal = current->val;
        current->val = current->next->val;
        current->next->val = tempVal;
        swapped = true;
      }
      current = current->next;
    }
  } while (swapped);
  return list1;
}

struct ListNode *initialize(struct ListNode *list) {
  list->val = 1;
  list->next = (struct ListNode *)malloc(sizeof(struct ListNode));
  list->next->val = 2;
  list->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
  list->next->next->val = 4;
  list->next->next->next = NULL;
  return list;
}

void freeList(struct ListNode *list) {
  free(list->next->next);
  free(list->next);
  free(list);
}

int main() {
  struct ListNode *list1 = (struct ListNode *)malloc(sizeof(struct ListNode));
  struct ListNode *list2 = (struct ListNode *)malloc(sizeof(struct ListNode));
  list1 = initialize(list1);
  list2 = initialize(list2);
  struct ListNode *mergedList = mergeTwoLists(list1, list2);
  while (mergedList != NULL) {
    printf("%d ", mergedList->val);
    mergedList = mergedList->next;
  }
  freeList(list1);
  freeList(list2);
  return 0;
}
