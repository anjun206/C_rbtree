#include "rbtree.h"

#include <stdlib.h>

rbtree *new_rbtree(void) {
  rbtree *p = calloc(1, sizeof(rbtree));
  // TODO: initialize struct if needed
  node_t *nil = malloc(sizeof *nil);
  nil->color = RBTREE_BLACK;
  nil->left = nil;
  nil->right = nil;
  nil->parent = nil;
  p->nil->color = RBTREE_BLACK;
  p->root = p->nil; 
  return p;
}

static void free_subtree(rbtree *t, node_t *x) {
  if (x == t->nil) return;
    free_subtree(t, x->left);
    free_subtree(t, x->right);
    free(x);
}

void delete_rbtree(rbtree *t) {
  // TODO: reclaim the tree nodes's memory
  if (!t) return;
  free_subtree(t, t->root);
  free(t->nil);
  free(t);
}

node_t *rbtree_insert(rbtree *t, const key_t key) {
  // TODO: implement insert
  if (!t || !key) return;
  if (t->root->key == NULL) t->root->key = key;
  return t->root;
}

node_t *rbtree_find(const rbtree *t, const key_t key) {
  // TODO: implement find
  return t->root;
}

node_t *rbtree_min(const rbtree *t) {
  // TODO: implement find
  return t->root;
}

node_t *rbtree_max(const rbtree *t) {
  // TODO: implement find
  return t->root;
}

int rbtree_erase(rbtree *t, node_t *p) {
  // TODO: implement erase
  return 0;
}

int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n) {
  // TODO: implement to_array
  return 0;
}
