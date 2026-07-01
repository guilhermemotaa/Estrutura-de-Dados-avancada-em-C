#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int pesquisa_binaria(int* vetor,int chave,int tamanho)
{
    int l=0,r=tamanho-1;
    while (l<=r)
    {
        int m=(l+r)/2;
        if (*(vetor+m)==chave)
        {
            return m;
        }
        else if (*(vetor+m)<chave)
        {
            l=m+1;
        }
        else if (*(vetor+m)>chave)
        {
            r=m-1;
        }
    }
    return -1;

}


int main ()
{
   int chave,tamanho;
   scanf ("%d",&chave);
   scanf ("%d",&tamanho);
   int v[tamanho];
   for (int i=0;i<tamanho;i++)
   {
    scanf ("%d",&v[i]);
   }
   int x = pesquisa_binaria(v,chave,tamanho);
   printf ("%d",x);
}