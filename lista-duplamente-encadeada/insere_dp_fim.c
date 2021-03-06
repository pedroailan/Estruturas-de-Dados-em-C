#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int indice;
    int conteudo;
    struct reg *prox, *ant;
}  celula;

typedef struct {
   celula* inicio;
   celula* fim;
   int sent;
 
} LISTA;


void inicializarLista(LISTA *l) {
  l->inicio = NULL;
  l->fim = NULL;
  l->sent = 0;
}

void organiza_indice(LISTA *l) {
  celula *p = l->inicio;
  for(int i = 1; i <= l->sent; i++){
    p->indice = i;
    p = p->prox;
  } 
}

void insere(LISTA *l, int n) {
  celula *nova;
  nova = malloc(sizeof(celula));
  nova->conteudo = n;
  nova->prox = l->inicio;
  l->inicio = nova;
  l->sent += 1;
  organiza_indice(l);
}

void insere_dp_fim(LISTA *l, int n) {
  celula *nova = malloc(sizeof(celula));
  nova->conteudo = n;
  if(l->inicio == NULL) {
    nova->prox = l->inicio;
    nova->ant = NULL;
    l->inicio = nova;
    l->fim = nova;
  } else {
    nova->prox = NULL;
    nova->ant = l->fim;
    l->fim->prox = nova;
    l->fim = nova;
  }
  organiza_indice(l);
}


void imprime(LISTA *l) {

  celula *p;
  for (p = l->inicio ; p != NULL ; p = p->prox) {
       printf("Indice %d:  / Conteudo: %d\n", p->indice, p->conteudo);
  }
  printf("\n");
  printf("Inicio: %d\n", l->inicio->conteudo);
  printf("Fim: %d\n", l->fim->conteudo);
}

int main() {
  LISTA l;

  inicializarLista(&l);


  insere_dp_fim(&l, 2);
  insere_dp_fim(&l, 3);
  insere_dp_fim(&l, 7);

  organiza_indice(&l);

  imprime(&l);
     
  getchar();
return 0;
}