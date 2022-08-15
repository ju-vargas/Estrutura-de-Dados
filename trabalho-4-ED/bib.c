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

ptArvore* Espelha (ptArvore a) {

    ptArvore *b = NULL;

    if (a!= NULL) {
        
    }

    return b; 
}
 

void Desenha(ptArvore *a) {
    if (a!= NULL) {
        printf ("%i - ", a->info);
        Desenha (a->esq);
        Desenha (a->dir);
   }
}

