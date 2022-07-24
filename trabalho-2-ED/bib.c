#include "bib.h"

//função de criar a lista, devolve um ponteiro VAZIO pois ainda não há lista 
ptLSE* cria_lista(void) {
    return NULL;
}

ptLSE* insere (ptLSE *PtLista, int aux) {   // a função recebe um ponteiro para a lista e um número, e devolve o ponteiro para o novo novo
    ptLSE *novo = NULL;           // ponteiro para o NOVO elemento
    ptLSE *ant = NULL;      // ponteiro auxiliar para o elemento ANTERIOR 
    ptLSE *ptAux = NULL;           // ponteiro auxiliar para PERCORRER a lista 
    ptLSE *ptAuxNum = NULL;        // ponteiro que guarda o endereço do NUM quando ele é encontrado
    ptLSE *ptUltimo = NULL;        // ponteiro auxiliar para ultimo endereço da lista 

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

    if (ptAux == NULL) {
        printf("LISTA VAZIA\n");
        listaVazia = TRUE;
    }
          
    if (!listaVazia) {
        
        while (ptAux != NULL) {
            printf("PROCURANDO IGUAL\n");
            //printf ("numero eh %i\n", ptAux->numero);
            if ((ptAux->numero) == aux) {
                temNaLista = TRUE; 
                posicaoEncontro = nroNodos; //posicao encontro começa do ZERO
                ptAuxNum = ptAux; 

                
                ant = PtLista; 
                    while (ant->prox != ptAuxNum && ant->prox != NULL) {
                    ant = ant->prox;                // isso faz com que ant carregue o anterior ao encontrado
                    printf ("o anterior eh %i", ant->numero);
                }

                
            } 
            
            ptAux = ptAux->prox;    // coloca o proximo como o atual
            nroNodos++;             // nroNodos começa do UM, pois estou contando uma quantidade
        }
    }

    if (temNaLista) {
        printf("o numero %i esta na lista\n", ptAuxNum->numero);
        printf("ponteiro ultimo: %i, ponteiro penultimo: %i", ptAuxNum->numero, ant->numero);
    }

    //2 - CRIAR o nodo  ========================================================================================================
    //--- lembrar dos possíveis casos 
    
    
    //se a lista estiver vazia
    if (listaVazia == TRUE) {
        printf("CRIANDO PRIMEIRO MEMBRO\n");
        //criar a lista mudando o ponteiro
        novo = (ptLSE*) malloc(sizeof(ptLSE));
        novo->numero = aux; 
        novo->prox = NULL;
        PtLista = novo;
        ptAux = PtLista;
        listaVazia = FALSE;
    }

    //se a lista tem elementos
    else if (temNaLista) {
        printf("TEM NA LISTA ");



        
        if (posicaoEncontro == 0) {                 //verifica se está no INICIO da lista
            printf("no INICIO\n");


            //criar nodo posterior
            novo = (ptLSE*) malloc(sizeof(ptLSE));
            novo->numero = aux+1;

            printf("novo numero: %i %i\n", novo->numero, aux);
            novo->prox = ptAuxNum->prox;   
            ptAuxNum->prox = novo;
            printf("novo prox: %i\n", novo->prox);    
            if (nroNodos == 1) 
            novo->prox = NULL;     


            //criar nodo anterior
            novo = (ptLSE*) malloc(sizeof(ptLSE));
            novo->numero = aux-1; 
            printf("novo numero: %i %i\n", novo->numero, aux);
            novo->prox = ptAuxNum;
            printf("novo prox: %i\n", novo->prox);  
            PtLista = novo;

            

            

            
        }

        else if ((posicaoEncontro+1) == nroNodos) {  //verifica se está no FIM da lista
            printf("no FIM\n");
            //criar nodo anterior
            novo = (ptLSE*) malloc(sizeof(ptLSE));
            novo->numero = aux-1; 
            novo->prox = ptAuxNum;
            if (nroNodos == 1) 
                novo->prox = NULL; 
            
            //criar nodo posterior  
            novo = (ptLSE*) malloc(sizeof(ptLSE));
            novo->numero = aux+1; 
            novo->prox = NULL;ptAuxNum->prox = novo;
            ptAuxNum->prox = novo;
        }

        else {                                      //verifica se está no MEIO da lista
            printf("no MEIO\n");
            //criar nodo anterior
            novo = (ptLSE*) malloc(sizeof(ptLSE));
            novo->numero = aux-1; 
            novo->prox = ptAuxNum;                  //to inserindo o nome antes 
            ant->prox = novo;                       //preciso ligar o anterior antigo com o anterior novo antAntigo->prox = antNovo; 

            //criar nodo posterior
            novo = (ptLSE*) malloc(sizeof(ptLSE));
            novo->numero = aux+1;
            novo->prox = ptAuxNum->prox;  
            ptAuxNum->prox = novo;                  //preciso ligar o inserido posterior com o num da lista
        }
    }

    else if (!temNaLista) { 
        printf("NAO TEM NA LISTA\n");
        ptAux = PtLista; 

        //remove o primeiro e o ultimo elemento
        if (nroNodos > 1) {
            //ultimo
            while (ptAux != NULL) {                // para achar o ultimo elemento
                ptUltimo = ptAux; 
                ptAux = ptAux->prox; 
            }       

            ptAux = PtLista;
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
                printf("numero de nodos nao eh 2");                 
                PtLista = PtLista ->prox; 
                free (ptAux);
            }
        }
         
        // se só tem um elemento
            //excluo diferente
            //altero ponteiro
        if (nroNodos == 1) {
            printf("entrei na exclusao, caso numero de nodos > 1");
            free(PtLista);
            PtLista = NULL;
        }

        printf("ponteiro da lista qnd nao tem = %i", PtLista); 
    }

    return PtLista;
}

ptLSE* busca(void) {
    return NULL;
}

ptLSE* destroi(ptLSE *ptLista) {             // a funçao recebe um ponteiro para o inicio da lista e vai percorrendo dando free
    ptLSE *ptAux;              //ponteiro auxiliar para percorrer a lista
    while (ptLista != NULL) {
         ptAux = ptLista;
         ptLista = ptLista->prox;
         free(ptAux);
   }
   free(ptLista);
   return NULL;
}

void imprime(ptLSE *ptLista) {
    ptLSE *ptAux;

    ptAux = ptLista;
    printf("%i\n", ptAux);
    printf("entrei na imprime\n");

    while ( ptAux != NULL) {
        printf("%i", ptAux->numero);
        if (ptAux->prox != NULL)
            printf ("->");
        ptAux = ptAux->prox;
    }
}