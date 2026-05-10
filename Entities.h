#pragma once

#include <string>
#include <vector>

#include "Effects.h"
#include "Items.h"

class Effects;

class Entities {
    private:

    public:
    
    std::string name;
    std::string desc;
    std::string nameColor = "red";

    //벡터 타입은 복사될때 알아서 새로운 메모리를 할당받더라
    std::vector<Effects*> effects; 
    std::vector<Items*> dropTable;
    float dropChance;

    int hp;
    int atk;
    int spd;
    int exp;

    bool isDead = false;
    bool isPlayer = false;

    Entities* target = nullptr; //초기화 안해주면 야랄남

    Entities() = default;
    Entities(const Entities& ent); //복사 생성자

    virtual void Attack();
    virtual void TakeTurn();
    virtual void Dead(); 
    Entities Clone();
};

//널포인터 대신에 쓸수 있는 널 객체용 클래스다.
//아직은 사용하지 않는다.
class TempEntity : public Entities { 
    public:
    TempEntity();  
};

class Player : public Entities {
    private:
    
    public:

    std::vector<Items*> inventory;
    int invSize;

    std::vector<Equipments*> wornGears;

    Player();
    ~Player();

    void Attack() override;
    void TakeTurn() override;
    void Dead() override;
    void ShowMenu();
    void ShowInv();
    void LootItem(Items* drop);
};

class Enemies : public Entities {
    public:

    std::vector<Enemies*> ENEMY_POOL;

    Enemies() = default;
    ~Enemies() = default;
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