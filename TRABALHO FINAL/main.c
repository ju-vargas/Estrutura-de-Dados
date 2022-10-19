#include "bib.h"
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(int nroArgs, char *nomeArq[]){
//VARIAVEIS *********************************************************************************************************
    int ok;
    int nroNodos = 0;
    int comparacoes = 0;
    int rotacoes = 0;

    pNodoA *arv;
    pNodoAVL *arvAVL;
    arv = NULL;
    arvAVL = NULL;
//LEITURA DE ARQUIVO CALORIAS ******************************************************************************************
    //essas variaveis guardam o nome dos arquivos
    //se receber o nome do terminal, vou usar elas pra conseguir selecionar o arquivo
    char nomeArqCalorias[STRING_SIZE];
    char nomeArqPaciente[STRING_SIZE];
    char nomeArqSaida[STRING_SIZE];

    strcpy(nomeArqCalorias, nomeArq[1]);
    strcpy(nomeArqPaciente, nomeArq[2]);
    strcpy(nomeArqSaida, nomeArq[3]);

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
    //le arquivo do paciente um de cada vez
    //pesquisa na árvore
    //escreve e fecha
    char alimentoPaciente[STRING_SIZE];
    int gramasAlimento = 0;
    int caloriasAlimento = 0;
    int caloriasCalculada = 0;
    int caloriasTotal = 0;

    pNodoA * auxCalorias;
    auxCalorias = NULL;

    pNodoAVL * auxCaloriasAVL;
    auxCaloriasAVL = NULL;

    FILE *arqPaciente = fopen(nomeArqPaciente, "r");
    FILE *arqSaida = fopen(nomeArqSaida, "wb+");

    if (!arqPaciente){
        perror("arqPaciente");
    }else if (!arqSaida){
        perror("arqSaida");
    }else {
        fprintf (arqSaida, "Calorias calculadas para %s usando a tabela %s.\n\n", nomeArqPaciente, nomeArqCalorias);

        //espaço para ABP *******************************************************************************************************
        //codigo baseado no stack overflow p/ como ler de dois em dois

        while (fscanf(arqPaciente, "%[^;];%d\n", alimentoPaciente, &gramasAlimento) == 2) {
            auxCalorias = pesquisaPadrao(arv,alimentoPaciente,&comparacoes);

            if (auxCalorias != NULL){
                caloriasAlimento = auxCalorias->nodoInfo.calorias;
                caloriasCalculada = (caloriasAlimento*gramasAlimento)/100;
                caloriasTotal += caloriasCalculada;
                fprintf (arqSaida, "%ig de %s (%i calorias por 100g) = %i calorias\n", gramasAlimento, alimentoPaciente, caloriasAlimento, caloriasCalculada);
            }
            else
                fprintf (arqSaida, "As calorias de %s não estão contabilizadas\n",alimentoPaciente);
        }
            fprintf (arqSaida, "\nTotal de %i calorias consumidas no dia\n\n", caloriasTotal);

        fprintf (arqSaida, "======== ESTATÍSTICAS ABP ============\n");
        fprintf (arqSaida, "Numero de nodos: %i\n", nroNodos);
        fprintf (arqSaida, "Altura: %i\n",alturaABP(arv));
        fprintf (arqSaida, "Rotacoes: 0\n");
        fprintf (arqSaida, "Numero de comparacoes: %i\n\n", comparacoes);

        rewind(arqPaciente);
        comparacoes = 0;

        //espaço para AVL *******************************************************************************************************
        //codigo baseado no stack overflow p/ como ler de dois em dois
        while (fscanf(arqPaciente, "%[^;];%d\n", alimentoPaciente, &gramasAlimento) == 2) {
            auxCaloriasAVL = pesquisaPadraoAVL(arvAVL,alimentoPaciente,&comparacoes);

            if (auxCaloriasAVL != NULL)
                printf ("%ig de %s (%i calorias por 100g) = %i calorias\n", gramasAlimento, alimentoPaciente, auxCaloriasAVL->nodoInfo.calorias, caloriasCalculada);
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

    printf ("Numero de nodos eh: %i", nroNodos);

    return 0;
}
