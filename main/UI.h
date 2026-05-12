#pragma once

#include <vector>

#include "Entities.h"
#include "Items.h"

class UI; //전방 선언

class UI {
    public:
    
    std::vector<UI*> uiStack;
    bool isStacked;

    virtual void Show();
    void Stack();
    void Goback();
};

class ItemUI : public UI {

    public:
    Items* item;

    ItemUI() = default;
    ItemUI(Items*);

    void Show() override;

    void ShowItem();
    void ShowName();//정보를 출력하는 함수
    void ShowDesc();
    void ShowVal();
    void DisPoseButton(int num);
    void GobackButton(int num);
    void DisPoseItem(); // 아이템 버리기

    void ShowEq();
    void ShowAtk();
    void ShowDef();
};

class PlayerUI : public UI {
    private:
    Player* player;
    public:
    PlayerUI() = default;
    PlayerUI(Player*);
};

class InvUI: public PlayerUI {
    Player* player;
    public:

    InvUI(Player*);
    void Show() override;
};
