
#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "keyboard.h"
#include "screen.h"

void display_menu() {
    screenClear(); // Limpar a tela - cli-lib
    printf("\n--- BATALHA NAVAL ---\n");
    printf("1. Começar Jogo\n");
    printf("2. Sair\n");
    printf("Escolha uma opção: ");
    fflush(stdout); // Comando padrao de C para limpar o terminal e apresentar o printf sem erros
    screenUpdate(); // Atualizar a tela - cli-lib
}

int opcao_teclado() {
    screenClear();
    display_menu(); // Chama o menu principal
    int opcao = -1;
    while (opcao != 1 && opcao != 2) {         
        while (!keyhit()) { /* Esperar para acionamento de tecla */ } 
        opcao = readch() - '0'; // Converte para digito atual, digito - 0 do ASCII 
        if (opcao != 1 && opcao != 2) {
            screenClear();
            display_menu();
            printf("\nOpção inválida! Tente novamente.\n");
            display_menu();
            fflush(stdout);
        }
    }
    return opcao;
}

int coordenada_teclado(char* prompt, int board_size) {  //Utilizar o teclado para os digitos nas coordenadas da linha e coluna
    int coord = -1; // Zerar a coordenada
    while (coord < 0 || coord >= board_size) {  // Verifica se eh maior que 0 ou maior que o tamanho da tabela
        printf("%s (0 a %d): ", prompt, board_size - 1); // board-size - 1 para mostrar no printf o tamanho correto da tabela
        fflush(stdout);
        while (!keyhit()) { /* Esperar para acionamento de tecla */ }
        coord = readch() - '0'; // Converte para digito atual, digito - 0 do ASCII = numero desejado
        if (coord < 0 || coord >= board_size) {
            printf("Entrada inválida. Tente novamente.\n");
            fflush(stdout);
        }
    }
    return coord;
}

void pausa_tabela() {    //Pausa para o feedback das tabelas
    printf("Pressione qualquer tecla para continuar...\n");
    fflush(stdout);
    while (!keyhit()) { /* Esperar para acionamento de tecla */ }
    readch(); // Aceita o digito
}

void turno_jogador(int turno) { // Turno do jogador atual
    printf("\n--- Turno do Jogador %d ---\n", turno);
    printf("Jogador %d está atacando.\n", turno);  
    fflush(stdout);
}

void feedback_acerto_erroTela(int ataque) { // Feedback de acerto ou erro
    if (ataque) {
        printf("Levou um pra Deus!\n");
    } else {
        printf("É agua papai!\n");
    }
    fflush(stdout);
    pausa_tabela();
}

int main() {
    int opcao;
    Jogador jogador1, jogador2;
    int x, y, turno = 1; // 1 para jogador 1, 2 para jogador 2, iniciando com jogador 1 

    keyboardInit(); // Iniciando acionamento de teclado - cli-lib
    screenInit(1); // Iniciar o sistema de renderizacao de tela com cor - cli-lib

    inicializar_tabela(&jogador1); // Inicializar tabela do jogador 1(Para mais info ver no game.h e game.c como funcionam)
    inicializar_tabela(&jogador2);// Inicializar tabela do jogador 2(Para mais info ver no game.h e game.c como funcionam)

    while (1) {
        display_menu(); // Chama o menu
        opcao = opcao_teclado(); // Usa o teclado para o menu
        if (opcao == 1) break;
        if (opcao == 2) exit(0); // exit(0) para finalizar o programa normalmente
    }

    // Loop do Jogo
    while (jogador1.navios_restantes > 0 && jogador2.navios_restantes > 0) { // Para iniciar o jogo os 2 tem que ter os navios restantes maiores que 0
        Jogador* oponente = (turno == 1) ? &jogador2 : &jogador1; 
        // Verifica a condicao do turno == 1 com operador ternario, se for verdadeiro retorna o endereco de jogador 2
        // E se for falso retorna o endereco do jogador 1, mantendo o turno alternado

        turno_jogador(turno);
        fflush(stdout);
        printf("Tabuleiro do Jogador %d:\n", (turno == 1) ? 2 : 1); // Informa o tabuleiro que esta no momento
        mostrar_tabela(oponente, 2, "Visualização"); // Tabela do oponente antes do ataque  //  

        x = coordenada_teclado("Informe a linha para explodir o jogador", BOARD_SIZE);
        y = coordenada_teclado("Informe a coluna para explodir o jogador", BOARD_SIZE);

        int ataque = feedback_acerto_erroMecanica(oponente, x, y);
        feedback_acerto_erroTela(ataque); // Confere se acertou ou nao o ataque

        mostrar_tabela(oponente, 2, "Atualização"); // Atualiza a tabela do oponente
        pausa_tabela(); // Pausa para ver a tabela do oponente

        turno = (turno == 1) ? 2 : 1; // Troca de turnos, verifica se o turno 1 eh verdadeiro com isso troca para 2 e vice versa com o operador ?
    }

    printf("\n--- Fim de partida! ---\n");
    if (jogador1.navios_restantes == 0) printf("Jogador 2 wins!\n");
    else printf("Jogador 1 wins!\n");
    fflush(stdout);

    keyboardDestroy();// Finalizar a interacao de teclado com terminal - cli-lib
    return 0;
}
