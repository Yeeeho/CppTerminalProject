#pragma once

#include <string>


class Entities {
    public:
    std::string name;
    int hp;
    int atk;
};

class Player : public Entities {
    public:
    Player();
    ~Player();
};
