#include "pch.h"

#include "system.h"
#include "entities.h"
#include "items.h"
#include "events.h"
#include "utils.h"

std::unordered_map<std::string, Events*> eventMap = {};

void Events::Run()
{
    std::cout << "executed abstract event run" << std::endl;
}

void ItemsEvent::Run()
{
    json currentItemPool = itemPool["items"];

    static std::default_random_engine dre;
    //지금은 전체 아이템 풀에서 조회하지만 추후에 수정 필요함.
    static std::uniform_int_distribution<int> itemIdx(0, itemPool.size()-1);

    Player* player =(Player*) GameSystem::player;
    Item* drop = new Item("default");

    player->LootItem(drop);
}

void EmptyEvent::Run()
{
    Utilities util;
    util.PrintLine("이 방에는 아무것도 없습니다...");
}
