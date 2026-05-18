#include <iostream>
#include <fstream>

#include "System.h"

json itemPool = NULL;
json entityPool = NULL;
json encounterPool = NULL;

GameSystem* GameSystem::player = nullptr;

void GameSystem::Load()
{
    std::cout << "start loading" << std::endl;

    LoadJsonFile(itemPool, "Data/item.json");
    LoadJsonFile(entityPool, "Data/entity.json");
    LoadJsonFile(encounterPool, "Data/encounter_pool.json");

    std::cout << "end loading" << std::endl;
}

void GameSystem::LoadJsonFile(json& j, std::string path)
{
    std::ifstream file(path);
    if (!file.is_open()) std::cout << path << " not opened" << std::endl;
    j = json::parse(file);
    std::cout << "parsed " << path << std::endl;
}
