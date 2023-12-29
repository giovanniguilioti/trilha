#include "trilha.h"

Trilha::Trilha(){ }

void Trilha::cria_grafo()
{
    this->grafo.emplace(0,  std::vector<int>{{1, 7}});
    this->grafo.emplace(1, std::vector<int>{0, 2, 9});
    this->grafo.emplace(2, std::vector<int>{1, 3});
    this->grafo.emplace(3, std::vector<int>{2, 4, 11});
    this->grafo.emplace(4, std::vector<int>{3, 5});
    this->grafo.emplace(5, std::vector<int>{4, 6, 13});
    this->grafo.emplace(6, std::vector<int>{5, 7});
    this->grafo.emplace(7, std::vector<int>{0, 6, 15});
    this->grafo.emplace(8, std::vector<int>{9, 15});
    this->grafo.emplace(9, std::vector<int>{1, 8, 10, 17});
    this->grafo.emplace(10, std::vector<int>{9, 11});
    this->grafo.emplace(11, std::vector<int>{3, 10, 12, 19});
    this->grafo.emplace(12, std::vector<int>{11, 13});
    this->grafo.emplace(13, std::vector<int>{5, 12, 14, 21});
    this->grafo.emplace(14, std::vector<int>{13, 15});
    this->grafo.emplace(15, std::vector<int>{7, 8, 14, 23});
    this->grafo.emplace(16, std::vector<int>{17, 23});
    this->grafo.emplace(17, std::vector<int>{9, 16, 18});
    this->grafo.emplace(18, std::vector<int>{17, 19});
    this->grafo.emplace(19, std::vector<int>{11, 18, 20});
    this->grafo.emplace(20, std::vector<int>{19, 21});
    this->grafo.emplace(21, std::vector<int>{13, 20, 22});
    this->grafo.emplace(22, std::vector<int>{21, 23});
    this->grafo.emplace(23, std::vector<int>{15, 16, 22});
}

void Trilha::inicia_jogo()
{
    srand(time(NULL));
    for(int i = 0; i < NUM_PECAS; ++i)
    {
        int pos = rand() % 24;
        while(this->tabuleiro[pos])
            pos = rand() % 24;

        std::cout << "inserindo peça: na pos: " << pos << "\n";
        this->tabuleiro[pos] = pecas[i % 2];
        this->num_pecas[pecas[i % 2]]++;
        printa_jogo();
        if(verifica_tripla(pos, pecas[i % 2]))
            remove_peca(pecas[(i + 1) % 2]);
    }
}

void Trilha::printa_jogo()
{
    std::cout << (this->tabuleiro[0] ?this->tabuleiro[0] : '-') << "      ";
    std::cout << (this->tabuleiro[1] ?this->tabuleiro[1] : '-') << "       ";
    std::cout << (this->tabuleiro[2] ?this->tabuleiro[2] : '-') << "          " << "\n";

    std::cout << "  " << (this->tabuleiro[8] ?this->tabuleiro[8] : '-');
    std::cout << "    " << (this->tabuleiro[9] ?this->tabuleiro[9] : '-');
    std::cout << "     " << (this->tabuleiro[10] ?this->tabuleiro[10] : '-') << "\n";

    std::cout << "    " << (this->tabuleiro[16] ?this->tabuleiro[16] : '-');
    std::cout << "  " << (this->tabuleiro[17] ?this->tabuleiro[17] : '-');
    std::cout << "   " << (this->tabuleiro[18] ?this->tabuleiro[18] : '-') << "\n";

    std::cout << (this->tabuleiro[7] ?this->tabuleiro[7] : '-');
    std::cout << " " << (this->tabuleiro[15] ?this->tabuleiro[15] : '-');
    std::cout << " " << (this->tabuleiro[23] ?this->tabuleiro[23] : '-');
    std::cout << "      " << (this->tabuleiro[19] ?this->tabuleiro[19] : '-');
    std::cout << " " << (this->tabuleiro[11] ?this->tabuleiro[19] : '-');
    std::cout << " " << (this->tabuleiro[3] ?this->tabuleiro[3] : '-') << "\n";

    std::cout << "    " << (this->tabuleiro[22] ?this->tabuleiro[22] : '-');
    std::cout << "  " << (this->tabuleiro[21] ?this->tabuleiro[21] : '-');
    std::cout << "   " << (this->tabuleiro[20] ?this->tabuleiro[20] : '-') << "\n";

    std::cout << "  " << (this->tabuleiro[14] ?this->tabuleiro[14] : '-');
    std::cout << "    " << (this->tabuleiro[13] ?this->tabuleiro[13] : '-');
    std::cout << "     " << (this->tabuleiro[12] ?this->tabuleiro[12] : '-') << "\n";

    std::cout << (this->tabuleiro[6] ?this->tabuleiro[6] : '-') << "      ";
    std::cout << (this->tabuleiro[5] ?this->tabuleiro[5] : '-') << "       ";
    std::cout << (this->tabuleiro[4] ?this->tabuleiro[4] : '-') << "          " << "\n";
}

