#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>

#define NUM_VERTICES 24
#define NUM_PECAS 18
#define NUM_PECAS_JOGADOR 9

class Trilha
{
private:
    std::map<int, std::vector<int>> grafo;
    std::map<int, char> tabuleiro;
    std::map<char, int> num_pecas;
    std::map<char, std::vector<int>> tabu;
    
    int verifica_impar(int i);
    int verifica_par(int i);

public:
    char pecas[2] = {'X', 'O'};

    Trilha();
    void cria_grafo();
    void inicia_jogo();
    void printa_jogo();
    bool verifica_tripla(int pos, char peca);
    void remove_peca(char peca);
    bool movimenta_peca(char peca);
};
