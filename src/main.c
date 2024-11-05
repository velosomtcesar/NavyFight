#include <stdio.h>
#include "keyboard.h"
#include "screen.h"
#include "timer.h"
#include "../include/board.h"
#include "../include/game.h"

int main() {
    initialize_screen(); 
    initialize_keyboard(); 
    initialize_timer(); 

    char comando;
    int jogo_ativo = 1;
    while (jogo_ativo) {
        comando = get_keyboard_input();
        switch(comando) {
            case 'Q': 
                jogo_ativo = 0;
                break;
            case ' ': 
                attack_position(); 
                break;
            case 'R': 
                reset_game(); 
                break;
            case 'H': 
                show_help(); 
                break;
            case '↑': 
                move_cursor('pra cima'); 
                break;
            case '↓': 
                move_cursor('pra baixo');
                break;
            case '←': 
                move_cursor('esquerda');
                break;
            case '→': 
                move_cursor('direita');
                break;
        }
        render_screen(); 
        delay_frame(); 
    }
    shutdown_screen();
    shutdown_keyboard();
    shutdown_timer();
    Tabuleiro *tabuleiro = criar_tabuleiro(); 
    inicializar_tabuleiro(tabuleiro); 
    posicionar_navios(tabuleiro); 

    printf("Bem-vindo ao NAVY FIGHT!\n"); 
    iniciar_jogo(tabuleiro); 

    liberar_tabuleiro(tabuleiro); 
    return 0;
}