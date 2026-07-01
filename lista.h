#ifndef _LISTA_H
#define _LISTA_H
 

typedef struct no {
    int dado;
    struct no *ant;
    struct no *prox;
} No;
 

typedef struct lista {
    No *cabeca;
    int tam;
} Lista;
 
Lista *inicializa();
void insere_inicio(Lista *l, int valor);
No* remove_no(Lista *l, No *p);
No* percorre_frente(No *atual, int passos);
No* percorre_tras(No *atual, int passos);
int escolhe_lider(Lista *l, No *inicio, int k);
void libera_lista(Lista *l);
 
#endif