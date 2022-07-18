#ifndef BIB_H
#define BIB_H

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>



typedef struct tipoNo ptLSE;

struct tipoNo{
 int numero;
 ptLSE *prox;
};



#endif