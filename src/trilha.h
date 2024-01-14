#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <chrono>

#include "estado.h"

#define NUM_VERTICES 24
#define NUM_PECAS 18
#define NUM_PECAS_JOGADOR 9

class Trilha
{
private:
    char pecas[2] = {'X', 'O'};
    std::map<int, std::vector<int>> grafo;
    Estado estado_atual;
    std::map<char, int> movimentos;
    std::map<char, int> tempo_de_busca;

    //0 - X
    //1 - O
    int profundidade[2];
    
    int verifica_impar(Estado& estado, int i, char peca);
    int verifica_par(Estado& estado, int i, char peca);
    int verifica_tripla(Estado& estado, char peca, int pos);
    int utilidade(Estado& estado, char peca, int fromPos, int toPos);
    std::map<int, std::vector<int>> lista_acoes_livre(Estado& estado);
    std::map<int, std::vector<int>> lista_acoes_restrita(Estado& estado);
    bool teste_termino(Estado& estado, bool inicio  = false);
    int valor_min(Estado& estado, int peca, int profundidade, int fromPos, int toPos, int minimo, int max);
    int valor_max(Estado& estado, int peca, int profundidade, int fromPos, int toPos, int minimo, int max);
    Estado movimenta_peca(Estado& estado, char peca, int fromPos, int toPos);
    Estado movimenta_peca_manualmente(Estado& estado, char peca, int fromPos, int toPos);
    Estado adiciona_peca(Estado& estado, char peca);
    void remove_peca(Estado& estado, char peca);
    Estado adiciona_peca_manualmente(Estado& estado, char peca, int pos);
    void remove_peca_manualmente(Estado& estado, char peca);
    std::tuple<int, int, int> decisao_minimax(Estado& estado, int peca, int profundidade);
    void printa_jogo(Estado& estado);
    void printa_jogo_posicao(Estado& estado);

public:
    Trilha() = default;
    Trilha(int profundidade_x, int profundidade_o);
    void cria_grafo();
    void jogo_automatico();
    void player_vs_computer();
};
