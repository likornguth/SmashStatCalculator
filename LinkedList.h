#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

struct Node {
  void *data;
  struct Node *next;
}

struct List{
  struct Node *head;
}

static inline void initList(struct List *list){
  list ->head = 0;
}

struct Node *addFront(struct List *list, void *data);

void traverseList(struct List *list, void (*f)(void *));

struct Node *findNode(struct List *list, const coid *dataSought, int (*compar)(const void *, const void*));
