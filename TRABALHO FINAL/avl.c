#include "avl.h"
#include "bib.h"

/*
como implementar AVL?
   1. criar structs (na TAD) ok
   2. criar insere árvore ok
   3. saber calcular altura
*/

// INSERÇAO ******************************************************************************************************************
// base retirada dos exemplos no Moodle da disciplina

pNodoAVL* insereArvoreAVL(pNodoAVL * a, tipoInfo info) {

    if (a == NULL) {
        //alocando espaço para o nodo, dando um endereço a ele
        a = (pNodoAVL*) malloc(sizeof(pNodoAVL));
        memcpy(&a->nodoInfo,&info,sizeof(a->nodoInfo));
        a->esq = NULL;
        a->dir = NULL;
        // o nodo eh sempre inserido como folha entao seu fator de balanceamento eh 0
        a->FB = 0;
    }

    else {
        // caso a info adicionada seja MENOR QUE seu pai
        if (comparaAlimento(info, a->nodoInfo.alimento) < 0)
            a->esq = insereArvoreAVL(a->esq, info);
        else
        // caso a info adicionada seja MAIOR QUE seu pai
            if (comparaAlimento(info, a->nodoInfo.alimento) > 0)
                a->dir = insereArvoreAVL(a->dir, info);
    }

    return a;
}


// Insere nodo em uma arvore AVL
// a eh a raiz, x eh  a chave a ser inserida, h eh a altura da arvore
pNodoAVL* insereAVL (pNodoAVL *a, tipoInfo x, int *ok, int *rotacoes) {
    if (a == NULL) {
        a = (pNodoAVL*) malloc(sizeof(pNodoAVL));

        strcpy (a->nodoInfo.alimento, x.alimento);
        a->nodoInfo.calorias = x.calorias;

        a->esq = NULL;
        a->dir = NULL;
        a->FB = 0;
        *ok = 1;
    }

    else {
        // caso a info adicionada seja MENOR QUE seu pai
        if (comparaAlimento(x, a->nodoInfo.alimento) < 0) {
            a->esq = insereAVL(a->esq,x,ok,rotacoes);
            if (*ok) {
                switch (a->FB) {
                    case -1:
                        a->FB = 0;
                        *ok = 0;
                        break;

                    case  0:
                        a->FB = 1;
                        break;

                    case  1:
                        (*rotacoes)++;
                        a = Caso1(a,ok);
                        break;
                }
            }
        }
        // caso a info adicionada seja MAIOR  QUE seu pai
        else if (comparaAlimento(x, a->nodoInfo.alimento) > 0) {
            a->dir = insereAVL(a->dir,x,ok,rotacoes);
            if (*ok) {
                switch (a->FB) {
                    case  1:
                        a->FB = 0;
                        *ok = 0;
                        break;

                    case  0:
                        a->FB = -1;
                        break;

                    case -1:
                        (*rotacoes)++;
                        a = Caso2(a,ok);
                        break;
                }
            }
        }
    }
    return a;
}

pNodoAVL *pesquisaPadraoAVL(pNodoAVL *a, char comida[STRING_SIZE], int *comp){
    if(a){
        int comparacao = comparaAlimento(a->nodoInfo, comida);
        (*comp)++;

        if (comparacao == 0)
            return a;

        else if (comparacao == -1)
            return pesquisaPadraoAVL(a->dir, comida, comp);

        else if(comparacao == 1)
            return pesquisaPadraoAVL(a->esq, comida, comp);

    }
    return NULL;
}

// FUNÇOES *********************************************************************************************************************
// base retirada dos exemplos no Moodle da disciplina

// recebo o endereço do nodo e vejo sua altura
int alturaAVL (pNodoAVL *a) {
    int altEsq, altDir;
    if (a == NULL)
        return 0;

    else {
        altEsq = alturaAVL (a->esq);
        altDir = alturaAVL (a->dir);

        if (altEsq > altDir)
            return (1 + altEsq);
        else
            return (1 + altDir);
    }
}

// para calcular fator de balanceamento
int calculaFB(pNodoAVL *a) {
    return (alturaAVL(a->esq) - alturaAVL(a->dir));
}

// funcao para desenhar a árvore
void desenha(pNodoAVL *a , int nivel) {
    int x;
    if (a !=NULL) {
        for (x=1; x<=nivel; x++)
        printf("=");
        printf("%s FB= %d\n", a->nodoInfo.alimento, calculaFB(a));

        if (a->esq != NULL)
            desenha(a->esq, (nivel+1));
        if (a->dir != NULL)
            desenha(a->dir, (nivel+1));
    }
}

