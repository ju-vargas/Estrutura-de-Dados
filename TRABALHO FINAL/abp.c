#include "abp.h"
#include "bib.h"

pNodoA *insereABP (pNodoA *arv, tipoInfo info){
    if (arv == NULL){
        arv = (pNodoA*) malloc(sizeof(pNodoA));
        memcpy(&arv->nodoInfo,&info,sizeof(arv->nodoInfo));
        arv->esq = NULL;
        arv->dir = NULL;
        return arv;
    } else {
        int comparacao = comparaAlimento(arv->nodoInfo,info.alimento);
        if (comparacao < 0){
            arv->dir = insereABP(arv->dir, info);
        }
        else if(comparacao > 0){
            arv->esq = insereABP(arv->esq, info);
        }
    }

    return arv;
}

int alturaABP (pNodoA *a) {
   int altEsq, altDir;

   if (a == NULL)
      return 0;

   else {
      altEsq = alturaABP (a->esq);
      altDir = alturaABP (a->dir);

      if (altEsq > altDir)
         return (1 + altEsq);
      else
         return (1 + altDir);
     }
}

// funcoes ARQUIVOS *******************************************************************************************************
pNodoA * preencheABP(FILE *arqCalorias, pNodoA *arv, int *nroNodos) {
    char nomeAlimento[STRING_SIZE];

    int calorias = 0;
    tipoInfo infoAux;

    while (fscanf(arqCalorias, "%[^;];%d\n", nomeAlimento, &calorias) == 2) {     //codigo baseado no stack overflow p/ como ler de dois em dois
        strcpy(infoAux.alimento, nomeAlimento);
        infoAux.calorias = calorias;

        arv = insereABP(arv, infoAux);
        (*nroNodos)++;
    }

    return arv;
}

pNodoA *pesquisaPadrao(pNodoA *a, char comida[STRING_SIZE], int *comp){
    if(a){
        int comparacao = comparaAlimento(a->nodoInfo, comida);
        (*comp)++;
        if (comparacao == 0)
            return a;

        else if (comparacao == -1)
            return pesquisaPadrao(a->dir, comida, comp);

        else if(comparacao == 1)
            return pesquisaPadrao(a->esq, comida, comp);

    }
    return NULL;
}

pNodoA *pesquisaSelecionada(pNodoA *a, char comida[STRING_SIZE], int *comp){
    char primeiraLetra = comida[0];

    if (toupper(primeiraLetra) == 'A'){
        //printf("Escolhendo comecar pela letra A\n");
        return pesquisaCentralE(a,comida,comp);
    }else if (toupper(primeiraLetra) == 'Z'){
        //printf("Escolhendo comecar pela letra Z\n");
        return pesquisaCentralD(a,comida,comp);
    }else{
        //printf("Escolhendo pesquisa padrao\n");
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
            (*comp)++;
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
            (*comp)++;
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
            (*comp)++;
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
            (*comp)++;
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
            (*comp)++;
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
            (*comp)++;
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
