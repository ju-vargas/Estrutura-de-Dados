#include <stdio.h>
#include <string.h>

//strcmp 
// Nesse contexto, string1 é dita ser "maior que" string2 se o primeiro caracter não-coincidente em string1 tiver um código ASCII maior que o caracter correspondente na string2.


int main(void){

    char string1[10] = "morango"; 
    char string2[10] = "maça";
    int comp = 25; 

    comp = strcmp (string1, string2); 
    printf ("valorrrr: %i", comp); 

    return 0; 
}
