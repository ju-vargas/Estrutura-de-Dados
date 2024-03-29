#ifndef AVL_H
#define AVL_H

#include "bib.h"

pNodoAVL * insereArvoreAVL(pNodoAVL * a, tipoInfo info);
pNodoAVL * pesquisaPadraoAVL(pNodoAVL *a, char comida[STRING_SIZE], int *comp);
pNodoAVL *pesquisaSelecionadaAVL(pNodoAVL *a, char comida[STRING_SIZE], int *comp);
pNodoAVL *pesquisaCentralEAVL(pNodoAVL *a, char comida[STRING_SIZE], int *comp);
pNodoAVL *pesquisaCentralDAVL(pNodoAVL *a, char comida[STRING_SIZE], int *comp);
int alturaAVL (pNodoAVL * a);
int calculaFB(pNodoAVL * a);
void desenha(pNodoAVL * a , int nivel);
int is_avl(pNodoAVL * a);
pNodoAVL * rotacaoDireita(pNodoAVL * pt);
pNodoAVL * rotacaoEsquerda(pNodoAVL * pt);
pNodoAVL * rotacaoDuplaDireita (pNodoAVL * pt);
pNodoAVL * rotacaoDuplaEsquerda (pNodoAVL * pt);
pNodoAVL * Caso1 (pNodoAVL * a , int *ok);
pNodoAVL * Caso2 (pNodoAVL * a , int *ok);
pNodoAVL * insereAVL (pNodoAVL * a, tipoInfo x, int *ok, int *rotacoes);
pNodoAVL * preencheAVL(FILE *arqCalorias, pNodoAVL *arvAVL, int *ok, int *rotacoes);

#endif
