#ifndef AVL_H
#define AVL_H

#include "bib.h"

pNodoAVL * insereArvoreAVL(pNodoAVL * a, tipoInfo info);
int altura (pNodoAVL * a);
int calculaFB(pNodoAVL * a);
void desenha(pNodoAVL * a , int nivel);
int is_avl(pNodoAVL * a);
pNodoAVL * rotacaoDireita(pNodoAVL * pt);
pNodoAVL * rotacaoEsquerda(pNodoAVL * pt);
pNodoAVL * rotacaoDuplaDireita (pNodoAVL * pt);
pNodoAVL * rotacaoDuplaEsquerda (pNodoAVL * pt);

pNodoAVL * Caso1 (pNodoAVL * a , int *ok);
pNodoAVL * Caso2 (pNodoAVL * a , int *ok);

pNodoAVL * insereAVL (pNodoAVL * a, tipoInfo x, int *ok);



#endif
