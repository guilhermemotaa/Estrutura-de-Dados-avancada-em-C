#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


int main() {
     int n, qtd;
    ListaCircular *frota;
    frota = inicializar_lista();
 
    printf("Naves: ");
    scanf("%d", &n);
 
    int *capacidades = malloc(n * sizeof(int));
    int *combustiveis = malloc(n * sizeof(int));
 
    printf("Capacidades: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &capacidades[i]);
    }
 
 
    printf("Combustiveis iniciais: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &combustiveis[i]);
    }
    printf("Combustivel por ciclo: ");
    scanf("%d", &qtd);
 
    for (int i = 0; i < n; i++)
    {
        inserir_fim(frota, i + 1, capacidades[i], combustiveis[i]);
    }

    free(capacidades);
    free(combustiveis);
 
    Nave *atual = frota->ultimo->proxima;
    int ciclo = 0;
 
    while (!todas_cheias(frota)) 
    {
        ciclo++;
 
        if (atual->combustivelATUAL < atual->capacidadeMAX) 
        {
            int espaco = atual->capacidadeMAX - atual->combustivelATUAL;
            int add    = (qtd < espaco) ? qtd : espaco;
            atual->combustivelATUAL += add;
 
            if (atual->combustivelATUAL == atual->capacidadeMAX)
            {
                printf("Ciclo %d - Nave %d cheia (%d/%d)\n",ciclo, atual->id,atual->combustivelATUAL, atual->capacidadeMAX);
            }

        }
 
        atual = atual->proxima;
    }
 
    printf("\nTotal: %d ciclos\n", ciclo);
 
    liberar_lista(frota);
    return 0;

}