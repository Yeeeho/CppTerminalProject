#pragma once

#include "json.hpp"

using json = nlohmann::json;

extern json* itemPool;

class Player;

class GameSystem {
    public:

    static const bool isDebug = true;
    
    static GameSystem *player;

    void Load();
};

class GameObject : public GameSystem {

};