#pragma once

class Player;

class GameSystem {
    public:

    static const bool isDebug = true;
    
    static GameSystem *player;
};

class GameObject : public GameSystem {

};