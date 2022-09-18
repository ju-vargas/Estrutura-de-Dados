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

typedef struct tipoInfo{
    int calorias;
    char alimento[STRING_SIZE];
}tipoInfo;

struct TNodoA{
        tipoInfo nodoInfo;
        struct TNodoA *esq;
        struct TNodoA *dir;
};

typedef struct TNodoA pNodoA;

#include "abp.h"
#include "avl.h"

#endif
