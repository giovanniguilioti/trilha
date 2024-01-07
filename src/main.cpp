#include "trilha.h"

void full_game(int profundidade);
void player_vs();
void menu();

int main()
{
    menu();
    return 0;
}

void full_game(int profundidade)
{

    Trilha* trilha = new Trilha(profundidade);
    trilha->cria_grafo();
    trilha->inicia_jogo();
}

void player_vs()
{
    std::cout << "Escolha uma dificuldade:\n";
    std::cout << "1 - facil\n";
    std::cout << "2 - medio\n";
    std::cout << "3 - dificil\n";
    int dificuldade;
    std::cin >> dificuldade;

    Trilha* trilha = nullptr;
    switch(dificuldade)
    {
        case 1: 
            trilha = new Trilha(3);
            break;
        case 2: 
            trilha = new Trilha(6);
            break;
        case 3: 
            trilha = new Trilha(9);
            break;
        default:
            std::cout << "\nopção inválida\n\n";
            menu();
            break;
    }

    trilha->cria_grafo();
    trilha->player_vs_computer();
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
            player_vs();
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