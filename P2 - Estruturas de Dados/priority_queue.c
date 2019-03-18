#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
typedef struct priority_queue priority_queue;

struct node {
  int item;
  int priority;
  node *next;
};

struct priority_queue {
  node *head;
};

int is_empty(PriorityQueue *pq) { return (pq->head == NULL); }

void enqueue(priority_queue *pq, int i, int p) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->item = i;
  new_node->priority = p;
  if ((is_empty(pq)) || (p > pq->head->priority)) {
    new_node->next = pq->head;
    pq->head = new_node;
  } else {
    node *current = pq->head;
    while ((current->next != NULL) && (current->next->priority > p)) {
      current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
  }
}

node *dequeue(priority_queue *pq) {
  if (is_empty(pq)) {
    printf("Priority Queue underflow");
    return NULL;
  } else {
    node *node = pq->head;
    pq->head = pq->head->next;
    node->next = NULL;
    return node;
  }
}

int maximum(priority_queue *pq) {
  if (is_empty(pq)) {
    printf("Priority Queue underflow");
    return -1;
  } else {
    return pq->head->i;
  }
}

void print_priority_queue(priority_queue *pq);
