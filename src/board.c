#include "../include/board.h"
#include <stdio.h>
#include <stdlib.h>

Tabuleiro *criar_tabuleiro() {
    Tabuleiro *tabuleiro = (Tabuleiro *)malloc(sizeof(Tabuleiro));
    tabuleiro->grade = (char **)malloc(BOARD_SIZE * sizeof(char *));
    for (int i = 0; i < BOARD_SIZE; i++) {
        tabuleiro->grade[i] = (char *)malloc(BOARD_SIZE * sizeof(char));
    }
    return tabuleiro;
}

void inicializar_tabuleiro(Tabuleiro *tabuleiro) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            tabuleiro->grade[i][j] = '.'; 
        }
    }
}

void imprimir_tabuleiro(const Tabuleiro *tabuleiro) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", tabuleiro->grade[i][j]); 
        }
        printf("\n");
    }
}

void liberar_tabuleiro(Tabuleiro *tabuleiro) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        free(tabuleiro->grade[i]); 
    }
    free(tabuleiro->grade); 
    free(tabuleiro); 
}

