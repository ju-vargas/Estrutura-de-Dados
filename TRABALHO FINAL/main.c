#include "bib.h"

int main(void){

//VARIAVEIS *********************************************************************************************************
    int ok; 
    int compara = 0;
    int nroNodos = 0; 

    pNodoA *arv;
    pNodoAVL *arvAVL; 
    arv = NULL;
    arvAVL = NULL; 
 
/*
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
*/

//LEITURA DE ARQUIVOS **************************************************************************************************
    
    //essas variaveis guardam o nome dos arquivos
    //se receber o nome do terminal, vou usar elas pra conseguir selecionar o arquivo
    char nomeArqCalorias[50] = "tables/1000Shuffled.csv"; 
    char nomeArqPaciente[50] = "tables/day1.csv"; 


    FILE *arqCalorias = fopen(nomeArqCalorias, "r");

    //preenchendo arvore ABP
    if (arqCalorias != NULL) {
        arv = preencheABP(arqCalorias, arv, &nroNodos);
    }

    rewind (arqCalorias); 

    //preenchendo arvore AVL
    if (arqCalorias != NULL) {
        arvAVL = preencheAVL(arqCalorias, arvAVL, &ok);
    }

    fclose (arqCalorias); 

//espaço para ABP ******************************************************************************************************* 
   
    //arv = insere(arv,a5);
    //arv = insere(arv,a4);
    //arv = insere(arv,a3);
    //arv = insere(arv,a2);
    //arv = insere(arv,a1);

    printf("Em ordem crescente...\n");
    centralE(arv);
    printf ("\n"); 


//espaço para AVL *******************************************************************************************************
  
    //arvAVL = insereArvoreAVL(arvAVL,a5);
    //arvAVL = insereAVL(arvAVL,a4, &ok);
    //arvAVL = insereAVL(arvAVL,a3, &ok);
    //arvAVL = insereAVL(arvAVL,a2, &ok);
    //arvAVL = insereAVL(arvAVL,a1, &ok);
    
    //o desenha desenha em qual ordem?
   // printf ("Desenho AVL\n"); 
    //desenha(arvAVL, 1); 
    //printf ("\n");

//***********************************************************************************************************************

    char comidaAchar[STRING_SIZE] = {"estrogonofe"};
    printf("Pesquisando por '%s'...\n",comidaAchar);

    pNodoA *nodoAchado;
    nodoAchado = NULL;

    int comparacoes = 0;

    //nodoAchado = pesquisa(arv,comidaAchar,&comparacoes);
    nodoAchado = pesquisaPadrao(arv,comidaAchar,&comparacoes);

    if (nodoAchado){
        printf("Acheeeeei!\n");
        printf("Calorias: %d | Alimento: %s\n",nodoAchado->nodoInfo.calorias,nodoAchado->nodoInfo.alimento);
    }
    else{
        printf("Nodo nao achado :(\n");
    }

    printf("Realizei %d comparacoes.\n",comparacoes);


    /*strcpy(comidaAchar,"arroz");
    comparacoes = 0;
    nodoAchado = pesquisaDecrescente(arv,comidaAchar,&comparacoes);

    if (nodoAchado){
        printf("Acheeeeei!\n");
        printf("Calorias: %d | Alimento: %s\n",nodoAchado->nodoInfo.calorias,nodoAchado->nodoInfo.alimento);
    }
    else{
        printf("Nodo nao achado :(\n");
    }

    printf("Realizei %d comparacoes.\n",comparacoes);*/


    printf ("numero de nodos eh: %i", nroNodos);
    return 0;
}
