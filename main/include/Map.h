#pragma once

#include <vector>
#include <string>

class Entities;
class Player;

class Room {
    private:

    public:

    Entities* enemy = nullptr;
    bool isEnemy = false;
    int enemyIdx = -1;

    std::string eventName;
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


