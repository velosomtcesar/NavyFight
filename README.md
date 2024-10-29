# NavyFight
Projeto para a cadeira de Programação Imperativa e Funcional.
Instituição: Cesar School
Curso: Sistemas de informação.

Membros: Caio, Cauê, Matheus Veloso e Cesar.

NavyFight é uma versão simplificada do clássico jogo de Batalha Naval. 
O jogador deve adivinhar a posição dos navios inimigos em um tabuleiro 5x5, onde cada célula representa um ponto do oceano. 
O objetivo é acertar todas as posições dos navios antes de esgotar as tentativas.


Nossas regras:
  -O jogo inicia com um tabuleiro de tamanho 5x5, e três navios são posicionados em locais aleatórios.
  -O jogador insere as coordenadas (linha e coluna) para disparar um tiro.
  -Se o jogador acertar a posição de um navio, um "X" é exibido na célula; se errar, um "O" aparece.
  -O jogo termina quando todos os navios forem afundados, ou se o jogador desejar sair.
  -Compile com o comando no terminal: gcc -o guess guess.c

Interação:
  -O jogo exibe o tabuleiro e solicita que o jogador insira as coordenadas para atirar.
  -O jogador deve inserir as coordenadas no formato linha coluna (por exemplo, 2 3 para a linha 2, coluna 3).
  -Após cada tentativa, o jogo exibe o estado atualizado do tabuleiro e a pontuação do jogador.

Compilação com os comandos "make" e "./build/naval" .
