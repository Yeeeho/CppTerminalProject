#include "pch.h"

#include "system.h"
#include "entity_ai.h"
#include "events.h"

json itemPool = NULL;
json eventPool = NULL;
json entityPool = NULL;
json encounterPool = NULL;

GameSystem* GameSystem::player = nullptr;

void GameSystem::Load()
{
    std::cout << "start loading" << std::endl;

    LoadJsonFile(itemPool, "Data/item.json");
    LoadJsonFile(eventPool, "Data/event_pool.json");
    LoadJsonFile(entityPool, "Data/entity.json");
    LoadJsonFile(encounterPool, "Data/encounter_pool.json");

    LoadAIMap();
    LoadEventMap();

    std::cout << "end loading" << std::endl;
}

void GameSystem::LoadJsonFile(json& j, std::string path)
{
    std::ifstream file(path);
    if (!file.is_open()) std::cout << path << " not opened" << std::endl;
    j = json::parse(file);
    std::cout << "parsed " << path << std::endl;
}

void GameSystem::LoadAIMap()
{
    aiMap["slave"] = new SlaveAI();
    aiMap["subterran"] = new SubterranAI();
    aiMap["rat"] = new RatAI();
}

void GameSystem::LoadEventMap()
{
    eventMap["item"] = new ItemsEvent();
    eventMap["empty"] = new EmptyEvent();
}
