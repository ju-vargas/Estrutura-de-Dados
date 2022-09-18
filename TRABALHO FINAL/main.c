#include "bib.h"

int main(void){
    pNodoA *arv;
    arv = NULL;
    int compara = 0;

    tipoInfo a2;
    strcpy(a2.alimento,"comida legal");
    a2.calorias = 200;

    tipoInfo a3;
    strcpy(a3.alimento,"comida ilegal");
    a3.calorias = 100;

    tipoInfo a4;
    strcpy(a4.alimento,"comida ilegal");
    a4.calorias = 50;

    arv = insere(arv,a2);
    //arv = insere(arv,a3);
    //arv = insere(arv,a4);

    //aqui, estou chamando a funcao apenas para testá-la
    compara = comparaAlimento (a2, "co");
    printf ("o valor eh: %i\n", compara);


    preFixadoE(arv);

    


    return 0;
}
