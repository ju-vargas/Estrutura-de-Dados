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

    if (toupper(primeiraLetra) == 'A'){
        printf("Escolhendo comecar pela letra A\n");
        return pesquisaCentralE(a,comida,comp);
    }else if (toupper(primeiraLetra) == 'Z'){
        printf("Escolhendo comecar pela letra Z\n");
        return pesquisaCentralD(a,comida,comp);
    }else{
        printf("Escolhendo pesquisa padrao\n");
        return pesquisaPadrao(a,comida,comp);
    }
}

pNodoA *guardar;
int achei = 0;
pNodoA *pesquisaCentralE(pNodoA *a, char comida[STRING_SIZE], int *comp){
    achei = 0;
    if(a){
        pesquisaCentralE(a->esq,comida,comp);

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
            pesquisaCentralE(a->dir,comida,comp);
        }

        return guardar;
    }
    return NULL;
}

pNodoA *pesquisaCentralD(pNodoA *a, char comida[STRING_SIZE], int *comp){
    achei = 0;
    if(a){
        pesquisaCentralD(a->dir,comida,comp);

        if (!achei){
            int comparacao = comparaAlimento(a->nodoInfo, comida);
            int temp = *comp;
            temp++;
            *comp = temp;
            if(comparacao == 0){
                guardar = a;
                achei = 1;
            }
        }

        if (!achei){
            pesquisaCentralD(a->esq,comida,comp);
        }

        return guardar;
    }
    return NULL;
}

pNodoA *pesquisaPreFixadoD(pNodoA *a, char comida[STRING_SIZE], int *comp){
    achei = 0;
    if(a){
        if (!achei){
            int comparacao = comparaAlimento(a->nodoInfo, comida);
            int temp = *comp;
            temp++;
            *comp = temp;
            if(comparacao == 0){
                guardar = a;
                achei = 1;
            }
        }

        if (!achei){
            pesquisaPreFixadoD(a->dir,comida,comp);
        }

        if (!achei){
            pesquisaPreFixadoD(a->esq,comida,comp);
        }

        return guardar;
    }
    return NULL;
}

pNodoA *pesquisaPreFixadoE(pNodoA *a, char comida[STRING_SIZE], int *comp){
    achei = 0;
    if(a){
        if (!achei){
            int comparacao = comparaAlimento(a->nodoInfo, comida);
            int temp = *comp;
            temp++;
            *comp = temp;
            if(comparacao == 0){
                guardar = a;
                achei = 1;
            }
        }

        if (!achei){
            pesquisaPreFixadoE(a->esq,comida,comp);
        }

        if (!achei){
            pesquisaPreFixadoE(a->dir,comida,comp);
        }

        return guardar;
    }
    return NULL;
}

pNodoA *pesquisaPosFixadoE(pNodoA *a, char comida[STRING_SIZE], int *comp){
    achei = 0;
    if(a){
        pesquisaPosFixadoE(a->esq,comida,comp);
        pesquisaPosFixadoE(a->dir,comida,comp);
        if (!achei){
            int comparacao = comparaAlimento(a->nodoInfo, comida);
            int temp = *comp;
            temp++;
            *comp = temp;
            if(comparacao == 0){
                guardar = a;
                achei = 1;
            }
        }
        return guardar;
    }
    return NULL;
}

pNodoA *pesquisaPosFixadoD(pNodoA *a, char comida[STRING_SIZE], int *comp){
    achei = 0;
    if(a){
        pesquisaPosFixadoD(a->dir,comida,comp);
        pesquisaPosFixadoD(a->esq,comida,comp);
        if (!achei){
            int comparacao = comparaAlimento(a->nodoInfo, comida);
            int temp = *comp;
            temp++;
            *comp = temp;
            if(comparacao == 0){
                guardar = a;
                achei = 1;
            }
        }
        return guardar;
    }
    return NULL;
}


void preFixadoE(pNodoA *a){
    if (a){
        printf("Calorias: %d | Alimento: %s\n",a->nodoInfo.calorias,a->nodoInfo.alimento);
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


