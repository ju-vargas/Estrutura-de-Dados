
#include <stdio.h>
#include <conio.h>
#include "lse.h"

int main(void)
{
    InfoNo dados;
    char cont;
    char rem[20];

    PtNo* l;
    l = cria_lista();
    do
    {
       printf("Titulo: "); gets(dados.titulo);
       printf("Distribuidora: "); gets(dados.distr);
       printf("Diretor: "); gets(dados.diretor);
       l = insere_ord(l, dados);
       printf("Continua? \n"); cont = getche();
    }while (cont!='n');

    printf("\nExibindo a lista...\n");
    imprime(l);
    getch();

    printf("Qual titulo deseja remover?\n");

    gets(rem);
    l = remover(l, rem);
    imprime(l);
    getch();

    l=destroi(l);
    imprime(l);
    getch();
}

