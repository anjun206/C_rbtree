#include "rbtree.h"
#include <stddef.h>
#include <stdlib.h>

rbtree *new_rbtree(void) {
  rbtree *p = calloc(1, sizeof *p);
  if (!p) abort();

  node_t *sentinel = calloc(1, sizeof *sentinel);
  if (!sentinel) abort();

  sentinel->color  = RBTREE_BLACK;
  sentinel->left   = sentinel;
  sentinel->right  = sentinel;
  sentinel->parent = sentinel;

  p->nil  = sentinel;
  p->root = sentinel;
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

// x 노드 기준으로 우측 회전
static void rotate_right (rbtree *t, node_t *x) {

  // x 노드 좌측 자식 = y 노드
  node_t *y = x->left;

    // y 우측 자식 x 좌측으로 옮겨주기
    x->left = y->right;
    if (y->right != t->nil) {
      y->right->parent = x;
    }

  // x,y 부모 교환
  y->parent = x->parent;
  
    // x가 root인지 왼쪽 자식인지, 오른쪽 자식인지 구분
    if (x->parent == t->nil) {
      t->root = y;
    }
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;

  // x y의 자식관계로 만들고 마무리
  y->right = x;
  x->parent = y;
}

// x 노드 기준 좌측 회전
static void rotate_left (rbtree *t, node_t *x) {

  // x 노드 우측 자식 = y 노드
  node_t *y = x->right;

    // y 좌측 자식 x 우측으로 옮겨주기
    x->right = y->left;
    if (y->left != t->nil) {
      y->left->parent = x;
    }

  // x,y 부모 교환
  y->parent = x->parent;
  
    // x가 root인지 왼쪽 자식인지, 오른쪽 자식인지 구분
    if (x->parent == t->nil) {
      t->root = y;
    }
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;

  // x y의 자식관계로 만들고 마무리
  y->left = x;
  x->parent = y;
}

static void rb_check(rbtree *t, node_t *n) {
  while (n->parent->color == RBTREE_RED) {
  // case 1
  if (n->parent->left == RBTREE_RED && n->parent->right == n) {
    n->parent->left = RBTREE_BLACK;
    n->parent = RBTREE_BLACK;
  }
  else if (n->parent->right == RBTREE_RED && n->parent->left == n) {
    n->parent->right = RBTREE_BLACK;
    n->parent = RBTREE_BLACK;
  }
  // case 2
  else if (n->parent->right == n 
        && n->parent->parent->left == n->parent
        && n->parent->parent->right->color == RBTREE_BLACK
  ) {
    rotate_left(t, n->parent);
  }
    else if (n->parent->left == n 
        && n->parent->parent->right == n->parent
        && n->parent->parent->left->color == RBTREE_BLACK
  ) {
    rotate_right(t, n->parent);
  }
  // case 3
  else if (n->parent->left == n
        && )
  // 할아버지에서 위반 여부 확인
  }
}



node_t *rbtree_insert(rbtree *t, const key_t key) {
  // TODO: implement insert
  // nil 경계
  if (!t) return NULL;

  node_t *z = calloc(1, sizeof *z);
  if (!z) return NULL;
  z->key=key;
  z->color=RBTREE_RED;
  z->left=z->right=z->parent=t->nil;

  // y = nil
  // x = root 노드
  node_t *y = t->nil;
  node_t *x = t->root;

  while (x != t->nil) {
      y = x;
      if (key < x->key) {
             x = x->left;
      } else x = x->right;
  }

  z->parent = y;
  if (y == t->nil) {
      t->root = z; 
  } else if (key < y->key) {
      y->left = z;
  } else {
      y->right = z;
  }

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
