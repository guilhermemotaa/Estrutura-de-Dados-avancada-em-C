#ifndef _DESCRITOR_H
#define _DESCRITOR_H

typedef struct No {
    int valor; // Valor armazenado no nó
    struct No *prox; // Ponteiro para o próximo nó
} No;
 

typedef struct {
    No *inicio; // Ponteiro para o início da lista
    No *fim; // Ponteiro para o final da lista
    int quantidade; // Quantidade de elementos na lista
} Descritor;

Descritor* criaLista ();
void inicializarlista(Descritor *l);
void inserirInicio (Descritor *l, int valor);
void inserirFinal (Descritor *l,int valor);
void removerInicio (Descritor *l);
void removerFinal(Descritor *l);
void removerElemento(Descritor *l, int elem);
void exibirLista (Descritor *l);



#endif