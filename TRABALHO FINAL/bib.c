#include "bib.h"


// funcoes ARVORES *******************************************************************************************************

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

pNodoA *pesquisaPadrao(pNodoA *a, char comida[STRING_SIZE], int *comp){
    if(a){
        int comparacao = comparaAlimento(a->nodoInfo, comida);
        int temp = *comp;
        temp++;
        *comp = temp;
        if (comparacao == 0){
            return a;
        }else if (comparacao == -1){
            return pesquisaPadrao(a->dir, comida, comp);
        }
        else if(comparacao == 1){
            return pesquisaPadrao(a->esq, comida, comp);
        }
    }
    return NULL;
}

pNodoA *pesquisaSelecionada(pNodoA *a, char comida[STRING_SIZE], int *comp){
    char primeiraLetra = comida[0];

    if (toupper(primeiraLetra) <= 'M'){
        printf("Escolhendo comecar pela letra A\n");
        return pesquisaCrescente(a,comida,comp);
    }else{
        printf("Escolhendo comecar pela letra Z\n");
        return pesquisaDecrescente(a,comida,comp);
    }
}

pNodoA *guardar;
int achei = 0;
pNodoA *pesquisaCrescente(pNodoA *a, char comida[STRING_SIZE], int *comp){
    achei = 0;
    if(a){
        pesquisaCrescente(a->esq,comida,comp);

        if (!achei){
            //printf("%p\n",a);
            //printf("comidaInfo: %s\n",a->nodoInfo.alimento);
            //printf("comida: %s\n",comida);
            int comparacao = comparaAlimento(a->nodoInfo, comida);
            //printf("comparacao: %d\n",comparacao);
            int temp = *comp;
            temp++;
            *comp = temp;
            if(comparacao == 0){
                //printf("achei, amigos! %p\n\n",a);
                guardar = a;
                achei = 1;
            }
            //printf("\n");
        }

        if (!achei){
            pesquisaCrescente(a->dir,comida,comp);
        }

        return guardar;
    }
    return NULL;
}

pNodoA *pesquisaDecrescente(pNodoA *a, char comida[STRING_SIZE], int *comp){
    achei = 0;
    if(a){
        pesquisaDecrescente(a->dir,comida,comp);

        if (!achei){
            //printf("%p\n",a);
            //printf("comidaInfo: %s\n",a->nodoInfo.alimento);
            //printf("comida: %s\n",comida);
            int comparacao = comparaAlimento(a->nodoInfo, comida);
            //printf("comparacao: %d\n",comparacao);
            int temp = *comp;
            temp++;
            *comp = temp;
            if(comparacao == 0){
                //printf("achei, amigos! %p\n\n",a);
                guardar = a;
                achei = 1;
            }
            //printf("\n");
        }

        if (!achei){
            pesquisaDecrescente(a->esq,comida,comp);
        }

        return guardar;
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

// funcoes ARQUIVOS *******************************************************************************************************


