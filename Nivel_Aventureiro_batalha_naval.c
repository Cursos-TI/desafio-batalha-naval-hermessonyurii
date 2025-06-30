//  DISCIPLINA: Introdução à Programação de Computadores, Programando em C.
//  Desafio: Posicionando Navios no Tabuleiro (Nível Aventureiro)
//  Objetivo: Representar um tabuleiro 10x10 com quatro navios posicionados — horizontal, vertical e dois em diagonal — evitando sobreposição.
//  Autor: Hermesson Yuri
//  Professor: Nathan
//  Data: 30/06/2025
//  GitHub: https://github.com/hermessonyurii
//  Detalhes: O programa posiciona quatro navios em uma matriz 10x10, valida posições e exibe visualmente o tabuleiro no console.

#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função auxiliar para verificar sobreposição e preencher o navio
int posicionar_navio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int l, int c, int direcao_linha, int direcao_coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int nova_linha = l + i * direcao_linha;
        int nova_coluna = c + i * direcao_coluna;

        // Verificação de limites
        if (nova_linha >= TAMANHO_TABULEIRO || nova_coluna >= TAMANHO_TABULEIRO || nova_coluna < 0) {
            printf("Erro: Navio fora dos limites do tabuleiro.\n");
            return 1;
        }

        // Verifica sobreposição
        if (tabuleiro[nova_linha][nova_coluna] == NAVIO) {
            printf("Erro: Sobreposição de navios detectada.\n");
            return 1;
        }
    }

    // Posicionamento seguro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int nova_linha = l + i * direcao_linha;
        int nova_coluna = c + i * direcao_coluna;
        tabuleiro[nova_linha][nova_coluna] = NAVIO;
    }
    return 0;
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas dos 4 navios: horizontal, vertical, diagonal principal, diagonal secundária
    int linha_h = 1, coluna_h = 2;
    int linha_v = 4, coluna_v = 6;
    int linha_d1 = 0, coluna_d1 = 0;
    int linha_d2 = 0, coluna_d2 = 9;

    // Posiciona os navios
    if (posicionar_navio(tabuleiro, linha_h, coluna_h, 0, 1)) return 1;    // Horizontal
    if (posicionar_navio(tabuleiro, linha_v, coluna_v, 1, 0)) return 1;    // Vertical
    if (posicionar_navio(tabuleiro, linha_d1, coluna_d1, 1, 1)) return 1;  // Diagonal principal
    if (posicionar_navio(tabuleiro, linha_d2, coluna_d2, 1, -1)) return 1; // Diagonal secundária

    // Exibe o tabuleiro
    printf("\nTabuleiro - Nível Aventureiro:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}