#ifndef BIB_H
#define BIB_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct tipoInfo{
    int calorias;
    char alimento[50];
}tipoInfo;

struct TNodoA{
        tipoInfo nodoInfo;
        struct TNodoA *esq;
        struct TNodoA *dir;
};

typedef struct TNodoA pNodoA;

//#include "abp.h"
//#include "avl.h"

pNodoA *insere(pNodoA *a, tipoInfo ch);
void preFixadoE(pNodoA *a);



#define TRUE 1
#define FALSE 0

#endif
