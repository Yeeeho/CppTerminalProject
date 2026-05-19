#include "pch.h"

#include "json.hpp"
#include "system.h"
#include "utils.h"
#include "combat.h"
#include "map.h"
#include "entities.h"
#include "events.h"

static bool isDebug = false;

Map::Map()
{
    std::cout << "you used default constructor.. which is not likely!\n";
}

Map::Map(int rooms)
{
    player = (Player*) GameSystem::player;

    for (int i = 0; i < rooms; i++) {
        Room* room = new Room();
        this->rooms.push_back(room);
    }
}

Map::Map(Player *p, int rooms) 
{
    std::vector<Room*> initRooms(rooms);
}

Map::~Map()
{
}

void Map::RandomRooms()
{
    Events ev;

    json currentEncPool = encounterPool["items"]["underworld"]; 
    json currentEventPool = eventPool["items"]["underworld"];

    static std::default_random_engine dre;
    static std::bernoulli_distribution EnemyProb(0.0);
    static std::uniform_int_distribution<int> EnemyRand(0, currentEncPool.size()-1);
    static std::uniform_int_distribution<int> EventRand(0, currentEventPool.size()-1);

    for (auto room : this->rooms) {

        if (EnemyProb(dre)) {
            room->isEnemy = true;
        }
        else {
            room->isEvent = true;
        }

        if (room->isEnemy) {
            room->enemyIdx = EnemyRand(dre);
            room->enemy = new Entities((currentEncPool[room->enemyIdx]));
        }
        if (room->isEvent) {
            room->eventName = currentEventPool[EventRand(dre)];
        }
    }
}

void Map::Progress()
{
    Utilities util;

    for (auto room : this->rooms) {
        if(room->isEnemy) {
            if (isDebug) {
                std::cout << room->enemy->name << std::endl;
            }
            Combat com = Combat(player);
            com.Loop(room->enemy);
        }

        else if(room->isEvent) {
            if (isDebug) std::cout << room->eventName << std::endl;
                
            Events* ev = eventMap[room->eventName];
            ev->Run();            
        }

        util.PrintLine("당신은 다음 방으로 나아갑니다..");        
    }
}
Room::Room()
{
}

Room::~Room()
{
}
