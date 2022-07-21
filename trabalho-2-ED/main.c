#include "bib.h"


/* Problema para o laboratório. Implementar uma função para inserir um número indeterminado de
elementos (números inteiros) em uma lista simplesmente encadeada.*/

//o código está com erros


/*  criar uma lista vazia
        -> cria uma lista e devolve o ponteiro para o início da lista
    inserir elementos na lista criada   
        -> funcao inserir 
        -> fazer função insere 
            --- recebe o ponteiro para o início da lista
            --- recebe um numero qualquer
                *** de acordo com a lista que já foi inserida:
                    --- se o numero existe, adiciona numero - 1 antes e numero + 1 depois
                        -> fazer busca 
                        -> inserir
                    --- se o numero não existe, primeiro e ultimo item excluídos (se existirem)
                        -> fazer busca
                        -> remover
                        -> atualizar ptLista para NULL caso o único elemento seja destruído
                    --- se a LISTA está VAZIA, num deve ser colocado na primeira posição
                        -> fazer busca 
                        -> inserir
                        -> atualizar ptlista
                *** se o valor inserido for 0, sai do laço 
    exibe lista
        -> funcao imprime
    destruir lista
        -> funcao destroi
    exibe lista
        -> funcao imprime
    fim do programa
*/

int main(void) {

    ptLSE* PtLista;
    
    int aux = 1; 


    //criar lista
    PtLista = cria_lista(); 

    //inserir 
    //criar lista usando esse numero 
    while (aux!=0) {
        printf("Insira um numero: "); 
        scanf("%i", &aux); 
        //PtLista = insere(PtLista, aux);
        PtLista = insere(PtLista, aux);
        //*** PERCORRER LISTA (busca)

        //se a lista está vazia, vira o primeiro elemento
        //se o numero nao está lista, REMOVE primeiro e ultimo
        //caso esteja removendo o único elemento, lembrar de atualizar ptLista para NULL
        //se está, INSERE
    }
        
    if (aux == 0) {
        printf ("Programa encerrado!");
    }  

    imprime(PtLista);
    destroi(PtLista);
    imprime(PtLista);

    

    return 0;
}