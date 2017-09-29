#include <studio.h>

typedef int typklucza;
typedef char[] typdanej;

typedef struct vertex {
  typklucza klucz;
  typdanej dana;
  struct vertex *lewy,*prawy;
} vertex, *pvertex;

pvertex root;

void InitBst(void){
  root = NULL;
}

pvertex BSTNewLeaf(typklucza klucz, typdanej dana) {
  pvertex p;

  if ((p=malloc(sizeof(vertex))) {
    p->klucz=klucz;
    p->dana=dana;
    p->lewy=p->prawy=NULL;
  }

  return p;
}

void BSTInsert(typklucza klucz, typdanej dana) {
  pvertex *p;

  p = &root;
  while (*p) {
    if ((*p)->klucz==klucz) return;
    else if ((*p)->klucz > klucz) p=&(*p)->lewy;
    else p=&(*p)->prawy;
  }
  *p=BSTNewLeaf(klucz,dana);
}

char BSTFind(typklucza klucz, typdanej dana) {
  pvertex p;

  p = root;
  while (p) {
    if (p->klucz==klucz) {
      *dana=p->dana;
      return 1;
    } else if (p->klucz > klucz) {
      p = p->lewy;
    } else {
      p = p->prawy;
    }
  }
  return 0;
}

void BSTDestroy(pvertex *tree) {
  while(*tree) {
    BSTDestroy(&(*tree)->lewy);
    BSTDestroy(&(*tree)->prawy);
    free(*tree);
    *tree=NULL;
  }
}
