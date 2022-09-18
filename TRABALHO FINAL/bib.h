#ifndef BIB_H
#define BIB_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

//ESTRUTURAS **************************************************************************************************************
//struct info (campo info do NODO)
typedef struct tipoInfo{
    int calorias;
    char alimento[50];
}tipoInfo;


//struct nodo ABP
struct TNodoA{
    tipoInfo nodoInfo;
    struct TNodoA *esq;
    struct TNodoA *dir;
};

typedef struct TNodoA pNodoA;


//struct nodo AVL
struct TNodoAVL{
    tipoInfo nodoInfo;
    int FB;                     //fator de balanceamento
    struct TNodoAVL *esq;
    struct TNodoAVL *dir;
};

typedef struct TNodoAVL pNodoAVL;

//FUNÇOES BIB.C *************************************************************************************************************
void preFixadoE(pNodoA *a);
int comparaAlimento (tipoInfo info, char nome[50]);

#include "abp.h"
#include "avl.h"

#endif
