#pragma once

#include <vector>
#include <memory>

#include "System.h"
#include "Items.h"

namespace OldUI
{

    class UI;
    
    using UIFunc = void (UI::*)(); //주의할점.. 함수 포인터는 공변반환이 안됨.
    
    class UI {
        
        public:
        UIFunc uiFunc = nullptr;
        
        UI() = default;
        
        virtual UI* GetObject(); //공변 반환을 통해 정확한 타입을 반환시킴.
        void Goback();
        void StackUI(UIFunc);
};

class UIState { //상태 저장용 클래스
    public:
    static std::vector<UIState*> UIStack;
    
    UI* uiObj = nullptr; //저장할 UI클래스 객체
    UIFunc uiFunc = nullptr; //저장할 UI클래스 함수
    bool isStacked = false;
    
    UIState(UI*, UIFunc, bool isStacked);
};

class PlayerUI : public UI {
    
    public:
    Player* player = nullptr; //주입받을 인스턴스
    
    PlayerUI(Player* pl);
    void ShowInv();
    
    PlayerUI* GetObject() override;
};

class ItemUI : public UI {
    public:
    
    Items* item = nullptr;
    
    ItemUI() = default;
    ItemUI(Items* item);
    
    ItemUI* GetObject() override;
    
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
    void DisPoseButton(int num);
    
    void DisPoseItem();
};

}