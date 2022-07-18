#include "bib.h"


/* Problema para o laboratório. Implementar uma função para inserir um número indeterminado de
elementos (números inteiros) em uma lista simplesmente encadeada.*/



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



    ptLSE* p;
    p = cria_lista(); 




    return 0;
}