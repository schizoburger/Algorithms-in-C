#include <stdio.h>
#include <stdlib.h>

typedef struct ElementOfList {

  int value;

  struct ElementOfList *next;

} ElementOfList;

ElementOfList* getListOfLength(int);
void printList(ElementOfList*);

ElementOfList* getListOfLength(int n) {
  ElementOfList* start = NULL;
  int i;
  for (i = n; i > 0; i--) {
    ElementOfList* new = malloc(sizeof(struct ElementOfList));
    new->value = i;
    new->next = start;
    start = new;
  }
  return start;
}

void printList(ElementOfList* start) {
  int i;
  while (start) {
    printf("%d\n", start->value);
    start = start->next;
  }
}
