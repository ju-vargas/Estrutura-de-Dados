#ifndef BIB_H
#define BIB_H

#include <stdio.h>
#include <stdlib.h> 

#define TRUE 1
#define FALSE 0

#include <string.h>

typedef struct tipoNo ptLSE;        // a estrutura ptLSE é o tipo ponteiro para lista simplesmente encadeada. é o PONTEIRO para o NODO 

struct tipoNo{                      //tipoNo eh a struct, o NODO que carrega os números
 int numero;                        
 ptLSE *prox;                       //ptLSE é o ELO, que aponta para o próximo número
};

ptLSE* cria_lista(void);
ptLSE* insere (ptLSE *PtLista, int aux);
ptLSE* busca(void);
ptLSE* destroi(ptLSE *ptLista);
void imprime(ptLSE *ptLista);


#endif