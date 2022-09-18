#include "bib.h"

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



void preFixadoE(pNodoA *a){
    if (a){
        printf("Calorias: %d | Alimento: %s - ",a->nodoInfo.calorias,a->nodoInfo.alimento);
        preFixadoE(a->esq);
        preFixadoE(a->dir);
    }
}

void centralE(pNodoA *a){
    if (a){
        centralE(a->esq);
        printf("Calorias: %d | Alimento: %s\n",a->nodoInfo.calorias,a->nodoInfo.alimento);
        centralE(a->dir);
    }
}