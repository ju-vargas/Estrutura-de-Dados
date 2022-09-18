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

void centralE(pNodoA *a){
    if (a){
        centralE(a->esq);
        printf("Calorias: %d | Alimento: %s\n",a->nodoInfo.calorias,a->nodoInfo.alimento);
        centralE(a->dir);
    }
}

//funcao que compara o campo nome de um alimento com a palavra procurada
//entrada: struct info do nodo, e palavra que quero comparar
//saida: 1 quando palavra nodo > palavra, 0 para iguais, -1 para menor
int comparaAlimento (tipoInfo info, char nome[STRING_SIZE]) {
    int compara = 0;

    compara = strcmp (info.alimento, nome);

    return compara;
}
