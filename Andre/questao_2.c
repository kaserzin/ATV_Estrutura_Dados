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
int comparar_matrizes(int vetor1[], int mat[]){
    for(int i = 1; i <= linhas; i++){
        for(int j = 1; j <= colunas; j++){
            int val1 = buscar_elemento(vetor1, i, j);
            int val2 = buscar_elemento(mat, i, j);
            if(val1 != val2) return 0;
        }
    }
    return 1;
}
void multiplicar_matrizes(int A[], int B[], int C[]) {
    for (int i = 1; i <= linhas; i++) {
        for (int j = 1; j <= colunas; j++) {

            int soma = 0;

            for (int k = 1; k <= colunas; k++) {
                int a = buscar_elemento(A, i, k);
                int b = buscar_elemento(B, k, j);
                soma += a * b;
            }

            adicionar_elemento(C, soma, i, j);
        }
    }
}
void gerar_identidade(int vetor[]) {
    for (int i = 1; i <= linhas; i++) {
        for (int j = 1; j <= colunas; j++) {

            if (i == j) {
                adicionar_elemento(vetor, 1, i, j);
            } else {
                adicionar_elemento(vetor, 0, i, j);
            }

        }
    }
}
int verificar_inversa(int A[], int B[]) {
    int produto[tamanho], identidade[tamanho];

    zerar_matriz(produto);
    zerar_matriz(identidade);

    multiplicar_matrizes(A, B, produto);
    gerar_identidade(identidade);

    return comparar_matrizes(produto, identidade);
}
int main(){
    int linha, coluna;

    printf("Digite o numero de linhas: ");
    scanf("%d", &linha);   

    printf("Digite o numero de colunas: ");
    scanf("%d", &coluna);

    definir_tamanho(linha, coluna);
    
    int vetorA[tamanho], vetorB[tamanho];

    zerar_matriz(vetorA); zerar_matriz(vetorB);

    adicionar_elemento(vetorA, 1, 1, 1);
    adicionar_elemento(vetorA, 2, 1, 2);
    adicionar_elemento(vetorA, 3, 2, 1);
    adicionar_elemento(vetorA, 4, 2, 2);

    adicionar_elemento(vetorB, 1, 1, 1);
    adicionar_elemento(vetorB, 0, 1, 2);
    adicionar_elemento(vetorB, 0, 2, 1);
    adicionar_elemento(vetorB, 1, 2, 2);

    printf("\nMatriz A:\n");
    imprimir_matriz(vetorA);

    printf("\nMatriz B:\n");
    imprimir_matriz(vetorB);

    if (eh_inversa(vetorA, vetorB)) {
        printf("B eh inversa de A\n");
    } else {
        printf("B nao eh inversa de A\n");
    }

    return 0;
}
