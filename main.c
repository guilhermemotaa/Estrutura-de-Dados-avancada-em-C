#include <stdio.h>
#include <stdlib.h>
#include "descritor.h"


int main ()
{
    //demonstracao de todas as funcoes sendo usadas :)//
    Descritor *sla;
    sla = criaLista ();
    inicializarlista(sla);
    inserirInicio (sla,5);
    inserirInicio (sla,4);
    inserirInicio (sla,3);
    inserirFinal (sla,6);
    inserirFinal (sla,7);
    removerInicio (sla);
    removerFinal (sla);
    removerElemento (sla,5);
    exibirLista (sla);
    //resultado final deve ser : quantidade: 2 e lista: 4 6//
}