# NavyFight
Projeto para a cadeira de Programação Imperativa e Funcional - 2024.2.
Instituição: CESAR School.
Curso: Sistemas de informação.

Membros: Caio Felipe(cfsr@cesar.school / cfsr-school), Cauê Prado(cpb@cesar.school / CauePrad0), Matheus Veloso(mvst@cesar.school / velosomtcesar).

NavyFight é uma versão simplificada do jogo Batalha Naval. 
O jogador deve adivinhar a posição dos navios dos inimigos( insirindo as coordenadas) em um tabuleiro 5x5 onde cada célula representa um ponto do oceano. 
O objetivo é acertar todas as posições dos navios antes de acabar as tentativas.


Mecânica atual:

  Teclas:
  Sair do Jogo - Q
  Espaco - Confirmar Ataque
  Navegação - Setas
  Reiniciar Jogo - R
  Exibir ajuda Comandos - H

# Ideia Principal
  Em NavyFight, você é um comandante em uma missão de eliminar os navios adversários que estão camuflados no oceano. O jogo é baseado em tentativas: você deve acertar as coordenadas de cada navio antes de ficar sem chances de ataque. A cada rodada, você terá um feedback   visual para entender se está acertando o alvo ou apenas atingindo a água.

# Como o Jogo Funciona
  Tabuleiro: O tabuleiro é uma grade de 5x5 onde cada célula começa marcada com um ponto (.) que representa uma posição não escolhida ainda.
  Posicionamento dos Navios: Existem dois navios escondidos em posições específicas, mas elas são desconhecidas para você.
  Ações do Jogador: Você ataca inserindo coordenadas (linha e coluna) para tentar acertar os navios. (Exemplo: 1 1)


# Mecânica do Jogo
  1- Ataque: Insira as coordenadas de ataque no formato linha coluna e pressione Espaço para confirmar.
  2- Feedback Visual:
    Se você acertar um navio, o ponto da célula muda para X, indicando um acerto.
    Se errar e atingir a água, o ponto muda para O.
    Caso você já tenha atacado aquela posição, o jogo avisa e permite escolher outra coordenada.
  3- Condições de Vitória: O jogo continua até que você afunde todos os navios ou acabe suas tentativas. Ao afundar todos, uma mensagem de vitória é exibida
  
# Controles
  Use os seguintes comandos para navegar e interagir com o jogo:
  
    Q: Sair do jogo
    Espaço: Confirmar ataque na coordenada selecionada
    Setas direcionais: Navegar pelo tabuleiro para selecionar coordenadas
    R: Reiniciar o jogo
    H: Exibir ajuda e comandos
  
VAMOS DERRUBAR NAVIOS!



