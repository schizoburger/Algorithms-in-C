#include <stdio.h>
#include <stdlib.h>

typedef struct ElemListy {

   int wartosc;

   struct ElemListy *nast;

} ElemListy;

ElemListy* WstawDoListyRosnacej(ElemListy*,int);
void wyswietlListe(ElemListy*);
ElemListy* stworzListe(int);
ElemListy* Stworz();
ElemListy* odwroc(ElemListy*);
ElemListy* sortuj(ElemListy*);
ElemListy* polacz(ElemListy*,ElemListy*);

int main() {
  ElemListy* pocz = stworzListe(6);
  pocz = WstawDoListyRosnacej(pocz,11);
  wyswietlListe(pocz);
  ElemListy* pocz2 = Stworz();
  wyswietlListe(pocz2);
  ElemListy* pocz3 = stworzListe(50);
  ElemListy* pocz4= stworzListe(33);
  ElemListy* polaczona = polacz(pocz3,pocz4);
  wyswietlListe(polaczona);
  polaczona = sortuj(polaczona);
  wyswietlListe(polaczona);
}

ElemListy* WstawDoListyRosnacej(ElemListy* pocz, int k) {
  ElemListy* nowy = malloc(sizeof(struct ElemListy));
  nowy->wartosc=k;
  if (!pocz) {
    nowy->nast=NULL;
    return nowy;
  }
  if (pocz->wartosc>=k) {
    nowy->nast=pocz;
    return nowy;
  }
  ElemListy* w=pocz;
  while (w->nast) {
    if (w->nast->wartosc>k) {
      nowy->nast=w->nast;
      w->nast=nowy;
      return pocz;
    }
    w=w->nast;
  }
  w->nast=nowy;
  nowy->nast=NULL;
  return pocz;
}

void wyswietlListe(ElemListy* pocz) {
  ElemListy* w = pocz;
  while (w) {
    printf("%d\n", w->wartosc);
    w=w->nast;
  }
}

ElemListy* stworzListe(int n) {
  ElemListy* pocz = NULL;
  int i;
  for (i=n;i>=1;i--) {
    ElemListy* nowy = malloc(sizeof(struct ElemListy));
    nowy->wartosc=2*i;
    nowy->nast=pocz;
    pocz=nowy;
  }
  return pocz;
}

ElemListy* Stworz() {
  ElemListy* pocz = NULL;
  int c;
  while (scanf("%d\n", &c) >= 0) {
    ElemListy* nowy = malloc(sizeof(struct ElemListy));
    nowy->wartosc=c;
    nowy->nast=pocz;
    pocz=nowy;
  }
  return odwroc(pocz);
}

ElemListy* odwroc(ElemListy* pocz) {
  ElemListy* pocz2=NULL;
  while(pocz){
    ElemListy* w=pocz->nast;
    pocz->nast=pocz2;
    pocz2=pocz;
    pocz=w;
  }
  return pocz2;
}

ElemListy* sortuj(ElemListy* pocz)
{
    ElemListy* pocz2 = NULL;

    ElemListy* w = pocz;
    while (w != NULL)
    {

        pocz2 = WstawDoListyRosnacej(pocz2,w->wartosc);

        w = w->nast;
    }

    return pocz2;
}
ElemListy* polacz(ElemListy* pocz1,ElemListy* pocz2) {
  ElemListy* w = pocz1;
  if (w==NULL) {
    w =pocz2;
    return w;
  }
  while(w->nast!=NULL) {
    w=w->nast;
  }
  w->nast=pocz2;
  return pocz1;
}
