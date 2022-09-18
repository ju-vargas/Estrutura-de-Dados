#include "abp.h"
#include "bib.h"

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

//funcao que compara o campo nome de um alimento com a palavra procurada
//entrada: struct info do nodo, e palavra que quero comparar
//saida: 1 quando palavra nodo > palavra, 0 para iguais, -1 para menor
int comparaAlimento (tipoInfo info, char nome[50]) {
    int compara = 0;

    compara = strcmp (info.alimento, nome);

    return compara; 
}
