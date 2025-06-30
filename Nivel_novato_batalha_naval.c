//  DISCIPLINA: Introdução à Programação de Computadores, Programando em C.
//  Desafio: Posicionando Navios no Tabuleiro (Nível Novato)
//  Objetivo: Representar um tabuleiro de Batalha Naval com dois navios posicionados corretamente.
//  Autor: Hermesson Yuri
//  Professor: Nathan - Sergio Cardoso
//  Data: 30/06/2025
//  GitHub: https://github.com/hermessonyurii
//  Detalhes: Este programa utiliza matrizes e vetores em C para criar um tabuleiro 10x10, 
//  posicionando dois navios (um na horizontal e outro na vertical) sem sobreposição e
//  exibindo o tabuleiro de forma clara no console.

#include <stdio.h>

// Define o tamanho do tabuleiro e o comprimento dos navios
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro preenchendo todas as posições com água (valor 0)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas iniciais fixas para o navio horizontal
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    // Coordenadas iniciais fixas para o navio vertical
    int linha_vertical = 5;
    int coluna_vertical = 1;

    // Validação: garantir que os navios cabem no tabuleiro e não se sobrepõem
    int sobreposicao = 0;

    // Verifica se o navio horizontal está dentro dos limites
    if (coluna_horizontal + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal excede os limites do tabuleiro.\n");
        return 1;
    }

    // Verifica se o navio vertical está dentro dos limites
    if (linha_vertical + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio vertical excede os limites do tabuleiro.\n");
        return 1;
    }

    // Verifica sobreposição entre os navios
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha_horizontal][coluna_horizontal + i] == NAVIO ||
            tabuleiro[linha_vertical + i][coluna_vertical] == NAVIO ||
            (linha_horizontal == linha_vertical + i && coluna_horizontal + i == coluna_vertical)) {
            sobreposicao = 1;
        }
    }

    if (sobreposicao) {
        printf("Erro: Os navios se sobrepõem.\n");
        return 1;
    }

    // Posiciona o navio horizontalmente no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = NAVIO;
    }

    // Posiciona o navio verticalmente no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = NAVIO;
    }

    // Exibe o tabuleiro completo com formatação
    printf("\nTabuleiro de Batalha Naval:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}