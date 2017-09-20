/* ZADANIA dla cwiczen 2/6/2014:
   1: Napisac funkcje do tworzenia grafu transponowanego z danego grafu.
      Oba grafy wejsciowe i wyjsciowe sa przekazane przez parametry.
   2: Napisac funkcje, ktora wypisuje dany graf do danego pliku tekstowego.
      Format danych tego pliku ma byc taki sam jak format danych pliku
      wejsciowego korzystany przez zaimplementowana funkcje WczytajGraf.
   3: Napisac funkcje, ktora sprawdza czy dany graf jest dwudzielny.
   Nalezy testowac Twoje funkcje.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct ElemListy {
    int nr;
    struct ElemListy *next;
} ElemListy;

typedef struct {
    int n; // ilosc wierzcholkow grafu
    ElemListy* ls[MAX]; // ls[k] jest wskaznikiem do pierwszego elementu listy sasiedztwa wierzcholka nr k
} Graf;

void WczytajGraf(char* nazwa_pliku, Graf* g)
// nazwa_pliku jest parametrem wejsciowy
// g jest parametrem wyjsciowym
{
    int i;

    FILE* f = fopen(nazwa_pliku, "r");
    if (f == NULL) {
        printf("Blad otwierania pliku %s.\n", nazwa_pliku);
        return;
    }

    g->n = 0;
    if (fscanf(f, "%d", &(g->n)) == 0) {
        printf("Zly format danych dla grafu.\n");
        fclose(f);
        return; // zly format pliku danych wejsciowych
    }

    for (i = 0; i < g->n; i++)
        g->ls[i] = NULL;

    while (!feof(f)) {
        int u, v;
        if (fscanf(f, "%d%d", &u, &v) == 2) {
            // mamy krawedz z u do v

            if (u >= g->n || v >= g->n) {
                printf("Nie poprawne dane grafu.\n");
                fclose(f);
                return;
            }

            ElemListy* wsk = (ElemListy*) malloc(sizeof(ElemListy));
            wsk->nr = v;
            wsk->next = g->ls[u];
            g->ls[u] = wsk;
        }
    }

    fclose(f);
}

void WyswietlGraf(Graf* g)
{
    int i;

    printf("Ilosc wierzcholkow: %d.\n", g->n);
    printf("Krawedzie:\n");

    for (i = 0; i < g->n; i++) {
        printf("Lista sasiedztwa wierzcholka nr %d: ", i);
        ElemListy* wsk = g->ls[i];
        while (wsk != NULL) {
            printf("%d ", wsk->nr);
            wsk = wsk->next;
        }
        printf("\n");
    }
}

void Transpozycja(Graf* g, Graf* gT) {
  int i;
  gT->n=g->n;
  for (i = 0; i < g->n; i++)
      gT->ls[i] = NULL;

  for (i=0; i < g->n; i++) {
    ElemListy* lsc = g->ls[i];
    while (lsc) {
      ElemListy* wsk = (ElemListy*) malloc(sizeof(ElemListy));
      wsk->nr = i;
      wsk->next=gT->ls[lsc->nr];
      gT->ls[lsc->nr] = wsk;
      lsc = lsc->next;
    }
  }
}

int main()
{
    char nazwa_pliku[80];
    printf("Podaj nazwe pliku zawierajacego dane grafu: ");
    scanf("%s", nazwa_pliku);

    Graf g, gT;
    WczytajGraf(nazwa_pliku, &g);
    Transpozycja(&g, &gT);
    WyswietlGraf(&g);
    WyswietlGraf(&gT);

    return 0;
}
