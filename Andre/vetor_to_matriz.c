#include <stdio.h>
int linhas, colunas, tamanho;

void definir_tamanho(int linha, int coluna) {
    linhas = linha;
    colunas = coluna;
    tamanho = linhas * colunas;
}

void adicionar_elemento(int vetor[], int valor, int linha, int coluna){

    vetor[(linha-1) * colunas + (coluna - 1)] = valor;

}
int buscar_elemento(int vetor[], int linha, int coluna){
    return vetor[((linha-1) * colunas + (coluna - 1))];
}
void zerar_matriz(int vetor[]) {
    for (int i = 1; i <= linhas; i++){
        for(int j= 1; j <= colunas; j ++){
            adicionar_elemento(vetor,0, i, j);
        }
    }
}

void imprimir_matriz(int vetor[]) {
    for (int i = 1; i <= linhas; i++) {
        for (int j = 1; j <= colunas; j++) {
            int val = buscar_elemento(vetor, i, j);
            printf("%d ", val);
        }
        printf("\n");
    }
}

int main(){
    int linha, coluna;
    printf("Digite o numero de linhas: ");
    scanf("%d", &linha);   
    printf("Digite o numero de colunas: ");
    scanf("%d", &coluna);
    definir_tamanho(linha, coluna);
    int vetor[tamanho];
    zerar_matriz(vetor);
    printf("Matriz zerada:\n");
    imprimir_matriz(vetor);
    adicionar_elemento(vetor, 35, 1, 3);
    adicionar_elemento(vetor, 25, 2, 2);
    adicionar_elemento(vetor, 15, 3, 1);
    printf("Matriz pos alteracao: \n\n");
    imprimir_matriz(vetor);

    return 0;
}