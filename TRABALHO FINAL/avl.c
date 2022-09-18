#include "avl.h"

/*
como implementar AVL?
   1. criar structs (na TAD) ok
   2. criar insere árvore ok
   3. saber calcular altura
*/

pNodoAVL* InsereArvoreAVL(pNodoAVL * a, tipoInfo info) {
  
   if (a == NULL) {
      a = (pNodoAVL*) malloc(sizeof(pNodoAVL));               //alocando espaço para o nodo, dando um endereço a ele

      strcpy (a->nodoInfo.alimento, info.alimento);
      a->nodoInfo.calorias = info.calorias;

      a->esq = NULL;
      a->dir = NULL;
      a->FB = 0;                                              // o nodo eh sempre inserido como folha entao seu fator de balanceamento eh 0
   }

   else {
      if (comparaAlimento(info, a->nodoInfo.alimento) < 0)    // caso a info adicionada seja MENOR QUE seu pai
         a->esq = InsereArvore(a->esq, info);
      else
         if (comparaAlimento(info, a->nodoInfo.alimento) > 0) // caso a info adicionada seja MAIOR QUE seu pai
         a->dir = InsereArvore(a->dir, info);
   }

   return a;
}

//******* verificar depois
int Altura (pNodoAVL *a) {                                    // recebo o endereço do nodo e vejo sua altura 
   int altEsq, altDir;
   if (a == NULL)
      return 0;

   else {
      altEsq = Altura (a->esq);
      altDir = Altura (a->dir);

      if (altEsq > altDir)
         return (1 + altEsq);
      else
         return (1 + altDir);
     }
}


int calculaFB(pNodoAVL *a) {                                   // para calcular fator de balanceamento
    return (Altura(a->esq) - Altura(a->dir));
}


void Desenha(pNodoAVL *a , int nivel) {                        // funcao para desenhar a árvore
   int x;
   if (a !=NULL) {
      for (x=1; x<=nivel; x++)
         printf("=");
         printf("%s FB= %d\n", a->nodoInfo.alimento, Calcula_FB(a));

   if (a->esq != NULL) 
      Desenha(a->esq, (nivel+1));
   if (a->dir != NULL) 
      Desenha(a->dir, (nivel+1));
 }
}





//preciso mesmo recopiar essa função aqui, já tenso usado para abp.c?
int comparaAlimento (tipoInfo info, char nome[50]) {
    int compara = 0;
    compara = strcmp (info.alimento, nome);
    return compara; 
}