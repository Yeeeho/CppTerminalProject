#pragma once

#include <iostream>
#include <string>

class Entities;
class Player;

class Scenario {
    private:
    Player* player;
    public:

    Scenario();
    Scenario(Player* p);
    
    void DebugScene();

    std::string curScene;
    void YesOrNo(std::string& input);

    void Init();
    void ReturnMain();
    void CutCommEnding();
    void DeathEnding();
    void Intro1();
};