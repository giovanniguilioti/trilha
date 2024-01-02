#include "trilha.h"

int main()
{
    auto trilha = new Trilha();
    trilha->cria_grafo();
    trilha->inicia_jogo();

    return 0;
}
