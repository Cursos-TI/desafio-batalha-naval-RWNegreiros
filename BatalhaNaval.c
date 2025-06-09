#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    // Declaração da matriz que representa o tabuleiro 10x10
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas iniciais do navio horizontal
    int linha_h = 2;
    int coluna_h = 4;

    // Verifica se o navio horizontal cabe no tabuleiro
    if (coluna_h + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // Verifica se há sobreposição com outro navio
        int pode_posicionar = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_h][coluna_h + i] != AGUA) {
                pode_posicionar = 0;
                break;
            }
        }

        // Posiciona o navio horizontal se possível
        if (pode_posicionar) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_h][coluna_h + i] = NAVIO;
            }
        } else {
            printf("Erro: sobreposição detectada para navio horizontal.\n");
            return 1;
        }
    } else {
        printf("Erro: navio horizontal fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Coordenadas iniciais do navio vertical
    int linha_v = 5;
    int coluna_v = 6;

    // Verifica se o navio vertical cabe no tabuleiro
    if (linha_v + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // Verifica se há sobreposição com outro navio
        int pode_posicionar = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_v + i][coluna_v] != AGUA) {
                pode_posicionar = 0;
                break;
            }
        }

        // Posiciona o navio vertical se possível
        if (pode_posicionar) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_v + i][coluna_v] = NAVIO;
            }
        } else {
            printf("Erro: sobreposição detectada para navio vertical.\n");
            return 1;
        }
    } else {
        printf("Erro: navio vertical fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Exibe o tabuleiro no console
    printf("\nTabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