int Trilha::verifica_par(int i)
{
    int count = 0;
    for(auto vertice : this->grafo[i])
    {
        if(vertice % 2 == 0)
        {
            if(this->tabuleiro[vertice] == this->tabuleiro[i])
                count++;

            if(count == 2)
                return i;
        }
    }
    return -1;
}

int Trilha::verifica_impar(int i)
{
    int count = 0;
    for(auto vertice : this->grafo[i])
    {
        if(vertice % 2 != 0)
        {
            if(this->tabuleiro[vertice] == this->tabuleiro[i])
                count++;

            if(count == 2)
                return i;
        }
    }
    return -1;
}

bool Trilha::verifica_tripla(int pos, char peca)
{
    for (int i = 1; i < NUM_VERTICES; i = i + 2)
    {
        if(!this->tabuleiro[i])
            continue;

        //verifica impar
        if((i >= 9 && i <= 15))
        {
            int tripla = verifica_impar(i);
            if(tripla >= 0)
            {
                if(std::find(this->tabu[peca].begin(), this->tabu[peca].end(), i) != this->tabu[peca].end())
                    return false;

                this->tabu[peca].push_back(i);
                std::cout << "adicionando " << i << " na tabu de " << peca <<  "\n";

                return true;
            }
        }

        //verifica par
        int tripla = verifica_par(i);
        if(tripla >= 0)
        {
            if(tripla >= 0)
            {
                if(std::find(this->tabu[peca].begin(), this->tabu[peca].end(), i) != this->tabu[peca].end())
                    return false;

                this->tabu[peca].push_back(i);
                std::cout << "adicionando " << i << " na tabu de " << peca <<  "\n";

                return true;
            }
        }
    }

    return false;
}

void Trilha::remove_peca(char peca)
{
    srand(time(NULL));

    int pos = rand() % 24;
    while(!this->tabuleiro[pos] || this->tabuleiro[pos] != peca)
        pos = rand() % 24;

    this->tabuleiro.erase(pos);
    this->num_pecas[peca]--;

    std::cout << "peca: " << peca << " removida na pos: " << pos << "\n";
    printa_jogo();
}

bool Trilha::movimenta_peca(char peca)
{
    srand(time(NULL));

    while(true)
    {
        if(this->num_pecas['X'] <= 2 || this->num_pecas['O'] <= 2)
            return false;

        int pos = rand() % 24;
        while(this->tabuleiro[pos] != peca)
            pos = rand() % 24;

        if(this->num_pecas[peca] == 3)
        {
            int new_pos = rand() % 24;
            while(this->tabuleiro[new_pos])
                new_pos = rand() % 24;

            this->tabuleiro[new_pos] = peca;
            this->tabuleiro.erase(pos);
            std::cout << "peca "<< peca << " movimentada da pos " << pos << " para a pos: " << new_pos << "\n";
            printa_jogo();
            
            if(verifica_tripla(pos, this->pecas[peca]))
            {
                if(peca == 'X')
                    remove_peca('O');
                else
                    remove_peca('X');
            }
            return true;
        }

        for(auto& vertice : this->grafo[pos])
        {
            if(!tabuleiro[vertice])
            {
                this->tabuleiro[vertice] = peca;
                this->tabuleiro.erase(pos);

                std::cout << "peca "<< peca << " movimentada da pos " << pos << " para a pos: " << vertice << "\n";
                printa_jogo();
                
                if(verifica_tripla(pos, this->pecas[peca]))
                {
                    if(peca == 'X')
                        remove_peca('O');
                    else
                        remove_peca('X');
                }
                return true;
            }
        }
    }

    return true;
}