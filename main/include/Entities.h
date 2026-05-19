#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "system.h"

class Effects;
class Item;
class Equipments;

class Entities : public GameObject {
    private:

    public:

    std::string race;
    std::string aiType;
    std::string name;
    std::string desc;
    std::string nameColor = "red";

    int hp;
    int atk;
    int spd;
    int exp;

    std::vector<Item*> dropTable;
    
    //여기부턴 생성자에서 할당해주지 않는 값이다.
    //벡터 타입은 복사될때 알아서 새로운 메모리를 할당받더라
    std::vector<Effects*> effects; 

    bool isDead = false;
    bool isPlayer = false;

    Entities* target = nullptr; //초기화 안해주면 야랄남

    Entities() = default;
    Entities(std::string name);
    Entities(const Entities& ent); //복사 생성자

    virtual void TakeTurn();
    virtual void Dead(); 
};

class Player : public Entities {
    private:
    
    public:

    std::vector<Item*> inventory;
    int invSize;

    std::unordered_map<std::string, Item*> equipments;

    Player();
    ~Player();

    void TakeTurn() override;
    void Dead() override;
    void ShowMenu();
    void LootItem(Item*& drop);
};
