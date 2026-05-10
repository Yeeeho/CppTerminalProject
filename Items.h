#pragma once

#include <string>
#include <vector>

#include "Utils.h"

class Items {
    private:
    public:
    std::string name;
    std::string nameColor;
    std::string desc;
    int value;
    void ShowName();
    void ShowDesc();
    void ShowVal();
    virtual void ShowItemInfo();
    void DisposeButton(int num);
    void DisposeItem();
    void ToInvButton(int num);
    void ToInv();
    virtual void ShowItemMenu();
};

class Equipments : public Items {

    public:
    int atk;
    int def;
    Equipments() = default;
    Equipments(Equipments* eq);
    void ShowItemInfo() override;
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