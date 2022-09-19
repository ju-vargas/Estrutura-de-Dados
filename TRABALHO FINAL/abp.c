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

// funcoes ARQUIVOS *******************************************************************************************************
pNodoA * preencheABP(FILE *arqCalorias, pNodoA *arv, int *nroNodos) {
    char nomeAlimento[STRING_SIZE];
    int calorias = 0;
    tipoInfo infoAux;

    while (fscanf(arqCalorias, "%[^;];%d\n", nomeAlimento, &calorias) == 2) {     //codigo baseado no stack overflow p/ como ler de dois em dois
        strcpy(infoAux.alimento, nomeAlimento);
        infoAux.calorias = calorias;

        arv = insere (arv, infoAux);
        (*nroNodos)++;
    }

    return arv;
}
