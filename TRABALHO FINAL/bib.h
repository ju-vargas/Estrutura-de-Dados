#ifndef BIB_H
#define BIB_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define STRING_SIZE 50

#define TRUE 1
#define FALSE 0

//ESTRUTURAS **************************************************************************************************************
//struct info (campo info do NODO)
typedef struct tipoInfo{
    int calorias;
    char alimento[STRING_SIZE];
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
void centralE(pNodoA *a); 

#include "abp.h"
#include "avl.h"

#endif
