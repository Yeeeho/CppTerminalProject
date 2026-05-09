#pragma once

#include <string>
#include <vector>

class Items {

    public:
    std::string name;
    std::string desc;
    int value;
};

class Equipments : public Items {

    public:
    int atk;
    int def;
    Equipments() = default;
    Equipments(Equipments* eq);
};

class IronDagger : public Equipments {

    public:
    IronDagger();
};

class RagCape : public Equipments {

    public:
    RagCape();
};