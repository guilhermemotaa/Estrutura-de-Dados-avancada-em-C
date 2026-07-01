#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
 
int main() 
{
    Lista *lista;
    lista = inicializa();
 
    int pessoas, valor;
    printf("Quantas pessoas? : ");
    scanf("%d", &pessoas);
    printf("Valor sorteado: ");
    scanf("%d", &valor);
 
    No *no1 = NULL;
    for (int i = 1; i <= pessoas; i++) 
    {
        insere_inicio(lista, i);
        if (i == 1) 
        {
            no1 = lista->cabeca;
        }
    }
 
    int lider = escolhe_lider(lista, no1, valor);
    printf("O lider eh : %d\n", lider);
 
    libera_lista(lista);
}