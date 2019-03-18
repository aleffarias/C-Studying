#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

// Cria a estrutura
struct node {
  int item;
  node *next;
};

node *create_linked_list() {
  return NULL; // Lista Vazia
}

node *add(node *head, int item) { // Tem como argumento o pontiro do tipo 'node'
                                  // e item que se deseja add
  node *new_node = (node *)malloc(sizeof(node));
  new_node->item = item;
  new_node->next = head;
  return new_node;
}

node *search(node *head, int item) {
  while (head != NULL) {
    if (head->item == item) {
      return head;
    }
    head = head->next;
  }
  return NULL;
}

node *remove_node(node *head, int item) {
  node *previous = NULL;
  node *current = head;
  while (current != NULL && current->item != item) {
    previous = current;
    current = current->next;
  }
  if (current == NULL) {
    return head;
  }
  if (previous == NULL) {
    head = current->next;
  } else {
    previous->next = current->next;
  }
  free(current);
  return head;
}

int is_empty(node *head) { return (head == NULL); }

void print_linked_list(node *head) {
  while (head != NULL) {
    printf("%d\n", head->item);
    head = head->next;
  }
}

void print_linked_list_recursively(node *head) {
  if (!is_empty(head)) {
    printf("%d\n", head->item);
    print_linked_list(head->next);
  }
}

int main() {
  node *list = create_linked_list();
  list = add(list, 3);
  list = add(list, 9);
  list = add(list, 27);
  list = add(list, 81);
  list = add(list, 243);
  printf("Complete list: \n");
  print_linked_list(list);
}
