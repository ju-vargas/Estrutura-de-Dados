#include "bib.h"

//função de criar a lista, devolve um ponteiro VAZIO pois ainda não há lista 
ptLSE* cria_lista(void) {
    return NULL;
}

ptLSE* insere (ptLSE *PtLista, int aux) {   // a função recebe um ponteiro para a lista e um número, e devolve o ponteiro para o novo novo
    
    ptLSE *novo;            // ponteiro para o NOVO elemento
    ptLSE *ant = NULL;      // ponteiro auxiliar para o elemento ANTERIOR 
    ptLSE *ptAux;           // ponteiro auxiliar para PERCORRER a lista 
    ptLSE *ptAuxNum;        // ponteiro que guarda o endereço do NUM quando ele é encontrado
    ptLSE *ptUltimo;        // ponteiro auxiliar para ultimo endereço da lista 

    int temNaLista = 0;
    int listaVazia = 0; 
    int nroNodos = 0; 
    int posicaoEncontro = 0; 

    //1 - PERCORRER a lista simplesmente encadeada ============================================================================
    // BUSCAR a posição de inserção 
    /*  COMO vai FUNCIONAR essa busca?
        --- vou percorrer e procurar se o número aux já está nessa lista 
            --- a partir disso, que vai ser decidido como inserir
                --- lembrar de fazer ifs para os casos 
                    - lista vazia     (atualiza ptLSE)
                    - lista no inicio (remoção diferente)
                    - lista no fim    (remoção diferente)
    */

    ptAux = PtLista; 

    if (ptAux = NULL)
        listaVazia = TRUE;  

    while (ptAux!= NULL) {
        if ((ptAux->numero) == aux) {
            temNaLista = TRUE; 
            posicaoEncontro = nroNodos; //posicao encontro começa do ZERO
            ptAuxNum = ptAux; 
        }         
        ant = ptAux;            // coloca ptAux como o ponteiro do no anterior
        ptAux = ptAux->prox;    // coloca o proximo como o atual
        nroNodos++;             // nroNodos começa do UM, pois estou contando uma quantidade
    }


    //2 - CRIAR o nodo  ========================================================================================================
    //--- lembrar dos possíveis casos 
    
    
    //se a lista estiver vazia
    if (listaVazia) {
        //criar a lista mudando o ponteiro
        novo = (ptLSE*) malloc(sizeof(ptLSE));
        novo->numero = aux; 
        PtLista = novo;
    }

    //se a lista tem elementos
    else if (temNaLista) {
        if (posicaoEncontro == 0) {                 //verifica se está no INICIO da lista
            //criar nodo anterior
            novo = (ptLSE*) malloc(sizeof(ptLSE));
            novo->numero = aux-1; 
            novo->prox = ptAuxNum;
            PtLista = novo;

            //criar nodo posterior
            novo = (ptLSE*) malloc(sizeof(ptLSE));
            novo->numero = aux+1;
            novo->prox = ptAuxNum->prox;            
        }

        else if ((posicaoEncontro+1) == nroNodos) {  //verifica se está no FIM da lista
            //criar nodo anterior
            novo = (ptLSE*) malloc(sizeof(ptLSE));
            novo->numero = aux-1; 
            novo->prox = ptAuxNum;
            
            //criar nodo posterior  
            novo = (ptLSE*) malloc(sizeof(ptLSE));
            novo->numero = aux+1; 
            novo->prox = NULL;
        }

        else {                                      //verifica se está no MEIO da lista
            //criar nodo anterior
            novo = (ptLSE*) malloc(sizeof(ptLSE));
            novo->numero = aux-1; 
            novo->prox = ptAuxNum;

            //criar nodo posterior
            novo = (ptLSE*) malloc(sizeof(ptLSE));
            novo->numero = aux+1;
            novo->prox = ptAuxNum->prox;  
        }
    }

    if (!temNaLista) { 
        ptAux = PtLista; 


        //remove o primeiro e o ultimo elemento
        

        if (nroNodos > 1) {
            //ultimo
            while (ptAux != NULL) {                // para achar o ultimo elemento
                ptUltimo = ptAux; 
                ptAux = ptAux->prox; 
            }

            while (ptAux->prox != ptUltimo) {
                ptAux = ptAux->prox;                // isso faz com que ptAux carregue o antepenultimo
            }

            ptAux->prox = NULL;                     // penultimo->proximo recebe NULL
            free (ptUltimo);                        // dou free no ultimo ponteiro
                    
            //primeiro

            // se só tem dois elementos  
            //excluo diferente
            //altero ponteiro
            
            if (nroNodos == 2) {
                free(PtLista);
                PtLista = NULL;
            }
            else {
                ptAux = PtLista;                        
                PtLista = PtLista ->prox; 
                free (ptAux);
            }

            
        }
         
        // se só tem um elemento
            //excluo diferente
            //altero ponteiro

        if (nroNodos == 1) {
            free(PtLista);
            PtLista = NULL;
        }
    }

    return NULL ;
}

ptLSE* busca(void) {
    return NULL;
}

ptLSE* removeLista(void) {
    return NULL;
}

ptLSE* detroi(ptLSE *ptLista) {             // a funçao recebe um ponteiro para o inicio da lista e vai percorrendo dando free

    ptLSE *ptAux;              //ponteiro auxiliar para percorrer a lista
    while (ptLista != NULL) {
         ptAux = ptLista;
         ptLista = ptLista->prox;
         free(ptAux);
   }
   free(ptLista);
   return NULL;
}

ptLSE* imprime(void) {
    return NULL;
}