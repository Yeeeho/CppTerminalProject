#pragma once

#include <string>
#include <vector>

#include "System.h"
#include "Utils.h"

enum class ItemType { //열거형 응가(클래스)
    Item,
    Equipment
};

class Items : public GameObject {
    private:
    public:
    std::string name;
    std::string nameColor;
    ItemType type = ItemType::Item;
    std::string desc;
    int value;

    ~Items();

    void DisposeButton(int num);
    void ToInvButton(int num);
    virtual void ShowItemMenu();
};

class Equipments : public Items {

    public:
    int atk;
    int def;
    Equipments();
    Equipments(Equipments* eq);
};

class Weapons : public Equipments {

};

class BodyArmors : public Equipments {

};

class HandGears : public Equipments {

};

class LegGears : public Equipments {

};

class BackGears : public Equipments {

};

class IronDagger : public Weapons {

    public:
    IronDagger();
};

class RagCape : public BackGears {

    public:
    RagCape();
};