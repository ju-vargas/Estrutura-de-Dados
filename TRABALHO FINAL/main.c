#include "bib.h"

int main(void){
    pNodoA *arv;
    arv = NULL;

    tipoInfo a2;
    strcpy(a2.alimento,"comida legal");
    a2.calorias = 200;

    arv = insere(arv,a2);

    preFixadoE(arv);

    return 0;
}
