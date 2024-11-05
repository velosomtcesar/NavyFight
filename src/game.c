#include "../include/game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void posicionar_navios(Tabuleiro *tabuleiro) {
    tabuleiro->grade[1][1] = 'N'; 
    tabuleiro->grade[3][2] = 'N'; 
}

void iniciar_jogo(Tabuleiro *tabuleiro) {
    int linha, coluna;
    int acertos = 0; 
    int total_navios = 2; 

    while (acertos < total_navios) {
        imprimir_tabuleiro(tabuleiro);
        printf("Digite as coordenadas (linha e coluna): ");
        scanf("%d %d", &linha, &coluna); 

        if (linha < 0 || coluna < 0 || linha >= BOARD_SIZE || coluna >= BOARD_SIZE) {
            printf("Coordenadas inválidas. Digite de novo!.\n");
            continue; 
        }

        if (tabuleiro->grade[linha][coluna] == 'N') {
            printf("Acertou um navio!\n");
            tabuleiro->grade[linha][coluna] = 'X'; 
            acertos++; 
        } else if (tabuleiro->grade[linha][coluna] == 'O') {
            printf("Você já digitou essas coordenadas. Digite de novo.\n");
        } else {
            printf("Água!\n");
            tabuleiro->grade[linha][coluna] = 'O'; 
        }
    }
    printf("Você afundou todos!!!!\n"); 
}