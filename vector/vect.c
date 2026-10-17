/**
 * Vector implementation.
 *
 * - Implement each of the functions to create a working growable array (vector).
 * - Do not change any of the structs
 * - When submitting, You should not have any 'printf' statements in your vector 
 *   functions.
 *
 * IMPORTANT: The initial capacity and the vector's growth factor should be 
 * expressed in terms of the configuration constants in vect.h
 */
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "vect.h"

/** Main data structure for the vector. */
struct vect {
  char **data;             /* Array containing the actual data. */
  unsigned int size;       /* Number of items currently in the vector. */
  unsigned int capacity;   /* Maximum number of items the vector can hold before growing. */
};

/** Construct a new empty vector. */
vect_t *vect_new() {

  /* [TODO] Complete the function */

  vect_t *v = NULL;

  return v;
}

/** Delete the vector, freeing all memory it occupies. */
void vect_delete(vect_t *v) {

  /* [TODO] Complete the function */

}

/** Get the element at the given index. */
const char *vect_get(vect_t *v, unsigned int idx) {
  assert(v != NULL);
  assert(idx < v->size);

  /* [TODO] Complete the function */

  return NULL;
}

/** Get a copy of the element at the given index. The caller is responsible
 *  for freeing the memory occupied by the copy. */
char *vect_get_copy(vect_t *v, unsigned int idx) {
  assert(v != NULL);
  assert(idx < v->size);

  /* [TODO] Complete the function */

  return NULL;
}
/** Set the element at the given index. */
void vect_set(vect_t *v, unsigned int idx, const char *elt) {
  assert(v != NULL);
  assert(idx < v->size);

  /* [TODO] Complete the function */

}

/** Add an element to the back of the vector. */
void vect_add(vect_t *v, const char *elt) {
  assert(v != NULL);

  /* [TODO] Complete the function */

}

/** Remove the last element from the vector. */
void vect_remove_last(vect_t *v) {
  assert(v != NULL);

  /* [TODO] Complete the function */

}

/** The number of items currently in the vector. */
unsigned int vect_size(vect_t *v) {
  assert(v != NULL);

  /* [TODO] Complete the function */

  return 0;
}

/** The maximum number of items the vector can hold before it has to grow. */
unsigned int vect_current_capacity(vect_t *v) {
  assert(v != NULL);

  /* [TODO] Complete the function */

  return 0;
}

