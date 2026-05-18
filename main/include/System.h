#pragma once

#include "json.hpp"

using json = nlohmann::json;

extern json itemPool;
extern json entityPool;
extern json encounterPool;


class Player;

class GameSystem {
    public:

    static const bool isDebug = true;
    
    static GameSystem *player;

    void Load();
    void LoadJsonFile(json& j, std::string path);
};

class GameObject : public GameSystem {

};