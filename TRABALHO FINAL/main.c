#include "bib.h"

int main(void){
    pNodoA *arv;
    arv = NULL;
    int compara = 0;

    tipoInfo a1 = {0};
    strcpy(a1.alimento,"arroz");
    a1.calorias = 100;

    tipoInfo a2 = {0};
    strcpy(a2.alimento,"batata");
    a2.calorias = 200;

    tipoInfo a3 = {0};
    strcpy(a3.alimento,"carambola");
    a3.calorias = 300;

    tipoInfo a4 = {0};
    strcpy(a4.alimento,"estrogonofe");
    a4.calorias = 400;

    tipoInfo a5 = {0};
    strcpy(a5.alimento,"zizania");
    a5.calorias = 500;

    arv = insere(arv,a5);
    arv = insere(arv,a4);
    arv = insere(arv,a3);
    arv = insere(arv,a2);
    arv = insere(arv,a1);

    printf("Em ordem crescente...\n");
    centralE(arv);

    char comidaAchar[STRING_SIZE] = {"zizaniA"};
    printf("Pesquisando por '%s'...\n",comidaAchar);

    pNodoA *nodoAchado;
    nodoAchado = NULL;
    nodoAchado = pesquisa(arv,comidaAchar);
    if (nodoAchado){
        printf("Acheeeeei!\n");
        printf("Calorias: %d | Alimento: %s\n",nodoAchado->nodoInfo.calorias,nodoAchado->nodoInfo.alimento);
    }else{
        printf("Nodo nao achado :(\n");
    }
    return 0;
}
