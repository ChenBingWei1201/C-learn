#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *array;
  size_t size;
  size_t capacity;
} Vector;

void vector_init(Vector *v) {
  v->size = 0;
  v->capacity = 4; // initial capacity
  v->array = (int *)malloc(v->capacity * sizeof(int));
}

void vector_append(Vector *v, int value) {
  if (v->size >= v->capacity) {
    v->capacity *= 2;
    v->array = (int *)realloc(v->array, v->capacity * sizeof(int));
  }
  v->array[v->size++] = value;
}

void vector_free(Vector *v) {
  free(v->array);
  v->array = NULL;
  v->size = v->capacity = 0;
}

int main() {
  Vector v;
  vector_init(&v);

  // Append elements to the vector
  for (int i = 0; i < 10; i++) {
    vector_append(&v, i);
  }

  // Print the elements
  for (size_t i = 0; i < v.size; i++) {
    printf("%d ", v.array[i]);
  }
  printf("\n");

  // Free the memory used by the vector
  vector_free(&v);

  return 0;
}
