#include "abp.h"

pNodoA *insere (pNodoA *arv, tipoInfo info){
    if (arv == NULL){
        arv = (pNodoA*) malloc(sizeof(arv));
        strcpy(arv->nodoInfo.alimento,info.alimento);
        arv->nodoInfo.calorias = info.calorias;

        arv->esq = NULL;
        arv->dir = NULL;

        return arv;
    } else {
        if (arv->nodoInfo.alimento > info.alimento)
            arv->dir = insere (arv->dir, info);
        else
            arv->esq = insere (arv->esq, info);
    }

    return arv;
}

void preFixadoE(pNodoA *a){
    if (a){
        printf("Calorias: %d | Alimento: %s - ",a->nodoInfo.calorias,a->nodoInfo.alimento);
        preFixadoE(a->esq);
        preFixadoE(a->dir);
    }
}


