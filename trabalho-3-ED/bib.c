#include "bib.h"

//função de criar a lista, devolve um ponteiro VAZIO pois ainda não há lista 
ptLSE* cria_lista(void) {
    return NULL;
}

ptLSE* insere (ptLSE *PtLista, int aux) {  

    ptLSE *novo = NULL;            // ponteiro para o NOVO elemento
    ptLSE *ant = NULL;             // ponteiro auxiliar para o elemento ANTERIOR 
    ptLSE *ptAux = NULL;           // ponteiro auxiliar para PERCORRER a lista 
    ptLSE *ptAuxNum = NULL;        // ponteiro que guarda o endereço do NUM quando ele é encontrado
    ptLSE *ptUltimo = NULL;        // ponteiro auxiliar para ultimo endereço da lista 

    int temNaLista = 0;
    int listaVazia = 0; 
    int nroNodos = 0; 
    int posicaoEncontro = 0;

    ptAux = PtLista; 

    if (ptAux == NULL) {
        listaVazia = TRUE;
    }

//BUSCAR se já há na lista =====================================================================================

    if (!listaVazia) {
        do {
            if ((ptAux->numero) == aux) {
                temNaLista = TRUE; 
                posicaoEncontro = nroNodos;             //posicao encontro começa do ZERO
                ptAuxNum = ptAux; 
                //nao preciso buscar nodo anterior pois é duplamente encadeada  
            } 
            ptAux = ptAux->prox;                        // coloca o proximo como o atual
            nroNodos++;                                 // nroNodos começa do UM, pois estou contando uma quantidade
        }  while (ptAux->prox != PtLista);
    }

    /* while (ptAux->prox != PtLista) {

            if ((ptAux->numero) == aux) {
                temNaLista = TRUE; 
                posicaoEncontro = nroNodos;             //posicao encontro começa do ZERO
                ptAuxNum = ptAux; 
                                                        //nao preciso buscar nodo anterior pois é duplamente encadeada  
            } 
            ptAux = ptAux->prox;                        // coloca o proximo como o atual
            nroNodos++;                                 // nroNodos começa do UM, pois estou contando uma quantidade
        }
    }*/

//CRIAR o nodo em lista vazia ====================================================================================

    if (listaVazia == TRUE) {
        //criar a lista mudando o ponteiro
        novo = (ptLSE*) malloc(sizeof(ptLSE));

        novo->numero = aux;                             // quando só há um nó num lista circular, ela aponta para si mesma
        novo->prox = novo;
        novo->ant = novo;

        PtLista = novo;
        ptAux = PtLista;
        listaVazia = FALSE;
    }


// INSERIR nodo em lista COM elementos ===========================================================================
    else if (temNaLista) {
        
        //criar nodo posterior
        novo = (ptLSE*) malloc(sizeof(ptLSE));

        novo->numero = aux+1;                       //preechendo campo do novo nodo
        novo->prox = ptAuxNum->prox;   
        novo->ant = ptAuxNum; 

        ptAuxNum->prox->ant = novo;                 //preenchendo campo do nodo posterior ao novo
        ptAuxNum->prox = novo;                      //preenchendo campo do nodo anterior ao novo (é o ptAuxNum)


        //criar nodo anterior
        novo = (ptLSE*) malloc(sizeof(ptLSE));

        novo->numero = aux-1;                       //preenchendo campo do novo nodo  
        novo->prox = ptAuxNum;
        novo->ant = ptAuxNum->ant; 

        ptAuxNum->ant->prox = novo;                 //preenchendo campo do nodo anterior ao novo
        ptAuxNum->ant = novo;                       //preenchendo campo do nodo posterior ao novo (é o ptAuxNum)

        if (posicaoEncontro == 0)                    //verifica se está no INICIO da lista
            PtLista = novo;

        

        //o que ta acontecendo é que 
        //o posterior 

        
    }

    else if (!temNaLista) { 
        ptAux = PtLista; 

        //remove o primeiro e o ultimo elemento
        if (nroNodos > 1) {
            ptUltimo = PtLista->ant;                //ultimo elemento
            ptAux = ptUltimo->ant;                  //penultimo elemento

            //ultimo                   
            ptAux->prox = PtLista;                  //penultimo->prox recebe primeiro da lista
            PtLista->ant = ptAux;                   //primeiro->ant recebe novo ultimo da lista         

            free (ptUltimo);                        //dou free no ultimo ponteiro
                    
            //primeiro
            ptAux = PtLista; 
            ptUltimo = PtLista->ant;
            PtLista = PtLista->prox;
            PtLista->ant = ptUltimo; 
            free (ptAux);    
        }
                                                 
        if (nroNodos == 1) {                        // se só tem um elemento
            free(PtLista);
            PtLista = NULL;
        } 
    }

    return PtLista; 
}

ptLSE* destroi(ptLSE *ptLista) {                    //a funçao recebe um ponteiro para o inicio da lista e vai percorrendo dando free
    ptLSE *ptAux;                                   //ponteiro auxiliar para percorrer a lista
    ptLSE *ptPrimeiro; 

    

    ptPrimeiro = ptLista; 

    do {                                            //quando o ptLista->prox for igual ao primeiro 
        ptAux = ptLista;
        ptLista = ptLista->prox;
        free(ptAux);
    } while (ptLista != ptPrimeiro);
    
    return NULL;

}


void imprime(ptLSE *ptLista) {
    ptLSE *ptAux;                                   //ponteiro auxiliar para percorrer a lista
    ptLSE *ptPrimeiro; 
    ptLSE *ptUltimo;


    ptPrimeiro = ptLista; 

    ptAux = ptLista;

    if (ptAux == NULL)
        printf("Lista vazia! ");

    do {                                            //quando o ptLista->prox for igual ao primeiro 
        printf("%i", ptAux->numero);
        ptAux = ptAux->prox;
        
        if (ptAux != ptPrimeiro)
            printf ("->");

    } while (ptAux != ptPrimeiro);

    printf("\n"); 


    printf ("Lista de tras pra frente: ");
    ptUltimo = ptAux = ptLista->ant; 
    
    do {                                            //quando o ptLista->prox for igual ao primeiro 
        printf("%i", ptAux->numero);
        ptAux = ptAux->ant;
        
        if (ptAux != ptUltimo)
            printf ("->");

    } while (ptAux != ptUltimo);

    printf("\n"); 

}
