#include "bib.h"

ptArvore* InsereArvore(ptArvore *a, tipoinfo ch) {

    if (a == NULL) {
        a = (ptArvore*) malloc(sizeof(ptArvore));
        a->info = ch;
        a->esq = NULL;
        a->dir = NULL;
    }

    else {
        if (ch < (a->info))
            a->esq = InsereArvore(a->esq,ch);
        else
            a->dir = InsereArvore(a->dir,ch);
    }

    return a;
}

ptArvore* InsereArvoreInvertido(ptArvore *a, tipoinfo ch) {

    if (a == NULL) {
        a = (ptArvore*) malloc(sizeof(ptArvore));
        a->info = ch;
        a->esq = NULL;
        a->dir = NULL;
    }

    else {
        if (ch > (a->info))
            a->esq = InsereArvoreInvertido(a->esq,ch);
        else
            a->dir = InsereArvoreInvertido(a->dir,ch);
    }

    return a;
}

int Compara (ptArvore *a, ptArvore *b, int *iguais) {
    if (a != NULL ) {
        if (b != NULL) {
            if (a->info != b->info) {
                *iguais = FALSE;
            }
                
            else {
                Compara (a->esq, b->esq, iguais); 
                Compara (a->dir, b->dir, iguais);
            }
        } 
    }
    
    return *iguais; 
}


//pre fixado a esquerda
void Desenha(ptArvore *a) {
    if (a!= NULL) {
        printf ("%i - ", a->info);
        Desenha (a->esq);
        Desenha (a->dir);
   }
}

//desenho por centro esquerda
void CentralE(ptArvore *a) {
     if (a!= NULL) {
            CentralE(a->esq);
            printf("%d - ",a->info);
            CentralE(a->dir);
      }
}

ptArvore* Espelha (ptArvore *a, ptArvore *b) {
    if (a != NULL ) {
        b = InsereArvoreInvertido (b, a->info);
            Espelha (a->dir, b);
            Espelha (a->esq, b);    
    }
    return b; 
}

int VerificaABP(ptArvore *a,int ant, int atual, int *deBusca) {
    if (a!= NULL) {
            VerificaABP(a->esq,ant,atual,deBusca);
            atual = a->info;
            if (atual < ant)
                *deBusca = FALSE;
            ant = atual;          
            VerificaABP(a->dir,ant,atual, deBusca);
    }

    return *deBusca;
}


