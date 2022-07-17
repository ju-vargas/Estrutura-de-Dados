#ifndef JOGADORBIB_H
#define JOGADORBIB_H

#include <stdio.h>
#include <string.h>

#define NUM_JOGADORES 20; 

typedef struct jogador {
    char nome[20]; 
    int idade; 
    int num_gols; 
    int num_faltas; 
    int num_passes_errados;
    int num_passes_corretos;
} JOGADOR;

void atribui_dados(JOGADOR *jogador); 
void exibe_estatisticas(JOGADOR *jogador); 
void eh_o_bom(JOGADOR *jogador);

#endif