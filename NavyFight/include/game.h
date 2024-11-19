
#ifndef GAME_H
#define GAME_H

#define BOARD_SIZE 5

typedef struct {
    char** tabuleiro; // Tabuleiro alocado dinamicamente
    int navios_restantes; // Número de navios restantes
} Jogador;

// Funções principais do jogo
void inicializar_tabela(Jogador* jogador);
void mostrar_tabela(const Jogador* jogador, int numero_jogador, const char* phase);
int  feedback_acerto_erroMecanica(Jogador* oponente, int x, int y);
void free_board(Jogador* jogador);

#endif
