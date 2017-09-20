#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
  int elem;
  struct lista *nast;
} *plista;

plista stworzListe(int);

int main() {
  int n = 1;
  plista pocz = stworzListe(n);
  pocz -> elem = 1;
  plista nowy = stworzListe(n);
  pocz -> nast = nowy;
  nowy -> elem = 5;
  printf("%d\n", pocz -> nast -> elem);
}

plista stworzListe(int n) {
  if (n <= 0) return NULL;
  plista pocz = malloc(sizeof(struct lista));
  if (n==1) return pocz;
  int i;
  plista nowy = malloc(sizeof(struct lista));
  pocz -> nast = nowy;
  for (i = 3; i < n + 1; i = i + 1) {
    plista nasti = malloc(sizeof(struct lista));
    nowy -> nast = nasti;
    nowy = nasti;
  }
  return pocz;
}
