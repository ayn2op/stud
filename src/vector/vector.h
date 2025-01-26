#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdlib.h>

#define Vec(type)    \
  struct {           \
    size_t length;   \
    size_t capacity; \
    type* items;     \
  }

#define vec_new(vec)     \
  do {                   \
    (vec)->length = 0;   \
    (vec)->capacity = 0; \
    (vec)->items = NULL; \
  } while (0)

#define vec_free(vec)    \
  do {                   \
    free((vec)->items);  \
    (vec)->length = 0;   \
    (vec)->capacity = 0; \
    (vec)->items = NULL; \
  } while (0)

#define vec_push(vec, item)                                                 \
  do {                                                                      \
    if ((vec)->length == (vec)->capacity) {                                 \
      size_t new_capacity = (vec)->capacity == 0 ? 1 : (vec)->capacity * 2; \
      void* new_items =                                                     \
          realloc((vec)->items, new_capacity * sizeof(*(vec)->items));      \
      if (!new_items) exit(EXIT_FAILURE);                                   \
      (vec)->capacity = new_capacity;                                       \
      (vec)->items = new_items;                                             \
    }                                                                       \
    (vec)->items[(vec)->length++] = (item);                                 \
  } while (0)

#define vec_length(vec) ((vec)->length)
#define vec_is_empty(vec) ((vec)->length == 0)

#endif
