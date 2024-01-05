#include "trilha.h"

void full_game(int profundidade)
{

    Trilha* trilha = new Trilha(profundidade);
    trilha->cria_grafo();
    trilha->inicia_jogo();
}

void menu()
{
    std::cout << "=== Trilha Engine === \n";
    std::cout << "1 - jogo completo\n"; 
    std::cout << "2 - player vs computador\n"; 
    std::cout << "3 - help\n"; 
    std::cout << "4 - sair\n"; 
    int escolha;
    std::cin >> escolha;

    switch(escolha)
    {
        case 1:
            std::cout << "escolha um nível de profundidade da árvore minmax\n";
            int profundidade;
            std::cin >> profundidade;
            full_game(profundidade);
            break;
        case 2:
            // fazer player
            break;
        case 3:
            std::cout << "\nmais instrucoes em github.com/giovanniguilioti/trilha\n\n";
            menu();
            break;
        case 4:
            exit(1);
        default:
            std::cout << "\nopção inválida\n\n";
            menu();
            break;
    }
}

int main()
{
    menu();
    return 0;
}
