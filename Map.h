#pragma once

#include <vector>

#include "Entities.h"

class Room {
    private:

    public:

    bool isEnemy = false;
    int enemyIdx = -1;
    Entities* enemy;

    bool isEvent = false;
    int eventIdx = -1;

    Room();
    ~Room();
};

class Map {
    private:
    Player* player;
    public:
    
    std::vector<Room*> rooms;
    
    Map();
    Map(int rooms);
    Map(Player* player ,int rooms);
    ~Map();
    
    void RandomRooms();
    void Progress();
};


