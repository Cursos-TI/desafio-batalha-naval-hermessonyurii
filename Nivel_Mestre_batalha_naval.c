// DISCIPLINA: Introdução à Programação de Computadores, Programando em C.
// Desafio: Habilidades Especiais no Tabuleiro (Nível Mestre)
// Objetivo: Gerar matrizes que simulem padrões de habilidades (cone, cruz, octaedro) com base em loops aninhados.
// Autor: Hermesson Yuri
// Professor: Nathan
// Data: 30/06/2025
// GitHub: https://github.com/hermessonyurii
// Detalhes: O programa exibe matrizes com padrões específicos representando áreas atingidas por habilidades especiais.

#include <stdio.h>
#include <stdlib.h> // Para a função abs() basei por aqui tive uma explicão na prática - fonte: https://www.ibm.com/docs/pt-br/i/7.6.0?topic=files-stdlibh

#define TAMANHO 5  // Tamanho padrão para as matrizes de habilidades (deve ser ímpar)

// Função para exibir uma matriz na tela
void exibir_matriz(int matriz[TAMANHO][TAMANHO], const char *nome) {
    printf("\nPadrão: %s\n\n", nome);
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para preencher o padrão de cone
void preencher_cone(int matriz[TAMANHO][TAMANHO]) {
    // Limpa a matriz
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            matriz[i][j] = 0;
        }
    }

    int meio = TAMANHO / 2;
    for (int i = 0; i <= meio; i++) {
        for (int j = meio - i; j <= meio + i; j++) {
            if (j >= 0 && j < TAMANHO) {
                matriz[i][j] = 1;
            }
        }
    }
}

// Função para preencher o padrão de cruz
void preencher_cruz(int matriz[TAMANHO][TAMANHO]) {
    int meio = TAMANHO / 2;
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            matriz[i][j] = (i == meio || j == meio) ? 1 : 0;
        }
    }
}

// Função para preencher o padrão de octaedro
void preencher_octaedro(int matriz[TAMANHO][TAMANHO]) {
    // Limpa a matriz
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            matriz[i][j] = 0;
        }
    }

    int meio = TAMANHO / 2;
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (abs(i - meio) + abs(j - meio) <= meio) {
                matriz[i][j] = 1;
            }
        }
    }
}

int main() {
    // Verifica se o tamanho é ímpar
    if (TAMANHO % 2 == 0) {
        printf("Erro: O tamanho da matriz deve ser ímpar para padrões simétricos.\n");
        return 1;
    }

    int matriz_cone[TAMANHO][TAMANHO];
    int matriz_cruz[TAMANHO][TAMANHO];
    int matriz_octaedro[TAMANHO][TAMANHO];

    // Preenche os padrões
    preencher_cone(matriz_cone);
    preencher_cruz(matriz_cruz);
    preencher_octaedro(matriz_octaedro);

    // Exibe os padrões no console
    exibir_matriz(matriz_cone, "Cone");
    exibir_matriz(matriz_cruz, "Cruz");
    exibir_matriz(matriz_octaedro, "Octaedro");

    return 0;
}