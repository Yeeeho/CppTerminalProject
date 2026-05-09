#pragma once

#include <iostream>
#include <string>

#include "Utils.h"
#include "Entities.h"

class Scenario {
    private:
    Utilities util;
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