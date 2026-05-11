#pragma once

#include <vector>

#include "System.h"
#include "Items.h"

class UI;

class UI {

    public:

    using UIFunc = void (UI::*)(); //주의할점.. 함수 포인터는 공변반환이 안됨.
    UI::UIFunc curFunc = nullptr;

    virtual UI* GetObject(); //공변 반환을 통해 정확한 타입을 반환시킴.
};

class UIState : public GameObject {
    public:
    static std::vector<UI*> UIStack;
};

class PlayerUI : public UI {

    public:
    Player* player = nullptr; //주입받을 인스턴스

    using UIFunc = void (PlayerUI::*)();
    PlayerUI::UIFunc curFunc = nullptr;

    PlayerUI(Player* pl);
    void ShowInv();

    PlayerUI* GetObject();
};

class ItemUI : public UI {
    public:

    Items* item = nullptr;

    using UIFunc = void (ItemUI::*)();
    ItemUI::UIFunc curFunc = nullptr;

    ItemUI() = default;
    ItemUI(Items* item);

    ItemUI* GetObject();

    void ShowInfo();

    void ShowName();
    void ShowDesc();
    void ShowVal();
    void ShowItemInfo();

    void ShowAtk();
    void ShowDef();
    void ShowEquipInfo();

    void ShowItemMenu();
    void ToInvButton(int num);
    void DisPosebutton(int num);
    void DisPoseWarning();

    void DisposeItem();
    void ToInv();
};
