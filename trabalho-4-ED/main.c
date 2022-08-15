#include "bib.c"



int main(void) {

    
    int continuar = TRUE;
    int iguais = 1;
    

    ptArvore *ptA, *arv1, *arv2;
    ptA = arv1 = arv2 = NULL; 
/*
    int chave = 0; 
    int aux = 0; 


    while (continuar == TRUE) {
        printf ("Insira o valor: "); 
        scanf ("%i", &chave);
        InsereArvore (ptA, chave); 

        printf ("Deseja continuar inserindo? 1-SIM; 2-NAO");
        scanf ("%i", &continuar);

    }
*/


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
        printf ("\nAs duas arvores sao iguais"); 
    else 
        printf ("\nAs duas arvores NAO sao iguais"); 



    return 0;
    
    
}