// funcao que verifica se eh AVL
int is_avl(pNodoAVL *a) {
    int altEsq, altDir;

    if (a!=NULL) {
        altEsq = alturaAVL(a->esq);
        altDir = alturaAVL(a->dir);
        return ( (altEsq - altDir <2) && (altDir - altEsq <2) && (is_avl(a->esq)) && (is_avl(a->dir)) );
    }
    else
        return 1;
}


// ROTAÇÕES ******************************************************************************************************************
// base retirada dos exemplos no Moodle da disciplina
pNodoAVL* rotacaoDireita(pNodoAVL *pt){
    pNodoAVL* ptu;

    ptu = pt->esq;
    pt->esq = ptu->dir;
    ptu->dir = pt;
    pt->FB = 0;
    pt = ptu;
    return pt;
}

pNodoAVL* rotacaoEsquerda(pNodoAVL *pt){
    pNodoAVL* ptu;

    ptu = pt->dir;
    pt->dir = ptu->esq;
    ptu->esq = pt;
    pt->FB = 0;
    pt = ptu;
    return pt;
}

pNodoAVL* rotacaoDuplaDireita (pNodoAVL* pt){
    pNodoAVL *ptu, *ptv;

    ptu = pt->esq;
    ptv = ptu->dir;
    ptu->dir = ptv->esq;
    ptv->esq = ptu;
    pt->esq = ptv->dir;
    ptv->dir = pt;

    if (ptv->FB == 1)
        pt->FB = -1;
    else
        pt->FB = 0;

    if (ptv->FB == -1)
        ptu->FB = 1;
    else
        ptu->FB = 0;

    pt = ptv;
    return pt;
}

pNodoAVL* rotacaoDuplaEsquerda (pNodoAVL* pt){
    pNodoAVL *ptu, *ptv;

    ptu = pt->dir;
    ptv = ptu->esq;
    ptu->esq = ptv->dir;
    ptv->dir = ptu;
    pt->dir = ptv->esq;
    ptv->esq = pt;

    if (ptv->FB == -1)
        pt->FB = 1;
    else
        pt->FB = 0;

    if (ptv->FB == 1)
        ptu->FB = -1;
    else
        ptu->FB = 0;

    pt = ptv;
   return pt;
}


// CASOS **********************************************************************************************************************
// base retirada dos exemplos no Moodle da disciplina
pNodoAVL* Caso1 (pNodoAVL* a , int *ok) {
    pNodoAVL *ptu;

    ptu = a->esq;
    if (ptu->FB == 1){
        // printf("fazendo rotacao direita em %s\n",a->nodoInfo.alimento);
        a = rotacaoDireita(a);
    }
    else{
        //printf("fazendo rotacao dupla direita em %s\n",a->nodoInfo.alimento);
        a = rotacaoDuplaDireita(a);
    }
    a->FB = 0;
    *ok = 0;
    return a;
}

pNodoAVL* Caso2 (pNodoAVL *a , int *ok) {
    pNodoAVL *ptu;

    ptu = a->dir;
    if (ptu->FB == -1) {
        //desenha(a,1);
        //printf("fazendo rotacao esquerda em %s\n",a->nodoInfo.alimento);
        a = rotacaoEsquerda(a);
    }

    else {
        //desenha(a,1);
        //printf("fazendo rotacao dupla esquerda em %s\n",a->nodoInfo.alimento);
        a = rotacaoDuplaEsquerda(a);
    }

    a->FB = 0;
    *ok = 0;
    return a;
}

// funcoes ARQUIVOS *******************************************************************************************************
pNodoAVL * preencheAVL(FILE *arqCalorias, pNodoAVL *arvAVL, int *ok, int *rotacoes) {
    char nomeAlimento[STRING_SIZE];
    int calorias = 0;
    tipoInfo infoAux;
    int primeiro = TRUE;

    while (fscanf(arqCalorias, "%[^;];%d\n", nomeAlimento, &calorias) == 2) {    //codigo baseado no stack overflow p/ como ler de dois em dois
        if (primeiro) {
            arvAVL = insereArvoreAVL (arvAVL, infoAux);
            primeiro = FALSE;
        }
        else{
            strcpy (infoAux.alimento, nomeAlimento);
            infoAux.calorias = calorias;
            arvAVL = insereAVL(arvAVL, infoAux, ok, rotacoes);
        }
    }

    return arvAVL;
}









