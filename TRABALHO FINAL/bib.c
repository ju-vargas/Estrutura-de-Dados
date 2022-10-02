#include "bib.h"


// funcoes ARVORES *******************************************************************************************************

//funcao que compara o campo nome de um alimento com a palavra procurada
//entrada: struct info do nodo, e palavra que quero comparar
//saida: 1 quando palavra nodo > palavra, 0 para iguais, -1 para menor
int comp = 0;
int comparaAlimento (tipoInfo info, char nome[STRING_SIZE]) {
    //compara = strcmp (info.alimento, nome);
    int i;
    char infoNodoLower[STRING_SIZE];
    char nomeLower[STRING_SIZE];

    strcpy(infoNodoLower,info.alimento);
    strcpy(nomeLower,nome);
    /**    
    ajeitar aqui pra otimizar    
    **/
    for(i=0; infoNodoLower[i]!='\0'; i++){
        if(infoNodoLower[i]>='A' && infoNodoLower[i]<='Z'){
            infoNodoLower[i] = infoNodoLower[i] + 32;
        //    comp++;
        }
    }

    for(i=0; nomeLower[i]!='\0'; i++){
        if(nomeLower[i]>='A' && nomeLower[i]<='Z'){
            nomeLower[i] = nomeLower[i] + 32;
        //    comp++;
        }
    }
// upper -> 457932
// lower -> 95539
    //printf("comp %d\n",comp);
    return strcmp(infoNodoLower, nomeLower);
}
