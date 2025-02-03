#include <assert.h>

#include "../../src/vector/vector.h"

int main(void) {
  Vector(int) vec;
  vector_new(&vec);

  assert(vec.length == 0);
  assert(vec.capacity == 0);
  assert(vec.items == NULL);

  vector_push(&vec, 10);
  vector_push(&vec, 20);
  vector_push(&vec, 30);

  assert(vec.items[0] == 10);
  assert(vec.items[1] == 20);
  assert(vec.items[2] == 30);

  vector_free(&vec);

  assert(vec.length == 0);
  assert(vec.capacity == 0);
  assert(vec.items == NULL);

  return 0;
}
