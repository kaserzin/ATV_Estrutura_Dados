#include <stdio.h>
#include <stdlib.h>
#include "pilhaDinamica.h"

// TopoDinamico da pilha
struct No *topoDinamico = NULL;

// Adicionar elemento
void adicionarElementoDinamica(int valor) {

    struct No *novo = malloc(sizeof(struct No));

    novo->valor = valor;
    novo->proximo = topoDinamico;

    topoDinamico = novo;
}

// Remover elemento
void removerElementoDinamica() {

    if (topoDinamico == NULL) {
        printf("Pilha dinamica vazia\n");
        return;
    }

    struct No *temp = topoDinamico;

    printf("Removido da pilha dinamica: %d\n", topoDinamico->valor);

    topoDinamico = topoDinamico->proximo;

    free(temp);
}

// Mostrar pilha
void mostrarPilhaDinamica() {

    struct No *atual = topoDinamico;

    if (atual == NULL) {
        printf("Pilha dinamica vazia\n");
        return;
    }

    printf("\nPilha Dinamica:\n");

    while (atual != NULL) {
        printf("%d\n", atual->valor);
        atual = atual->proximo;
    }
}

// Limpar pilha
void limparPilhaDinamica() {

    struct No *temp;

    while (topoDinamico != NULL) {
        temp = topoDinamico;
        topoDinamico = topoDinamico->proximo;
        free(temp);
    }

    printf("Pilha dinamica limpa\n");
}