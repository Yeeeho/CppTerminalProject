#include <iostream>
#include <vector>
#include <random>

#include "json.hpp"
#include "System.h"
#include "Combat.h"
#include "Map.h"
#include "Entities.h"
#include "Events.h"

static bool isDebug = true;

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

    json currentPool = encounterPool["items"]["underground"]; //여기 하드코딩해놓음

    static std::default_random_engine dre;
    static std::bernoulli_distribution EnemyProb(0.7);
    static std::uniform_int_distribution<int> EnemyRand(0, currentPool.size()-1);
    static std::uniform_int_distribution<int> EventRand(0, 1);

    for (auto room : this->rooms) {

        if (EnemyProb(dre)) {
            room->isEnemy = true;
        }
        else {
            room->isEvent = true;
        }

        if (room->isEnemy) {
            room->enemyIdx = EnemyRand(dre);
            room->enemy = new Entities((currentPool[room->enemyIdx]));
        }
        if (room->isEvent) {
            room->eventIdx = EventRand(dre);
        }
    }
}

void Map::Progress()
{
    Events ev;

    for (auto room : this->rooms) {
        if(room->isEnemy) {
            if (isDebug) {
                std::cout << room->enemy->name << std::endl;
            }
            Combat com = Combat(player);
            com.Loop(room->enemy);
        }

        else if(room->isEvent) {
            if (isDebug) {
                std::string eventIdx = std::to_string(room->eventIdx);
                std::cout << "event idx" + eventIdx + "\n";
            }
            std::cout << "event feature is not updated" << std::endl;
        }
        else {
            std::cout << "if you see this there is something wrong\n";
        }
    }
}

Room::Room()
{
}

Room::~Room()
{
}
