#ifndef ABP_H
#define ABP_H

#include "bib.h"

pNodoA *insereABP(pNodoA *a, tipoInfo ch);
pNodoA *preencheABP(FILE *arqCalorias, pNodoA *arv, int *nroNodos);
int alturaABP (pNodoA *a);
pNodoA *pesquisaPadrao(pNodoA *a, char comida[STRING_SIZE], int *);
pNodoA *pesquisaSelecionada(pNodoA *a, char comida[STRING_SIZE], int *);
pNodoA *pesquisaCentralE(pNodoA *a, char comida[STRING_SIZE], int *comp);
pNodoA *pesquisaCentralD(pNodoA *a, char comida[STRING_SIZE], int *comp);
pNodoA *pesquisaPreFixadoE(pNodoA *a, char comida[STRING_SIZE], int *comp);
pNodoA *pesquisaPreFixadoD(pNodoA *a, char comida[STRING_SIZE], int *comp);
pNodoA *pesquisaPosFixadoE(pNodoA *a, char comida[STRING_SIZE], int *comp);
pNodoA *pesquisaPosFixadoD(pNodoA *a, char comida[STRING_SIZE], int *comp);
void preFixadoE(pNodoA *a);
void centralE(pNodoA *a);

#endif
