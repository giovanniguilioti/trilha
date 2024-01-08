#include "trilha.h"

static int conta_peca(Estado& estado, char peca)
{
    int count = 0;
    for(auto i : estado.tabuleiro)
    {
        if(i.second == peca)
            count++;
    }

    return count;
}

Trilha::Trilha(int profundidade)
{
    this->profundidade = profundidade;
}

void Trilha::cria_grafo()
{
    this->grafo.emplace(0,  std::vector<int>{1, 7});
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

void Trilha::printa_jogo(Estado& estado)
{
    std::cout << (estado.tabuleiro[0] ? estado.tabuleiro[0] : '-') << "      ";
    std::cout << (estado.tabuleiro[1] ? estado.tabuleiro[1] : '-') << "       ";
    std::cout << (estado.tabuleiro[2] ? estado.tabuleiro[2] : '-') << "          " << "\n";

    std::cout << "  " << (estado.tabuleiro[8] ?estado.tabuleiro[8] : '-');
    std::cout << "    " << (estado.tabuleiro[9] ?estado.tabuleiro[9] : '-');
    std::cout << "     " << (estado.tabuleiro[10] ?estado.tabuleiro[10] : '-') << "\n";

    std::cout << "    " << (estado.tabuleiro[16] ?estado.tabuleiro[16] : '-');
    std::cout << "  " << (estado.tabuleiro[17] ?estado.tabuleiro[17] : '-');
    std::cout << "   " << (estado.tabuleiro[18] ?estado.tabuleiro[18] : '-') << "\n";

    std::cout << (estado.tabuleiro[7] ?estado.tabuleiro[7] : '-');
    std::cout << " " << (estado.tabuleiro[15] ?estado.tabuleiro[15] : '-');
    std::cout << " " << (estado.tabuleiro[23] ?estado.tabuleiro[23] : '-');
    std::cout << "      " << (estado.tabuleiro[19] ?estado.tabuleiro[19] : '-');
    std::cout << " " << (estado.tabuleiro[11] ?estado.tabuleiro[11] : '-');
    std::cout << " " << (estado.tabuleiro[3] ?estado.tabuleiro[3] : '-') << "\n";

    std::cout << "    " << (estado.tabuleiro[22] ?estado.tabuleiro[22] : '-');
    std::cout << "  " << (estado.tabuleiro[21] ?estado.tabuleiro[21] : '-');
    std::cout << "   " << (estado.tabuleiro[20] ?estado.tabuleiro[20] : '-') << "\n";

    std::cout << "  " << (estado.tabuleiro[14] ?estado.tabuleiro[14] : '-');
    std::cout << "    " << (estado.tabuleiro[13] ?estado.tabuleiro[13] : '-');
    std::cout << "     " << (estado.tabuleiro[12] ?estado.tabuleiro[12] : '-') << "\n";

    std::cout << (estado.tabuleiro[6] ?estado.tabuleiro[6] : '-') << "      ";
    std::cout << (estado.tabuleiro[5] ?estado.tabuleiro[5] : '-') << "       ";
    std::cout << (estado.tabuleiro[4] ?estado.tabuleiro[4] : '-') << "          " << "\n";
}

void Trilha::printa_jogo_posicao(Estado& estado)
{
    std::cout << "==============================================================================================\n"; 
    std::cout << (estado.tabuleiro[0] ? estado.tabuleiro[0] : '-') << "      ";
    std::cout << (estado.tabuleiro[1] ? estado.tabuleiro[1] : '-') << "       ";
    std::cout << (estado.tabuleiro[2] ? estado.tabuleiro[2] : '-') << "          ";

    std::cout << "0        ";
    std::cout << "1         ";
    std::cout << "2          " << "\n";

    std::cout << "  " << (estado.tabuleiro[8] ?estado.tabuleiro[8] : '-');
    std::cout << "    " << (estado.tabuleiro[9] ?estado.tabuleiro[9] : '-');
    std::cout << "     " << (estado.tabuleiro[10] ?estado.tabuleiro[10] : '-') << "          ";

    std::cout << "    8";
    std::cout << "      9";
    std::cout << "      10" << "\n";

    std::cout << "    " << (estado.tabuleiro[16] ?estado.tabuleiro[16] : '-');
    std::cout << "  " << (estado.tabuleiro[17] ?estado.tabuleiro[17] : '-');
    std::cout << "   " << (estado.tabuleiro[18] ?estado.tabuleiro[18] : '-') << "          ";

    std::cout << "         16";
    std::cout << "  17";
    std::cout << "  18" << "\n";

    std::cout << (estado.tabuleiro[7] ?estado.tabuleiro[7] : '-');
    std::cout << " " << (estado.tabuleiro[15] ?estado.tabuleiro[15] : '-');
    std::cout << " " << (estado.tabuleiro[23] ?estado.tabuleiro[23] : '-');
    std::cout << "      " << (estado.tabuleiro[19] ?estado.tabuleiro[19] : '-');
    std::cout << " " << (estado.tabuleiro[11] ?estado.tabuleiro[11] : '-');
    std::cout << " " << (estado.tabuleiro[3] ?estado.tabuleiro[3] : '-') << "          ";

    std::cout << "7";
    std::cout << " 15";
    std::cout << " 23";
    std::cout << "      19";
    std::cout << " 11";
    std::cout << " 3" << "\n";

    std::cout << "    " << (estado.tabuleiro[22] ?estado.tabuleiro[22] : '-');
    std::cout << "  " << (estado.tabuleiro[21] ?estado.tabuleiro[21] : '-');
    std::cout << "   " << (estado.tabuleiro[20] ?estado.tabuleiro[20] : '-') << "          ";

    std::cout << "         22";
    std::cout << "  21" ;
    std::cout << "  20" << "\n";

    std::cout << "  " << (estado.tabuleiro[14] ?estado.tabuleiro[14] : '-');
    std::cout << "    " << (estado.tabuleiro[13] ?estado.tabuleiro[13] : '-');
    std::cout << "     " << (estado.tabuleiro[12] ?estado.tabuleiro[12] : '-') << "          ";

    std::cout << "    14";
    std::cout << "     13";
    std::cout << "     12" << "\n";

    std::cout << (estado.tabuleiro[6] ?estado.tabuleiro[6] : '-') << "      ";
    std::cout << (estado.tabuleiro[5] ?estado.tabuleiro[5] : '-') << "       ";
    std::cout << (estado.tabuleiro[4] ?estado.tabuleiro[4] : '-') << "          ";

    std::cout << "6        ";
    std::cout << "5         ";
    std::cout << "4          " << "\n";
}

void Trilha::jogo_automatico()
{
    auto start = std::chrono::high_resolution_clock::now();
    srand(time(NULL));

    auto acoes = lista_acoes_livre(this->estado_atual);

    printa_jogo(this->estado_atual);

    for(int i = 0; i < NUM_PECAS; ++i)
    {
        this->estado_atual = adiciona_peca(this->estado_atual, this->pecas[i % 2]);
        movimentos[this->pecas[i % 2]] += 1;
    }

    int i = 0;
    while(true)
    {
        auto pos = decisao_minimax(this->estado_atual, this->pecas[i]);
        std::cout << "utilidade do movimento: " << std::get<2>(pos) << "\n";

        this->estado_atual = movimenta_peca(this->estado_atual, this->pecas[i], std::get<0>(pos), std::get<1>(pos));
        movimentos[this->pecas[i % 2]] += 1;
        if(teste_termino(this->estado_atual))
            break;
        i = (i + 1) % 2;
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);

    std::cout << "posicao final: \n";
    printa_jogo(this->estado_atual);
    std::cout << "profundidade da Arvore MinMax: " << this->profundidade << "\n";
    std::cout << "jogadas de X: " << movimentos['X'] << "\n";
    std::cout << "jogadas de O: " << movimentos['O'] << "\n";
    std::cout << "jogadas total: "<< movimentos['X'] + movimentos['O'] << "\n";
    std::cout << "tempo de jogo: " << duration.count() << " segundos\n";
}

int Trilha::verifica_par(Estado& estado, int i, char peca)
{
    int count = 0;
    for(auto vertice : this->grafo[i])
    {
        if(vertice % 2 == 0)
        {
            if(estado.tabuleiro[vertice] == peca && (estado.tabuleiro[vertice] == estado.tabuleiro[i]))
                count++;

            if(count == 2)
                return i;
        }
    }
    return -1;
}

int Trilha::verifica_impar(Estado& estado, int i, char peca)
{
    int count = 0;
    for(auto vertice : this->grafo[i])
    {
        if(vertice % 2 != 0)
        {
            if(estado.tabuleiro[vertice] == peca && (estado.tabuleiro[vertice] == estado.tabuleiro[i]))
                count++;

            if(count == 2)
                return i;
        }
    }
    return -1;
}

int Trilha::verifica_tripla(Estado& estado, char peca, int pos)
{
    for(int i = 1; i < NUM_VERTICES; i = i + 2)
    {
        if(!estado.tabuleiro[i] || estado.tabuleiro[i] != peca)
            continue;

        //verifica impar
        if((i >= 9 && i <= 15))
        {
            int impar = verifica_impar(estado, i, peca);
            if(impar >= 0 && std::find(this->grafo[i].begin(), this->grafo[i].end(), pos) != this->grafo[i].end())
            {
                if(std::find(estado.tripla_impar[peca].begin(), estado.tripla_impar[peca].end(), i) == estado.tripla_impar[peca].end())
                {
                    estado.tripla_impar[peca].push_back(i);
                    return i;
                }

            }
        }

        //verifica par
        int par = verifica_par(estado, i, peca);
        if(par >= 0 && std::find(this->grafo[i].begin(), this->grafo[i].end(), pos) != this->grafo[i].end())
        {
            if(std::find(estado.tripla_par[peca].begin(), estado.tripla_par[peca].end(), i) == estado.tripla_par[peca].end())
            {
                estado.tripla_par[peca].push_back(i);
                return i;
            }

        }
    }

    return -1;
}

void Trilha::remove_peca(Estado& estado, char peca)
{
    srand(time(NULL));

    int pos = rand() % 24;
    while(!estado.tabuleiro[pos] || estado.tabuleiro[pos] != peca)
        pos = rand() % 24;

    auto it = estado.tabuleiro.find(pos);
    estado.tabuleiro.erase(it);

    std::cout << "peca: " << peca << " removida na pos: " << pos << "\n";
    printa_jogo(estado);
}

void Trilha::remove_peca_manualmente(Estado& estado, char peca)
{
    int pos;
    while(true)
    {
        std::cout << "remover peca: " << peca << " da posicao: ";
        std::cin >> pos;
        if(pos < 0 || pos > 24)
        {
            std::cout << "\n Erro: posição invalida\n";
            printa_jogo_posicao(estado);
            continue;
        }
        else if(this->estado_atual.tabuleiro[pos] != peca)
        {
            std::cout << "\nErro: peca invalida\n";
            printa_jogo_posicao(estado);
            continue;
        }

        auto it = estado.tabuleiro.find(pos);
        estado.tabuleiro.erase(it);
        break;
    }

    std::cout << "\npeca: " << peca << " removida na pos: " << pos << "\n";
    printa_jogo_posicao(estado);
}

Estado Trilha::adiciona_peca(Estado& estado, char peca)
{
    srand(time(NULL));

    Estado novo_estado(estado);

    //tratar minmax
    int pos = rand() % 24;
    while(estado.tabuleiro[pos])
        pos = rand() % 24;

    novo_estado.tabuleiro[pos] = peca;

    std::cout << "adicionada peca: " << peca << " na pos: " << pos << " \n";
    //printa_jogo(novo_estado);

    int tripla = verifica_tripla(novo_estado, peca, pos);
    if(tripla >= 0)
    {
        std::cout << "tripla de meio: " << tripla << " apos inserir na pos: " << pos << " a peca: " << peca << "\n";
        if(peca == 'X')
            remove_peca(novo_estado, 'O');
        else
            remove_peca(novo_estado, 'X');
    }
    return novo_estado;
}

Estado Trilha::adiciona_peca_manualmente(Estado& estado, char peca, int pos)
{
    Estado novo_estado(estado);
    
    novo_estado.tabuleiro[pos] = peca;

    std::cout << "adicionada peca: " << peca << " na pos: " << pos << " \n";
    printa_jogo_posicao(novo_estado);

    int tripla = verifica_tripla(novo_estado, peca, pos);
    if(tripla >= 0)
    {
        std::cout << "tripla de meio: " << tripla << " apos inserir na pos: " << pos << " a peca: " << peca << "\n";
        if(peca == 'X')
            remove_peca_manualmente(novo_estado, 'O');
        else
            remove_peca_manualmente(novo_estado, 'X');
    }
    return novo_estado;
}

Estado Trilha::movimenta_peca(Estado& estado, char peca, int fromPos, int toPos)
{
    Estado novo_estado(estado);

    novo_estado.tabuleiro[toPos] = peca;
    novo_estado.tabuleiro.erase(fromPos);

    std::cout << "peca: " << peca << " movimentada da pos: " << fromPos << " para a pos: " << toPos << " \n";
    printa_jogo(novo_estado);

    int tripla = verifica_tripla(novo_estado, peca, toPos);
    if(tripla >= 0)
    {
        std::cout << "tripla de meio: " << tripla << " apos inserir na pos: " << fromPos << " a peca: " << peca << "\n";
        if(peca == 'X')
            remove_peca(novo_estado, 'O');
        else
            remove_peca(novo_estado, 'X');
    }
    return novo_estado;
}

Estado Trilha::movimenta_peca_manualmente(Estado& estado, char peca, int fromPos, int toPos)
{
    Estado novo_estado(estado);

    novo_estado.tabuleiro[toPos] = peca;
    novo_estado.tabuleiro.erase(fromPos);

    std::cout << "peca: " << peca << " movimentada da pos: " << fromPos << " para a pos: " << toPos << " \n";
    printa_jogo_posicao(novo_estado);

    int tripla = verifica_tripla(novo_estado, peca, toPos);
    if(tripla >= 0)
    {
        std::cout << "tripla de meio: " << tripla << " apos inserir na pos: " << fromPos << " a peca: " << peca << "\n";
        if(peca == 'X')
            remove_peca_manualmente(novo_estado, 'O');
        else
            remove_peca_manualmente(novo_estado, 'X');
    }
    return novo_estado;
}

/*
* 5 - tripla
* 2 - dupla
*/
int Trilha::utilidade(Estado& estado, char peca)
{
    int valor = 0;
    std::vector<int> tabu_tripla;
    std::multimap<int, int> tabu_dupla;
    for(int i = 1; i < NUM_VERTICES; i = i + 2)
    {
        if(!estado.tabuleiro[i] || estado.tabuleiro[i] != peca)
            continue;

        //verifica impar
        if((i >= 9 && i <= 15))
        {
            if(verifica_impar(estado, i, peca) >= 0)
            {
                if(std::find(tabu_tripla.begin(), tabu_tripla.end(), i) == tabu_tripla.end())
                {
                    tabu_tripla.push_back(i);
                    for(auto vizinho : this->grafo[i])
                    {
                        if(vizinho % 2 != 0)
                        {
                            tabu_dupla.emplace(i, vizinho);
                            tabu_dupla.emplace(vizinho, i);
                        }
                    }

                    valor += 5;
                }
            }
        }

        //verifica par
        if(verifica_par(estado, i, peca) >= 0)
        {
            if(std::find(tabu_tripla.begin(), tabu_tripla.end(), i) == tabu_tripla.end())
            {
                tabu_tripla.push_back(i);

                for(auto vizinho : this->grafo[i])
                {
                    if(vizinho % 2 == 0)
                    {
                        tabu_dupla.emplace(i, vizinho);
                        tabu_dupla.emplace(vizinho, i);
                    }
                }

                valor += 5;
            }
        }
    }

    for(auto i : estado.tabuleiro)
    {
        for(auto vizinho : this->grafo[i.first])
        {
            if(estado.tabuleiro[i.first] == peca && estado.tabuleiro[i.first] == estado.tabuleiro[vizinho])
            {
                auto chave = tabu_dupla.find(i.first);
                if (chave != tabu_dupla.end() && chave->second == vizinho)
                    continue;

                auto value = tabu_dupla.find(vizinho);
                if (value != tabu_dupla.end() && value->second == i.first)
                    continue;

                tabu_dupla.emplace(i.first, vizinho);
                tabu_dupla.emplace(vizinho, i.first);
                    
                valor += 2;
            }
        }
    }

    return valor;
}

std::map<int, std::vector<int>> Trilha::lista_acoes_livre(Estado& estado)
{
    std::map<int, std::vector<int>> acoes;
    std::vector<int> posicoes_livres;
    for(int i = 0; i < NUM_VERTICES; ++i)
    {
        if(estado.tabuleiro[i])
            continue;

        posicoes_livres.push_back(i);
    }

    if(estado.tabuleiro.empty())
    {
        for(int i = 0; i < NUM_VERTICES; ++i)
            acoes[i] = posicoes_livres;

        return acoes;
    }

    for(auto i : estado.tabuleiro)
        acoes[i.first] = posicoes_livres;

    return acoes;
}

std::map<int, std::vector<int>> Trilha::lista_acoes_restrita(Estado& estado)
{
    std::map<int, std::vector<int>> acoes;
    
    for(auto i : estado.tabuleiro)
        for(auto vertice : this->grafo[i.first])
            if(!estado.tabuleiro[vertice])
                acoes[i.first].push_back(vertice);

    return acoes;
}

bool Trilha::teste_termino(Estado& estado, bool inicio /* = false*/)
{
    if(!inicio && (conta_peca(estado, 'X') <= 2 || conta_peca(estado, 'O') <= 2))
        return true;

    return false;
}

std::tuple<int, int, int> Trilha::decisao_minimax(Estado& estado, int peca)
{
    int profundidade = 0;
    std::vector<std::tuple<int, int, int>> resultados;
    std::map<int, std::vector<int>> acoes;

    if(conta_peca(estado, this->pecas[peca % 2]) == 3)
        acoes = lista_acoes_livre(estado);
    else
        acoes = lista_acoes_restrita(estado);

    for(auto acao : acoes)
    {
        if(estado.tabuleiro[acao.first] != this->pecas[peca % 2])
            continue;

        for(auto vizinho : acao.second)
        {
            resultados.push_back({acao.first, vizinho, 
                                        valor_max(  estado, 
                                                    this->pecas[peca % 2], 
                                                    profundidade + 1, 
                                                    acao.first, 
                                                    vizinho,
                                                    std::numeric_limits<int>::min(),
                                                    std::numeric_limits<int>::max())});
        }
    }

    std::tuple<int, int, int> melhor_resultado;
    int max = std::numeric_limits<int>::min();
    for(auto resultado : resultados)
    {
        if(std::get<2>(resultado) > max)
        {
            max = std::get<2>(resultado);
            melhor_resultado = resultado;
        }
    }

    std::vector<std::tuple<int, int, int>> melhores_resultados;
    for(auto resultado: resultados)
        if(std::get<2>(resultado) == max && resultado != melhor_resultado)
            melhores_resultados.push_back(resultado);

    if(!melhores_resultados.empty())
    {
        std::cout << "mais de um estado com melhor utilidade\n";
        srand(time(NULL));
        int melhor_resultado_aleatorio = rand() % melhores_resultados.size();
        std::cout << "melhor movimento da pos: "<< std::get<0>(melhores_resultados[melhor_resultado_aleatorio]) << " para a pos: " << std::get<1>(melhores_resultados[melhor_resultado_aleatorio]) << " utilidade: " << std::get<2>(melhores_resultados[melhor_resultado_aleatorio]) << "\n";
        return melhores_resultados[melhor_resultado_aleatorio];
    }

    std::cout << "melhor movimento da pos: "<< std::get<0>(melhor_resultado) << " para a pos: " << std::get<1>(melhor_resultado) << " utilidade: " << std::get<2>(melhor_resultado) << "\n";
    return melhor_resultado;
}

int Trilha::valor_min(Estado& estado, int peca, int profundidade, int fromPos, int toPos, int minimo, int maximo)
{
    if(teste_termino(estado) || profundidade == this->profundidade)
    {
        Estado novo_estado = estado;
        novo_estado.tabuleiro[toPos] = this->pecas[peca % 2];
        novo_estado.tabuleiro.erase(fromPos);
        return utilidade(novo_estado, this->pecas[peca % 2]);
    }

    std::vector<std::tuple<int, int, int>> resultados;
    int v = std::numeric_limits<int>::max();
    for(auto acao : lista_acoes_restrita(estado))
    {
        if(estado.tabuleiro[acao.first] != this->pecas[peca % 2])
            continue;

        for(auto vizinho : acao.second)
        {
            Estado novo_estado = estado;
            novo_estado.tabuleiro[vizinho] = this->pecas[peca % 2];
            novo_estado.tabuleiro.erase(acao.first);

            int v = valor_max(  novo_estado, 
                                this->pecas[(peca % 2) +1], 
                                profundidade + 1, 
                                acao.first, 
                                vizinho,
                                minimo,
                                maximo);

            if(v <= minimo)
                return v;

            maximo = std::max(maximo, v);
            resultados.push_back({acao.first, vizinho, v});
        }
    }

    for(auto resultado : resultados)
    {
        if(std::get<2>(resultado) < maximo)
            return std::get<2>(resultado);
    }
}

int Trilha::valor_max(Estado& estado, int peca, int profundidade, int fromPos, int toPos, int minimo, int maximo)
{
    if(teste_termino(estado) || profundidade == this->profundidade)
    {
        Estado novo_estado = estado;
        novo_estado.tabuleiro[toPos] = this->pecas[peca % 2];
        novo_estado.tabuleiro.erase(fromPos);
        return utilidade(novo_estado, this->pecas[peca % 2]);
    }

    std::vector<std::tuple<int, int, int>> resultados;
    int v = std::numeric_limits<int>::min();

    for(auto acao : lista_acoes_restrita(estado))
    {
        if(estado.tabuleiro[acao.first] != this->pecas[peca % 2])
            continue;

        for(auto vizinho : acao.second)
        {
            Estado novo_estado = estado;
            novo_estado.tabuleiro[vizinho] = this->pecas[peca % 2];
            novo_estado.tabuleiro.erase(acao.first);

            v = std::max(v, valor_min(  novo_estado, 
                                this->pecas[(peca % 2) + 1],
                                profundidade + 1, 
                                acao.first, 
                                vizinho,
                                minimo,
                                maximo));

            if(v >= minimo)
                return v;
            
            minimo = std::max(minimo, v);
            resultados.push_back({acao.first, vizinho, v});
        }
    }

    for(auto resultado : resultados)
    {
        if(std::get<2>(resultado) > minimo)
            return std::get<2>(resultado);
    }
}

void Trilha::player_vs_computer()
{
    int count = 0;
    int i = 0;
    while(true)
    {
        if(count > 8)
        {
            printa_jogo_posicao(this->estado_atual);
            std::cout << "Mover peca: " << this->pecas[i % 2] << "\n da posicao: ";
            int fromPos;
            std::cin >> fromPos;
            if(fromPos < 0 || fromPos > 24)
            {
                std::cout << "\n Erro: posição invalida\n";
                continue;
            }
            else if(this->estado_atual.tabuleiro[fromPos] != this->pecas[i % 2])
            {
                std::cout << "\nErro: posição ja ocupada\n";
                continue;
            }

            std::cout << "para a posicao: ";
            int toPos;
            std::cin >> toPos;
            if(toPos < 0 || toPos > 24)
            {
                std::cout << "\n Erro: posição invalida\n";
                continue;
            }
            else if(this->estado_atual.tabuleiro[toPos])
            {
                std::cout << "\nErro: posição ja ocupada\n";
                continue;
            }

            std::map<int, std::vector<int>> acoes;
            if(conta_peca(this->estado_atual, this->pecas[i % 2]) == 3)
                acoes = lista_acoes_livre(this->estado_atual);
            else
                acoes = lista_acoes_restrita(this->estado_atual);

            if(std::find(acoes[fromPos].begin(), acoes[fromPos].end(), toPos) != acoes[fromPos].end())
            {
                this->estado_atual = movimenta_peca_manualmente(this->estado_atual, this->pecas[i % 2], fromPos, toPos);
                std::cout << "\npeca: " << this->pecas[i % 2] << " movida da posicao: " << fromPos << " para a posicao: " << toPos << "\n\n";
            }
            else
                continue;

            i = (i % 2) + 1;

            auto pos_computer = decisao_minimax(this->estado_atual, this->pecas[i]);
            this->estado_atual = movimenta_peca(this->estado_atual, this->pecas[i], std::get<0>(pos_computer), std::get<1>(pos_computer));
            if(teste_termino(this->estado_atual))
                break;
        }
        else
        {
            printa_jogo_posicao(this->estado_atual);
            std::cout << "Adicionar peca: " << this->pecas[i % 2] << " na posicao(0 - 23): ";
            int pos;
            std::cin >> pos;
            if(pos < 0 || pos > 24)
            {
                std::cout << "\n Erro: posição invalida\n";
                continue;
            }
            else if(this->estado_atual.tabuleiro[pos])
            {
                std::cout << "\nErro: posição ja ocupada\n";
                continue;
            }

            this->estado_atual = adiciona_peca_manualmente(this->estado_atual, this->pecas[i % 2], pos);
            std::cout << "\npeca: " << this->pecas[i % 2] << " adicionada na posicao: " << pos << "\n\n";

            i = (i % 2) + 1;

            this->estado_atual = adiciona_peca(this->estado_atual, this->pecas[i % 2]);
            count++;
            if(teste_termino(this->estado_atual, true))
                break;
        }

        i = (i % 2) + 1;
    }
}
