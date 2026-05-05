#include <iostream>
#include <vector>

#include "Map.h"
#include "Entities.h"

Map::Map()
{
    std::cout << "you used default constructor.. which is not likely!\n";
}

Map::Map(Player *p, int roomNum) : player(p)
{
    std::vector<Room> initRooms(roomNum);
    rooms = initRooms;
}

Map::~Map()
{
}

void Map::Progress()
{
    for (auto room : this->rooms) {
        if(room.isEnemy) {
            std::cout << "this room has battle\n";
        }
        else if(room.isEvent) {
            std::cout << "this room has event\n";
        }
        else {
            std::cout << "if you see this there is something wrong\n";
        }
    }
}

Room::Room()
{
    //debuggin
    isEvent = true;
}

Room::~Room()
{
}
