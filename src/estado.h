#pragma once

#include <map>
#include <vector>

class Estado
{
private:
    
public:
    Estado() = default;
    std::map<int, char> tabuleiro;
    std::map<char, std::vector<int>> tripla_tabu;
};