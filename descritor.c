#include <stdio.h>
#include <stdlib.h>
#include "descritor.h"


Descritor *criaLista ()
{
	Descritor *l = (Descritor*) malloc (sizeof(Descritor));

	return l;
}

void inicializarlista(Descritor *l)
{
	l->inicio=NULL;
	l->fim=NULL;
	l->quantidade=0;
}

void inserirInicio (Descritor *l, int valor)
{
	No *novo;
	novo= (No*)  malloc (sizeof(No));
	novo->valor=valor;
	novo->prox = l->inicio;
	if (l->fim==NULL)
	{
		l->fim=novo;
	}
	l->inicio = novo;
	l->quantidade++;
}


void inserirFinal(Descritor *l, int valor)
{
    No *novo = (No*) malloc(sizeof(No));

    if (novo == NULL)
        return;

    novo->valor = valor;
    novo->prox = NULL;

    if (l->inicio == NULL)
    {
        l->inicio = novo;
        l->fim = novo;
    }
    else
    {
        l->fim->prox = novo;
        l->fim = novo;
    }

    l->quantidade++;
}

void removerInicio (Descritor *l)
{
    if (l->inicio == NULL)
        return;

    No *aux = l->inicio;

    l->inicio = l->inicio->prox;

    if (l->inicio == NULL)
        l->fim = NULL;

    free(aux);
    l->quantidade--;

}

void removerFinal(Descritor *l)
{
    if (l->inicio == NULL)
        return;

    if (l->inicio == l->fim)
    {
        free(l->inicio);
        l->inicio = NULL;
        l->fim = NULL;
        l->quantidade--;
        return;
    }

    No *aux = l->inicio;

    while (aux->prox != l->fim)
    {
        aux = aux->prox;
    }

    free(l->fim);
    l->fim = aux;
    l->fim->prox = NULL;

    l->quantidade--;
}

void removerElemento(Descritor *l, int elem)
{
    if (l->inicio == NULL)
        return;

    if (l->inicio->valor == elem)
    {
        removerInicio(l);
        return;
    }

    No *ant = l->inicio;
    No *atual = l->inicio->prox;

    while (atual != NULL && atual->valor != elem)
    {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
        return; 

    ant->prox = atual->prox;

    if (atual == l->fim)
        l->fim = ant;

    free(atual);
    l->quantidade--;
}

void exibirLista (Descritor *l)
{
	No *aux = l->inicio;
    printf ("Quantidade de elementos: %d\n",l->quantidade);
	while (aux!=NULL)
	{
		printf ("%d ",aux->valor);
		aux = aux->prox;
	}
	return;
}