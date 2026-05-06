#pragma once

#include <string>
#include <vector>

#include "Effects.h"

class Effects;

class Entities {
    private:

    public:
    
    std::string name;
    std::string desc;
    std::string nameColor = "red";

    std::vector<Effects*> effects;

    int hp;
    int atk;
    int spd;
    int exp;

    bool isDead = false;
    bool isPlayer = false;

    Entities* target;

    virtual void Attack();
    virtual void TakeTurn();
    virtual void Dead();
    Entities Clone();
};

class Player : public Entities {
    private:
    
    public:
    Player();
    ~Player();

    void Attack() override;
    void TakeTurn() override;
    void ShowMenu();
};

class Enemies : public Entities {
    public:

    std::vector<Enemies*> ENEMY_POOL;

    Enemies() = default;
    ~Enemies() = default;

    void InitEnemyPool();
};

class Slave : public Enemies {
    private:
    void TakeTurn() override;
    void Attack() override;
    
    public:
    Slave();
    ~Slave();
};

class Subterranean : public Enemies {
    private:
    void TakeTurn() override;
    void Attack() override;

    public:
    Subterranean();
    ~Subterranean();
};