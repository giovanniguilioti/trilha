#include "trilha.h"

extern int x;
extern int o;

int main()
{
    auto trilha = new Trilha();
    trilha->cria_grafo();
    trilha->inicia_jogo();
    //printa_jogo(tabuleiro);
    //verifica_tripla(tabuleiro, grafo);

    int peca = 1;
    int count = 0;
    while(count < 50)
    {
        //std::cout << "X pecas: " << trilha->num_x << "\n";
        //std::cout << "O pecas: " << trilha->num_o << "\n";
        if(!trilha->movimenta_peca(peca))
            break;
        peca = (peca + 1) % 2;
    }

    trilha->printa_jogo();

    return 0;
}