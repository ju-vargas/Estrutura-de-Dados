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


//funcao que compara o campo nome de um alimento com a palavra procurada
//entrada: struct info do nodo, e palavra que quero comparar
//saida: 1 quando palavra nodo > palavra, 0 para iguais, -1 para menor
int comparaAlimento (tipoInfo info, char nome[STRING_SIZE]) {
    //compara = strcmp (info.alimento, nome);
    int i;
    char infoNodoUpper[STRING_SIZE];
    char nomeUpper[STRING_SIZE];

    strcpy(infoNodoUpper,info.alimento);
    strcpy(nomeUpper,nome);

    for(i=0; infoNodoUpper[i]!='\0'; i++){
        if(infoNodoUpper[i]>='a' && infoNodoUpper[i]<='z'){
            infoNodoUpper[i] = infoNodoUpper[i] - 32;
        }
    }

    for(i=0; nomeUpper[i]!='\0'; i++){
        if(nomeUpper[i]>='a' && nomeUpper[i]<='z'){
            nomeUpper[i] = nomeUpper[i] - 32;
        }
    }

    return strcmp(infoNodoUpper, nomeUpper);
}

pNodoA *pesquisa(pNodoA *a, char comida[STRING_SIZE]){
    if(a){
        int comparacao = comparaAlimento(a->nodoInfo, comida);
        if (comparacao == 0){
            return a;
        }else if (comparacao == -1){
            return pesquisa(a->dir, comida);
        }
        else if(comparacao == 1){
            return pesquisa(a->esq, comida);
        }
    }
    return NULL;
}
