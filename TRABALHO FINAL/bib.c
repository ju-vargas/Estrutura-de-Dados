#include "bib.h"

//funcao que compara o campo nome de um alimento com a palavra procurada
//entrada: struct info do nodo, e palavra que quero comparar
//saida: 1 quando palavra nodo > palavra, 0 para iguais, -1 para menor
int comparaAlimento (tipoInfo info, char nome[50]) {
    int compara = 0;
    compara = strcmp (info.alimento, nome);
    return compara; 
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