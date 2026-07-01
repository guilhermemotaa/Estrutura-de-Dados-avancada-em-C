#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


ListaCircular *inicializar_lista() 
{
    ListaCircular *lista = (ListaCircular*) malloc (sizeof(ListaCircular));
    lista->ultimo  = NULL;
    lista->tamanho = 0;
}

Nave *criar_nave(int id, int capacidade, int combustivel) 
{
    Nave *nova = (Nave *)malloc(sizeof(Nave));
    if (!nova) 
    { 
        printf("Erro de memoria\n");
        return 0; 
    }
    nova->id = id;
    nova->capacidadeMAX = capacidade;
    nova->combustivelATUAL = combustivel;
    nova->proxima = NULL;
    return nova;
}

void inserir_fim(ListaCircular *lista, int id, int capacidade, int combustivel) 
{
    Nave *nova = criar_nave(id, capacidade, combustivel);
    if (!lista->ultimo)
    {
        nova->proxima = nova;
    } 
    else 
    {
        nova->proxima = lista->ultimo->proxima;
        lista->ultimo->proxima = nova;
    }
    lista->ultimo = nova;
    lista->tamanho++;
}

int todas_cheias(ListaCircular *lista) 
{
    Nave *atual = lista->ultimo->proxima;
    for (int i = 0; i < lista->tamanho; i++) 
    {
        if (atual->combustivelATUAL < atual->capacidadeMAX)
        {
            return 0;
        }
        atual = atual->proxima;
    }
    return 1;
}

void liberar_lista(ListaCircular *lista) 
{
    if (!lista->ultimo) return;
    Nave *atual = lista->ultimo->proxima;
    Nave *temp;
    for (int i = 0; i < lista->tamanho; i++) 
    {
        temp = atual;
        atual = atual->proxima;
        free(temp);
    }
    lista->ultimo = NULL;
    lista->tamanho = 0;
}
