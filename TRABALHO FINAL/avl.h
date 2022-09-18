#ifndef AVL_H
#define AVL_H

#include "bib.h"

pNodoAVL * InsereArvoreAVL(pNodoAVL * a, tipoInfo info);
int Altura (pNodoAVL * a);
int Calcula_FB(pNodoAVL * a);
void Desenha(pNodoAVL * a , int nivel);

int is_avl(pNodoA * a);
pNodoA * rotacao_direita(pNodoA * pt);
pNodoA * rotacao_esquerda(pNodoA * pt);
pNodoA * rotacao_dupla_direita (pNodoA * pt);
pNodoA * rotacao_dupla_esquerda (pNodoA * pt);
pNodoA * Caso1 (pNodoA * a , int *ok);
pNodoA * Caso2 (pNodoA * a , int *ok);
pNodoA * InsereAVL (pNodoA * a, tipoInfo x, int *ok);

int comparaAlimento (tipoInfo info, char nome[50]); 

#endif
