#pragma once

#include <string>

#include "Entities.h"

class Entities;

class Effects {
    private:

    public:
    std::string name;
    int buffDef;

    int lastTurn; //1로 설정하면 생성되자마자 바로 없어짐
};

class Defence : public Effects {

    public:
    Defence(Entities *ent);
    ~Defence() = default;
};