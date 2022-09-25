#ifndef ABP_H
#define ABP_H

#include "bib.h"

pNodoA *insere(pNodoA *a, tipoInfo ch);
pNodoA *preencheABP(FILE *arqCalorias, pNodoA *arv, int *nroNodos);
int alturaABP (pNodoA *a);

#endif
