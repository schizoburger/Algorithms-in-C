#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

typedef int ElType;

typedef struct ListEl {
    ElType key;
    struct ListEl *next;
} ListEl;

ListEl* PushFront(ListEl* head, ElType k)
{
    ListEl* w = (ListEl*) malloc(sizeof(ListEl));
    w->key = k;
    w->next = head;
    return w; // the new head
}

void DisplayList(ListEl* head)
{
    ListEl* w = head;
    while (w != NULL) {
        printf("%d, ", w->key);
        w = w->next;
    }
}

int main()
{
    int i;
    srand(time(NULL));

    ListEl* head = NULL;

    for (i = 0; i < 20; i++)
        head = PushFront(head, rand()%100);

    DisplayList(head);

    printf("\n");
    return 0;
}

