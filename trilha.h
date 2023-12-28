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
    int num_x = 0;
    int num_o = 0;
    
    int verifica_impar(int i);
    int verifica_par(int i);

public:
    Trilha();
    void cria_grafo();
    void inicia_jogo();
    void printa_jogo();
    bool verifica_tripla(int pos);
    void remove_peca(char peca);
    bool movimenta_peca(int peca);
};
