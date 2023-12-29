#include "trilha.h"

int main()
{
    auto trilha = new Trilha();
    trilha->cria_grafo();
    trilha->inicia_jogo();

    int i = 0;
    while(true)
    {
        if(!trilha->movimenta_peca(trilha->pecas[i % 2]))
            break;
        i = (i + 1) % 2;
    }

    std::cout << "posicao final: \n";
    trilha->printa_jogo();

    return 0;
}
