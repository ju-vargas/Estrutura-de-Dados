#include "bib.h"



int main(void) {
    
    int continuar = TRUE;
    int iguais = TRUE;
    int raiz = TRUE; 
    int deBusca = TRUE; 
      
    ptArvore *ptA, *arv1, *arv2, *arvEspelho;

    ptA = arv1 = arv2 = arvEspelho = NULL; 

    arv1 = InsereArvore(arv1,10);
    arv1 = InsereArvore(arv1,45);
   //arv1 = InsereArvore(arv1,22);
    arv1 = InsereArvore(arv1,25);
    arv1 = InsereArvore(arv1,70);
    arv1 = InsereArvore(arv1,80);
    arv1 = InsereArvore(arv1,95);

    arv2 = InsereArvore(arv2,10);
    arv2 = InsereArvore(arv2,45);
    arv2 = InsereArvore(arv2,25);
    //arv2 = InsereArvore(arv2,22);
    arv2 = InsereArvore(arv2,70);
    arv2 = InsereArvore(arv2,80);
    arv2 = InsereArvore(arv2,95);
    



    Desenha (arv1); 
    printf ("\n");
    Desenha (arv2); 
    Compara (arv1, arv2, &iguais);


    if (iguais)
        printf ("\nAs duas arvores sao iguais\n"); 
    else 
        printf ("\nAs duas arvores NAO sao iguais\n"); 


    arvEspelho = Espelha (arv1, arvEspelho); 

    printf ("Arvore original: "); 
    CentralE (arv1); 
    printf ("\n"); 

    printf ("Arvore espelho: ");
    CentralE(arvEspelho); 
    printf ("\n"); 

    VerificaABP (arv1, arv1->info, arv1->info, &deBusca);

    if(deBusca == 1)
        printf ("Eh arvore binaria de busca!\n");
    else
        printf ("NAO eh arvore binaria de busca\n!");



    return 0;
    
    
}