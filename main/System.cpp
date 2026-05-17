#include <iostream>
#include <fstream>

#include "System.h"

json* itemPool = nullptr;

GameSystem* GameSystem::player = nullptr;

void GameSystem::Load()
{
    std::cout << "start loading" << std::endl;

    std::ifstream itemfile("Data/item.json");
    std::cout << "itemfile found" << std::endl;

    if (!itemfile.is_open()) {
        std::cout << "itemfile not opened" << std::endl;
    }

    itemPool = new json();
    *itemPool = json::parse(itemfile);
    std::cout << "parsed itemfile" << std::endl;

    std::cout << "end loading" << std::endl;
}
