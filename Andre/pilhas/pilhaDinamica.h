#ifndef PILHADINAMICA_H
#define PILHADINAMICA_H

struct No {
    int valor;
    struct No *proximo;
};

void adicionarElementoDinamica(int valor);
void removerElementoDinamica();
void mostrarPilhaDinamica();
void limparPilhaDinamica();

#endif