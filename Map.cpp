#include <iostream>
#include <vector>
#include <random>

#include "Map.h"
#include "Entities.h"

Map::Map()
{
    std::cout << "you used default constructor.. which is not likely!\n";
}

Map::Map(int rooms)
{
    for (int i = 0; i < rooms; i++) {
        Room* room = new Room();
        this->rooms.push_back(room);
    }
}

Map::Map(Player *p, int rooms) : player(p)
{
    std::vector<Room*> initRooms(rooms);
}

Map::~Map()
{
}

void Map::RandomRooms()
{
    static std::default_random_engine dre;
    static std::bernoulli_distribution EnemyProb(0.7);
    static std::uniform_int_distribution<int> EnemyRand(0, 1);
    static std::uniform_int_distribution<int> EventRand(0, 1);

    Enemies enemyInst;

    for (auto room : this->rooms) {

        if (EnemyProb(dre)) {
            room->isEnemy = true;
        }
        else {
            room->isEvent = true;
        }

        if (room->isEnemy) {
            room->enemyIdx = EnemyRand(dre);

            Enemies* enemy = new Enemies();
        }
        if (room->isEvent) {
            room->eventIdx = EventRand(dre);
        }
    }
}

void Map::Progress()
{
    for (auto room : this->rooms) {
        if(room->isEnemy) {
            std::string enemyIdx = std::to_string(room->enemyIdx);
            std::cout << "enemy idx" + enemyIdx + "\n";
            std::cout << room->enemy->name + "\n";
        }
        else if(room->isEvent) {
            std::string eventIdx = std::to_string(room->eventIdx);
            std::cout << "event idx" + eventIdx + "\n";
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
