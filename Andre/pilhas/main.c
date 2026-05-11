#include <stdio.h>
#include <conio.h>
#include "pilhaEstatica.h"
#include "pilhaDinamica.h"

int main() {
    // estatica

    adicionarElementoEstatica(10);
    adicionarElementoEstatica(20);
    adicionarElementoEstatica(30);

    mostrarPilhaEstatica();
    removerElementoEstatica();
    mostrarPilhaEstatica();
    limparPilhaEstatica();
    mostrarPilhaEstatica();
    //dinamica

    adicionarElementoDinamica(100);
    adicionarElementoDinamica(200);
    adicionarElementoDinamica(300);

    mostrarPilhaDinamica();
    removerElementoDinamica();
    mostrarPilhaDinamica();
    limparPilhaDinamica();
    mostrarPilhaDinamica();

    getch();
    return 0;
}