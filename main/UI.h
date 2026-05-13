#pragma once

#include <vector>

#include "Entities.h"
#include "Items.h"

class UI; //전방 선언

class UI : public GameSystem {
    public:
    
    static const bool isDebug = false; //디버깅용 정적변수다.
 
    static std::vector<UI*> uiStack; //정적 UI 스택
    bool isStacked = false;

    virtual void Show(); //이 함수에서 UI를 출력하고, UI를 조건에 따라 스택함.
    void Stack(); //현재 객체를 스택하는 함수.
    void Goback(int num = 1); //스택을 pop 하고, 이전 UI 객체를 Show 하는 함수.

    bool YesOrNo(); //예, 아니오를 물어보는 함수.
};

class PlayerUI : public UI {
    private:
    public:
    Player* player = (Player*) GameSystem::player;

    PlayerUI() = default;
    PlayerUI(Player*);
};

class InvUI: public PlayerUI {
    public:

    InvUI(Player*);
    void Show() override;
};

class ItemUI : public PlayerUI {
    private:
    public:
    Items* item;

    ItemUI() = default;
    ItemUI(Items*);

    void Show() override; //아이템 정보를 출력함.

    //아이템 타입에 따라서 다른 함수를 실행함.
    void ShowItem();
    void ShowName();
    void ShowDesc();
    void ShowVal();
    void DisPoseButton(int num);
    void GobackButton(int num);

    void ShowEq();
    void ShowAtk();
    void ShowDef();
};

class DisPoseUI : public ItemUI {
    private:
    
    public:

    void Show() override;

    DisPoseUI(Items*);
};


