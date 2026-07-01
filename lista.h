#ifndef _LISTA_H
#define _LISTA_H

typedef struct 
{
    int id;
    int capacidadeMAX;
    int combustivelATUAL;
    struct Nave *proxima;
} Nave;


typedef struct 
{
    Nave *ultimo;
    int tamanho;
} ListaCircular;

ListaCircular *inicializar_lista();
Nave *criar_nave(int id, int capacidade, int combustivel);
void inserir_fim(ListaCircular *lista, int id, int capacidade, int combustivel);
int todas_cheias(ListaCircular *lista);
void liberar_lista(ListaCircular *lista);


#endif