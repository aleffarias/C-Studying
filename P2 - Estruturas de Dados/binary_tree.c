#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct binary_tree binary_tree;

struct binary_tree {
  int item;
  binary_tree *left;
  binary_tree *right;
};

binary_tree *create_empty_binary_tree() { return NULL; }

binary_tree *create_binary_tree(int item, binary_tree *left,
                                binary_tree *right) {
  binary_tree *new_binary_tree = (binary_tree *)malloc(sizeof(binary_tree));
  new_binary_tree->item = item;
  new_binary_tree->left = left;
  new_binary_tree->right = right;
  return new_binary_tree;
}

binary_tree *search(binary_tree *bt, int item) {
  if ((bt == NULL) || (bt->item == item)) {
    return bt;
  } else if (bt->item > item) {
    return search(bt->left, item);
  } else {
    return search(bt->right, item);
  }
}

int is_empty(binary_tree *bt) { return (bt == NULL); }

binary_tree *add(binary_tree *bt, int item) {
  if (bt == NULL) {
    bt = create_binary_tree(item, NULL, NULL);
  } else if (bt->item > item) {
    bt->left = add(bt->left, item);
  } else {
    bt->right = add(bt->right, item);
  }
  return bt;
}

void print_in_order(binary_tree *bt) {
  if (!is_empty(bt)) {
    print_in_order(bt->left);
    printf(" %d ", bt->item);
    print_in_order(bt->right);
  }
}

void print_pre_order(binary_tree *bt) {
  if (!is_empty(bt)) {
    printf("%d", bt->item);
    print_pre_order(bt->left);
    print_pre_order(bt->right);
  }
}

void print_post_order(binary_tree *bt) {
  if (!is_empty(bt)) {
    print_post_order(bt->left);
    print_post_order(bt->right);
    printf("%d", bt->item);
  }
}

int main() {
  int n;

  binary_tree *no = (binary_tree *)malloc(sizeof(binary_tree));
  no = create_empty_binary_tree();

  while (scanf("%d", &n) != EOF) {
    no = add(no, n);

    printf("\n----\nAdicionando %d\n    ", n);
    print_in_order(no);

    printf("\npre\n");
    print_pre_order(no);

    printf("\npos\n");
    print_post_order(no);
  }

  printf("\n----");

  return 0;
}
