#include "jogadorbib.h"
//CRIAÇÃO DE FUNÇÕES 

/*função para atribuir dados na lista. a função recebe um jogador por vez e preenche seus dados*/
void atribui_dados(JOGADOR *jogador) {
    printf ("Nome do Jogador: "); 
    scanf ("%s", &jogador->nome);  
    printf ("Idade do jogador: ");
    scanf  ("%i", &jogador->idade); 
    printf ("Numero de gols do jogador: ");
    scanf  ("%i", &jogador->num_gols); 
    printf ("Numero de faltas do jogador: ");
    scanf  ("%i", &jogador->num_faltas);
    printf ("Numero de passes errados do jogador: ");
    scanf  ("%i", &jogador->num_passes_errados);
    printf ("Numero de passes corretos do jogador: ");
    scanf  ("%i", &jogador->num_passes_corretos);
}

/* essa função imprime os campos de cada jogador, além de calcular a % de passos corretos em relação aos passes totais*/
void exibe_estatisticas(JOGADOR *jogador) {

    float porcentagem = 0; 
    float totalpasses = 0;

    totalpasses = jogador->num_passes_errados + jogador->num_passes_corretos;
  
    porcentagem = (100 * jogador->num_passes_corretos)/totalpasses; 
    //total      100
    //certo      x
    //total * x = 100 * certo
    //x = (100 * certo)/total

    printf ("Nome do jogador: %s\n", jogador->nome); 
    printf ("Idade do jogador: %i\n", jogador->idade); 
    printf ("Numero de gols do jogador: %i\n", jogador->num_gols); 
    printf ("Numero de faltas do jogador: %i\n", jogador->num_faltas); 
    printf ("Numero de passes errados do jogador: %i\n", jogador->num_passes_errados); 
    printf ("Numero de passes corretos do jogador: %i\n", jogador->num_passes_corretos); 
    printf ("Total de passes corretos: %2.f %%\n\n", porcentagem); 
}

/* função que define se jogador "é o bom". ela recebe um jogador e faz a análise. os critérios são:
        -- pelo menos 1.5x mais passes que corretos que errados
        -- pelo menos 3x gols que faltas */
void eh_o_bom(JOGADOR *jogador) {
    if((jogador->num_passes_corretos >= (1.5 * jogador->num_passes_errados)) && jogador->num_gols >= (3*jogador->num_faltas)) {
        printf("Eh o bom!!!");
    }
    else    
        printf ("Nao eh o bom :("); 
    }