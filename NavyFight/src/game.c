
#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "screen.h"

void inicializar_tabela(Jogador* jogador) { // Gera a tabela e inicializa 
    jogador->tabuleiro = (char**)malloc(BOARD_SIZE * sizeof(char*)); 
    // Aloca o tamanho da memoria para armazenar BOARD_SIZE linhas
    // Cada linha eh um ponteiro para um array char* sendo uma linha no tabuleiro
    for (int i = 0; i < BOARD_SIZE; i++) {
        jogador->tabuleiro[i] = (char*)malloc(BOARD_SIZE * sizeof(char));
        for (int j = 0; j < BOARD_SIZE; j++) {
            jogador->tabuleiro[i][j] = '-'; // Inicia para que todos os pontos sejam '-'
        }
    }
    // Posicionar navios fixos (exemplo para testes)
    jogador->tabuleiro[1][1] = 'S';
    jogador->tabuleiro[2][3] = 'S';
    jogador->tabuleiro[4][0] = 'S'; // Navios posicionados manualmente
    jogador->navios_restantes = 3;  // Configura para que o jogador tenha inicialmente 3 navios
} 

void mostrar_tabela(const Jogador* jogador, int numero_jogador, const char* phase) { // Mostrar a tabela no terminal
    screenSetColor(RED, BLACK); // Configura cor do texto - cli-lib
printf("\n-------------NAVYFIGHT--------\n");
screenSetNormal(); // Mostrar tela normal - cli-lib
screenUpdate(); // Atualizar a tela - cli-lib
printf("Pressione qualquer tecla para continuar...");
getchar(); // Confirmar tecla 

    screenClear();
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i); // Exibir o indice das colunas da primeira linha
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i); // Exibe o indice da linha de inicio
        for (int j = 0; j < BOARD_SIZE; j++) {
            char unidade = jogador->tabuleiro[i][j];
            if (unidade == 'S') {  // Se o ponto tiver S ela eh exibida com o caractere '-' para esconder
                printf("- "); 
            } else {
                printf("%c ", unidade); // Transforma o cell somente no caractere - para ser agua 
            }
        }
        printf("\n");
    }
    screenUpdate();
}

int feedback_acerto_erroMecanica(Jogador* jogador, int x, int y) {
    if (jogador->tabuleiro[x][y] == 'S') {    
        jogador->tabuleiro[x][y] = 'X'; // Marca acerto
        jogador->navios_restantes--;
        return 1; // Acerto
    } else if (jogador->tabuleiro[x][y] == '-') {
        jogador->tabuleiro[x][y] = 'O'; // Marca erro
        return 0; // Erro
    }
    return 0; // Tentativa repetida ou inválida
}
