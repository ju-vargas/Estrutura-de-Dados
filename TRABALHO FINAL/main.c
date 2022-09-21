#include "bib.h"

int main(void){

//VARIAVEIS *********************************************************************************************************
    int ok;
    int compara = 0;
    int nroNodos = 0;
    int comparacoes = 0;
    int rotacoes = 0;


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

//LEITURA DE ARQUIVO CALORIAS ******************************************************************************************

    //essas variaveis guardam o nome dos arquivos
    //se receber o nome do terminal, vou usar elas pra conseguir selecionar o arquivo
    char nomeArqCalorias[50] = "../tables/1000Shuffled.csv";
    char nomeArqPaciente[50] = "../tables/day1.csv";
    char nomeArqSaida[50] = "../tables/Saida_day1.bin";


    FILE *arqCalorias = fopen(nomeArqCalorias, "r");

    //preenchendo arvore ABP
    if (arqCalorias != NULL) {
        arv = preencheABP(arqCalorias, arv, &nroNodos);
    }else{
        perror("arqCalorias");
    }

    rewind (arqCalorias);

    //preenchendo arvore AVL
    if (arqCalorias != NULL) {
        arvAVL = preencheAVL(arqCalorias, arvAVL, &ok, &rotacoes);
    }else{
        perror("arqCalorias");
    }

    fclose (arqCalorias);

//LEITURA DE ARQUIVO CALORIAS ******************************************************************************************
//criar função aqui?
    //le arquivo do paciente um de cada vez
    //pesquisa na árvore
    //escreve e fecha

    char alimentoPaciente[STRING_SIZE];
    int gramasAlimento = 0;
    int caloriasAlimento= 0;
    int caloriasCalculada = 0;
    int caloriasTotal = 0;

    pNodoA * auxCalorias;
    auxCalorias = NULL;

    FILE *arqPaciente = fopen(nomeArqPaciente, "r");
    FILE *arqSaida = fopen(nomeArqSaida, "wb+");

    if (!arqPaciente){
        perror("arqPaciente");
    }else if (!arqSaida){
        perror("arqSaida");
    }else {
        fprintf (arqSaida, "Calorias calculadas para %s usando a tabela %s.\n\n", nomeArqPaciente, nomeArqCalorias);

        while (fscanf(arqPaciente, "%[^;];%d\n", alimentoPaciente, &gramasAlimento) == 2) {    //codigo baseado no stack overflow p/ como ler de dois em dois
            //qual pesquisa usar aqui, qual arvore?
            //por enquanto tem para ABP, fazer partes para outras pesquisas!!!

            //fazer funcao para calcula calorias
            auxCalorias = pesquisaPadrao(arv,alimentoPaciente,&comparacoes);
            if (auxCalorias != NULL){
                caloriasAlimento = auxCalorias->nodoInfo.calorias;
                caloriasCalculada = (caloriasAlimento*gramasAlimento)/100;
                caloriasTotal += caloriasCalculada;
                fprintf (arqSaida, "%ig de %s (%i calorias por 100g) = %i calorias\n", gramasAlimento, alimentoPaciente, caloriasAlimento, caloriasCalculada);
            }
            else
                fprintf (arqSaida, "As calorias de %s não estão contabilizadas\n");
        }
            fprintf (arqSaida, "\nTotal de %i calorias consumidas no dia\n\n", caloriasTotal);

        fprintf (arqSaida, "======== ESTATÍSTICAS ABP ============\n");
        fprintf (arqSaida, "Numero de nodos: %i\n", nroNodos);
        fprintf (arqSaida, "Altura: %i\n",alturaABP(arv));
        fprintf (arqSaida, "Rotacoes: 0\n");
        fprintf (arqSaida, "Numero de comparacoes: %i\n\n", comparacoes);

        rewind(arqPaciente);
        comparacoes = 0;
        while (fscanf(arqPaciente, "%[^;];%d\n", alimentoPaciente, &gramasAlimento) == 2) {    //codigo baseado no stack overflow p/ como ler de dois em dois
            //qual pesquisa usar aqui, qual arvore?
            //por enquanto tem para ABP, fazer partes para outras pesquisas!!!

            //fazer funcao para calcula calorias
            auxCalorias = pesquisaPadraoAVL(arvAVL,alimentoPaciente,&comparacoes);
            if (auxCalorias != NULL)
                printf ("%ig de %s (%i calorias por 100g) = %i calorias\n", gramasAlimento, alimentoPaciente, caloriasAlimento, caloriasCalculada);
            else
                printf ("As calorias de %s nao estao contabilizadas\n",alimentoPaciente);
        }
        fprintf (arqSaida, "======== ESTATÍSTICAS AVL ============\n");
        fprintf (arqSaida, "Numero de nodos: %i\n", nroNodos);
        fprintf (arqSaida, "Altura: %i\n", alturaAVL(arvAVL));
        fprintf (arqSaida, "Rotacoes: %i\n", rotacoes);
        fprintf (arqSaida, "Numero de comparacoes: %i\n",comparacoes);

    }

    fclose (arqSaida);
    fclose (arqPaciente);

//espaço para ABP *******************************************************************************************************
    //printf("Em ordem crescente...\n");
    //centralE(arv);
    //printf ("\n");

//espaço para AVL *******************************************************************************************************
    //o desenha desenha em qual ordem?
    //printf ("Desenho AVL\n");
    //desenha(arvAVL, 1);
    //printf ("\n");

    printf ("numero de nodos eh: %i", nroNodos);
    return 0;
}

//AREA DE TESTES **************************************************************************************************************
 /*
    char comidaAchar[STRING_SIZE] = {"estrogonofe"};
    printf("Pesquisando por '%s'...\n",comidaAchar);

    pNodoA *nodoAchado;
    nodoAchado = NULL;


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
*/

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
