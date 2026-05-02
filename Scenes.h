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
    std::string curScene;
    void YesOrNo(std::string& input);

    void Init();
    void CutCommEnding();
    void Intro1();
};