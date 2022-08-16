#ifndef BIB_H
#define BIB_H

#include <stdio.h>
#include <stdlib.h> 

#define TRUE 1
#define FALSE 0

typedef int tipoinfo;
typedef struct tipoNoArvore ptArvore;           // a estrutura ptArvore é o tipo ponteiro para arvore. é o PONTEIRO para o NODO 


struct tipoNoArvore{                            //tipoNoArvore eh a struct, o NODO que carrega os números
    tipoinfo info;                        
    ptArvore *esq;                              //ptArvore é o ELO, que aponta para o próximo número
    ptArvore *dir;
};


ptArvore* InsereArvore(ptArvore *a, tipoinfo ch);
void Desenha(ptArvore *a);
int Compara (ptArvore *a, ptArvore *b, int *iguais);
ptArvore* Espelha (ptArvore *a, ptArvore *b); 
void CentralE(ptArvore *a); 
int VerificaABP (ptArvore *a, int ant, int atual, int *deBusca);



#endif