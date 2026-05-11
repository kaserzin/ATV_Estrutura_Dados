#include <stdio.h>
#include "pilhaEstatica.h"

int pilha[TAM];
int topoEstatico = -1;

// Adicionar elemento
void adicionarElementoEstatica(int valor) {

    if (topoEstatico == TAM - 1) {
        printf("Pilha estatica cheia \n");
        return;
    }

    topoEstatico++;
    pilha[topoEstatico] = valor;
}

// Remover elemento
void removerElementoEstatica() {

    if (topoEstatico == -1) {
        printf("Pilha estatica vazia \n");
        return;
    }

    printf("Removido da pilha estatica: %d\n", pilha[topoEstatico]);

    topoEstatico--;
}

// Mostrar pilha
void mostrarPilhaEstatica() {

    if (topoEstatico == -1) {
        printf("Pilha estatica vazia \n");
        return;
    }

    printf("\nPilha Estatica:\n");

    for (int i = topoEstatico; i >= 0; i--) {
        printf("%d\n", pilha[i]);
    }
}

// Limpar pilha
void limparPilhaEstatica() {

    topoEstatico = -1;

    printf("Pilha estatica limpa \n");
}