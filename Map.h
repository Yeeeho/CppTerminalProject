#pragma once

#include <vector>

#include "Entities.h"

class Room {
    private:

    public:

    bool isEnemy = false;
    bool isEvent = false;
    Entities* enemy;

    Room();
    ~Room();
};

class Map {
    private:
    Player* player;
    public:
    
    std::vector<Room> rooms;
    
    Map();
    Map(Player* player ,int rooms);
    ~Map();
    
    void Progress();
};


