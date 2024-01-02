#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>

#include "estado.h"

#define NUM_VERTICES 24
#define NUM_PECAS 18
#define NUM_PECAS_JOGADOR 9
#define MAX_PROFUNDIDADE 2

class Trilha
{
private:
    char pecas[2] = {'X', 'O'};
    std::map<int, std::vector<int>> grafo;
    Estado estado_atual;
    
    int verifica_impar(Estado& estado, int i, char peca);
    int verifica_par(Estado& estado, int i, char peca);
    int verifica_tripla(Estado& estado, char peca);
    void remove_peca(Estado& estado, char peca);
    int utilidade(Estado& estado, char peca);
    std::map<int, std::vector<int>> lista_acoes_livre(Estado& estado);
    std::map<int, std::vector<int>> lista_acoes_restrita(Estado& estado);
    bool teste_termino(Estado& estado, bool inicio  = false);
    std::tuple<int, int, int> valor_min(Estado& estado, int peca, int fromPos, int toPos, int profundidade);
    std::tuple<int, int, int> valor_max(Estado& estado, int peca, int fromPos, int toPos, int profundidade);
    Estado movimenta_peca(Estado& estado, char peca, int fromPos, int toPos);
    Estado adiciona_peca(Estado& estado, char peca);
    std::tuple<int, int, int> decisao_minimax(Estado& estado, int peca);
    void printa_jogo(Estado& estado);

public:
    Trilha() = default;
    void cria_grafo();
    void inicia_jogo();
};
