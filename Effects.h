#pragma once

#include <string>

#include "Entities.h"

class Entities;

class Effects {
    private:

    public:
    std::string name;
    
    int lastTurn;

};

class Defence : public Effects {

    public:
    int buffDef;
    Defence(Entities *ent);
    ~Defence() = default;
};