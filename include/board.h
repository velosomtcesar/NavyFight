#ifndef BOARD_H
#define BOARD_H

#define BOARD_SIZE 5

typedef struct {
    char **grade;
} Tabuleiro;

Tabuleiro *criar_tabuleiro(); 
void inicializar_tabuleiro(Tabuleiro *tabuleiro);
void imprimir_tabuleiro(const Tabuleiro *tabuleiro);
void liberar_tabuleiro(Tabuleiro *tabuleiro); 

#endif 