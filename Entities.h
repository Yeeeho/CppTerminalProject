#pragma once

#include <string>


class Entities {
    public:

    std::string name;
    std::string desc;

    int hp;
    int atk;
    int spd;

    virtual void Attack(Entities* target);
};

class Player : public Entities {
    private:
    void Attack(Entities* target) override;

    public:
    Player();
    ~Player();
};

class Slave : public Entities {
    public:

    Slave();
    ~Slave();
};