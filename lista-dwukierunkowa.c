#include <stdlib.h>
#include <stdio.h>

typedef struct ListEl {
    int key;
    struct ListEl *next;
    struct ListEl *prev;
} ListEl;

ListEl* NaLewo(ListEl* biezacy)
{
    if (biezacy && biezacy->prev)
        return biezacy->prev;
    else
        return biezacy;
}


ListEl* NaPrawo(ListEl* biezacy)
{
    if (biezacy && biezacy->next)
        return biezacy->next;
    else
        return biezacy;
}

void Wyswietl(ListEl* biezacy)
{
    ListEl* w = biezacy;
    while (w && w->prev)
        w = w->prev;

    while (w) {
        if (w == biezacy)
            printf("(%d) ", w->key);
        else
            printf("%d ", w->key);

        w = w->next;
    }

    printf("\n");
}

ListEl* Dodaj(ListEl* biezacy, int k)
{
    ListEl* w = (ListEl*) malloc(sizeof(ListEl));
    w->key = k;
    w->next = NULL;
    w->prev = NULL;

    if (!biezacy)
        return w;

    if (!(biezacy->prev)) {
        w->next = biezacy;
        biezacy->prev = w;
        return w;
    }

    ListEl* v = biezacy->prev;
    v->next = w;
    w->next = biezacy;
    biezacy->prev = w;
    w->prev = v;
    return w;
}

ListEl* Usun(ListEl* biezacy)
{
    if(!biezacy)
        return NULL;

    ListEl* v = biezacy->prev;
    ListEl* w = biezacy->next;

    free(biezacy);

    if (v)
        v->next = w;

    if (w)
        w->prev = v;


    if (w)
        return w;
    else
        return v;
}

int main()
{
    ListEl* biezacy = NULL;

    int i;
    for (i = 10; i >= 1; i--)
        biezacy = Dodaj(biezacy, i);

    Wyswietl(biezacy);

    //biezacy = NaPrawo(biezacy);
    //biezacy = NaPrawo(biezacy);
    //biezacy = NaPrawo(biezacy);

    //Wyswietl(biezacy);

    //biezacy = NaLewo(biezacy);

    //Wyswietl(biezacy);

    //biezacy = Usun(biezacy);

    //Wyswietl(biezacy);

    while (1) {
        printf("\n");
        printf("1: Na lewo.\n");
        printf("2: Na prawo.\n");
        printf("3: Wyswietl.\n");
        printf("4: Dodaj element.\n");
        printf("5: Usun element.\n");
        printf("6: Zakoncz.\n\n");
        printf("Podaj komende (1,2,3,4,5 lub 6): ");
        int c;
        scanf("%d", &c);

        if (c == 6)
            break;

        switch (c) {
            case 1: biezacy = NaLewo(biezacy); break;
            case 2: biezacy = NaPrawo(biezacy); break;
            case 3: Wyswietl(biezacy); break;
            case 4: 
                printf("Podaj wartosc klucza nowego elementu: ");
                int k;
                scanf("%d", &k); 
                biezacy = Dodaj(biezacy,k); 
                break;
            case 5: biezacy = Usun(biezacy); break;
            default: printf("Nie znana komenda.\n");
        }
    }

    return 0;
}


