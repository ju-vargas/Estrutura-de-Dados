#include "abp.h"
#include "bib.h"

pNodoA *insere (pNodoA *arv, tipoInfo info){
    if (arv == NULL){
        arv = (pNodoA*) malloc(sizeof(pNodoA));
        memcpy(&arv->nodoInfo,&info,sizeof(arv->nodoInfo));
        arv->esq = NULL;
        arv->dir = NULL;
        return arv;
    } else {
        int comparacao = comparaAlimento(arv->nodoInfo,info.alimento);
        if (comparacao == -1){
            arv->dir = insere (arv->dir, info);
        }
        else if(comparacao == 1){
            arv->esq = insere (arv->esq, info);
        }
    }

    return arv;
}

