#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
 
Lista *inicializa() {
    Lista *l = (Lista*) malloc (sizeof(Lista));
    l->cabeca = NULL;
    l->tam = 0;
    return l;
}
 

void insere_inicio(Lista *l, int valor) {
    No *novo = malloc(sizeof(No));
    novo->dado = valor;
 
    if (l->cabeca == NULL) {
        novo->prox = novo;
        novo->ant = novo;
        l->cabeca = novo;
    } else {
        No *ultimo = l->cabeca->ant;
        novo->prox = l->cabeca;
        novo->ant = ultimo;
        ultimo->prox = novo;
        l->cabeca->ant = novo;
        l->cabeca = novo;
    }
    l->tam++;
}
 

No* remove_no(Lista *l, No *p) {
    if (l->tam == 0) return NULL;
 
    No *ant = p->ant;
    No *prox = p->prox;
 
    if (l->tam == 1) {
        l->cabeca = NULL;
    } else {
        ant->prox = prox;
        prox->ant = ant;
        if (l->cabeca == p) l->cabeca = prox;
    }
 
    free(p);
    l->tam--;
    return prox;
}
 

No* percorre_frente(No *atual, int passos) {
    No *p = atual;
    int i;
    for (i = 0; i < passos; i++) {
        p = p->prox;
    }
    return p;
}
 

No* percorre_tras(No *atual, int passos) {
    No *p = atual;
    int i;
    for (i = 0; i < passos; i++) {
        p = p->ant;
    }
    return p;
}
 

int escolhe_lider(Lista *l, No *inicio, int k) {
    No *atual = inicio;
    int direita = 1;
 
    while (l->tam > 1) {
        int passos = (k - 1) % l->tam;
        No *alvo;
 
        if (direita)
            alvo = percorre_frente(atual, passos);
        else
            alvo = percorre_tras(atual, passos);
 
        No *prox_atual;
        if (direita)
            prox_atual = alvo->ant;
        else
            prox_atual = alvo->prox;
 
        remove_no(l, alvo);
        atual = prox_atual;
        direita = !direita;
    }
 
    return l->cabeca->dado;
}
 
void libera_lista(Lista *l) {
    while (l->tam > 0) {
        remove_no(l, l->cabeca);
    }
}