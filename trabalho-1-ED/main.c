//lab 01 - tipo abstrato de dados

/*para compilar, usei as seguintes linhas no terminal do vscode: 
    gcc -o main.exe main.c jogadorbib.c
	 ./main.exe*/
#include "jogadorbib.h"


int main(void) {
    JOGADOR jogadores[20] = {}; 
    int contador = 0, op = 0, aux = 0; 
    int tamanhoMax=20, inicioLista = -1, fimLista = -1; 

    //primeiro, é preciso inserir os jogadores no meu array de jogadores
    printf ("Insira os jogadores (no maximo 20)!\n"); 
        while (op != 1) {
            atribui_dados(&jogadores[contador]); 
            contador++; 
            printf ("\nDigite 1 para sair (ou outro numero para continuar): \n");
            scanf ("%i", &op); 
        }


    //depois, preciso exibir a estatistica dos jogadores
    for (int i = 0; i < contador; i++) {
        printf ("JOGADOR NUMERO %i\n", i);
        exibe_estatisticas(&jogadores[i]); 
    }
    

    //depois disso, preciso ter a opção de testar se um jogador específico eh bom (o usuário poderá escolher qual jogador) 
    //---- caso ele escolha um numero de jogador que nao esta na lista, da erro.
    printf("\nEscolha um jogador para saber se ele eh o bom! (de 0 ate %i)\n", contador); 
    scanf ("%i", &aux); 
    if (aux <= contador)
        eh_o_bom(&jogadores[aux]); 
    else 
        printf ("Nao ha jogador cadastrado com esse número!");

    printf("\nFIM DO PROGRAMA");
    return 0; 
} 
