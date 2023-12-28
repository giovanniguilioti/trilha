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

    /*for(auto& i : grafo)
    {
        std::cout<< i.first << ": ";
        for(auto& v : i.second)
            std::cout << v << " ";

        std::cout << "\n";
    }*/
}

void Trilha::inicia_jogo()
{
    srand(time(NULL));
    for(int i = 0; i < NUM_PECAS; ++i)
    {
        int pos = rand() % 24;
        while(this->tabuleiro[pos])
            pos = rand() % 24;

        if(i % 2 == 0)
        {
            std::cout << "inserindo peça: X na pos: " << pos << "\n";
            this->tabuleiro[pos] = 'X';
            this->num_x++;
            printa_jogo();
            if(verifica_tripla(pos))
                remove_peca('O');
        }
        else
        {
            std::cout << "inserindo peça: O na pos: " << pos << "\n";
            this->tabuleiro[pos] = 'O';
            this->num_o++;
            printa_jogo();
            if(verifica_tripla(pos))
                remove_peca('X');
        }
    }

    /*for(auto& i :this->tabuleiro)
        std::cout << i.first << " > " << i.second << "\n";*/
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

bool Trilha::verifica_tripla(int pos)
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
                if (std::find(this->grafo[i].begin(), this->grafo[i].end(), pos) != this->grafo[i].end())
                {
                    std::cout << "esse movimento causou uma tripla" << "\n";
                    return true;
                }
            }
        }

        //verifica par
        int tripla = verifica_par(i);
        if(tripla >= 0)
        {
            if (std::find(this->grafo[i].begin(), this->grafo[i].end(), pos) != this->grafo[i].end())
            {
                std::cout << "esse movimento causou uma tripla" << "\n";
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
    {
        std::cout << pos << " no while\n";
        pos = rand() % 24;
    }

   this->tabuleiro.erase(pos);
    if(peca == 'X')
        this->num_x--;
    else
        this->num_o--;
    std::cout << "removendo na pos: " << pos << "\n";
}

bool Trilha::movimenta_peca(int peca)
{
    srand(time(NULL));

    bool andou = false;
    while(!andou)
    {
        if(num_x <= 2 || num_o <= 2)
            return false;

        int pos = rand() % 24;
        if(peca)
        {
            while(this->tabuleiro[pos] != 'X')
                pos = rand() % 24;
        }
        else
        {
            while(this->tabuleiro[pos] != 'O')
                pos = rand() % 24;
        }

        std::cout << peca << ": " << pos << "\n";

        for(auto& vertice : this->grafo[pos])
        {
            if(!tabuleiro[vertice])
            {
                if(peca)
                    this->tabuleiro[vertice] = 'X';
                else
                    this->tabuleiro[vertice] = 'O';

                this->tabuleiro.erase(pos);
                andou = true;

                std::cout << "andei " << peca << "\n";

                if(verifica_tripla(pos))
                {
                    if(peca)
                        remove_peca('O');
                    else
                        remove_peca('X');
                }

                //this->printa_jogo();

                return true;
            }
        }
    }

    return true;
}