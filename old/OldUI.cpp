#include <iostream>

#include "OldUI.h"
#include "Utils.h"

namespace OldUI {
std::vector<UIState*> UIState::UIStack = {}; //정적 멤버 변수 초기화

static bool isDebug = true;


    UI* UI::GetObject()
    {
    return this;
}

UIState::UIState(UI* uiParam, UIFunc uifParam, bool isStackedParam)
{
    uiObj = uiParam; //참조만 하므로 포인터를 복사한다.
    uiFunc = uifParam;
    isStacked = isStackedParam;
}

void UI::Goback()
{
    std::cout << "이전 메뉴로 돌아갑니다." << std::endl;

    UIState* lastUis = UIState::UIStack[UIState::UIStack.size() - 1];
    UIState::UIStack.pop_back(); //현재 실행한 포인터 함수를 스택에서 지움
    delete lastUis;
    std::cout << "Popped, current UIStack Size: ";
    std::cout << UIState::UIStack.size() << std::endl;
    
    UIState* uis = UIState::UIStack[UIState::UIStack.size() - 1];
    if (uis->uiObj == nullptr) std::cout << "널포인터 오브젝트다." << std::endl;
    if (uis->uiFunc == nullptr) std::cout << "널포인터 함수." << std::endl;
    (uis->uiObj->*uis->uiFunc)(); //전에 실행했던 함수를 스택에서 호출 
}

void UI::StackUI(UIFunc pfunc)
{
    if (true) { 
        UIFunc curFunc = (UIFunc) pfunc;
        UIState* uis = new UIState(this, curFunc, true);
        
        UIState::UIStack.push_back(uis);   
    }
    
    if (isDebug) {
        std::cout << "current UIStack Size: ";
        std::cout << UIState::UIStack.size() << std::endl;
    }
}

PlayerUI::PlayerUI(Player *playerInj)
{
    player = playerInj;
}

void PlayerUI::ShowInv()
{
    StackUI((UIFunc)&PlayerUI::ShowInv);
    
    Utilities util;

    std::cout << player->name;
    std::string line = "의 인벤토리";
    line = util.WrapColor(line, "yellow");
    util.PrintLine(line, 2);
    
    int i = 1;
    for (Items* item : player->inventory) {
        std::string itemname = util.WrapColor(item->name, item->nameColor);
        std::string num = std::to_string(i);
        line = "[" + num + "]" + itemname;
        std::cout << line << std::endl;
        i += 1;
    }
    util.NewLine(1);
    util.PrintLine("숫자를 입력하여 선택하십시오.", 2);
    
    int intinput;
    std::cin >> intinput;
    util.NewLine(1);
    Items* curItem = player->inventory[intinput-1];
    ItemUI itemui = ItemUI(curItem);
    
    itemui.ShowInfo();
    
    util.NewLine(1);
    itemui.ShowItemMenu();
}

PlayerUI* PlayerUI::GetObject()
{
    return this;
}

ItemUI::ItemUI(Items *itemInj)
{
    item = itemInj;
}

ItemUI *ItemUI::GetObject()
{
    return this;
}

void ItemUI::ShowInfo()
{
    switch(item->type) {
        case ItemType::Item:
        ShowItemInfo();
        
        case ItemType::Equipment:
        ShowEquipInfo();
    }
}
void ItemUI::ShowName()
{
    Utilities util;
    
    std::string itemname = util.WrapColor(item->name, item->nameColor);
    std::cout << "아이템명: " + itemname +"\n" << std::endl;
}

void ItemUI::ShowDesc()
{
    std::cout << item->desc + "\n" << std::endl;
}

void ItemUI::ShowVal()
{
    std::string itemval = std::to_string(item->value);
    std::cout << "아이템 가치: " + itemval +"\n" << std::endl;
}

void ItemUI::ShowItemInfo()
{
    ShowName();
    ShowDesc();
    ShowVal();
}

void ItemUI::ShowAtk()
{
    Equipments* eq = (Equipments*) item;
    if (eq->atk == 0) return;
    
    std::string itemval = std::to_string(eq->atk);
    std::cout << "공격력: " + itemval << std::endl;
}

void ItemUI::ShowDef()
{
    Equipments* eq = (Equipments*) item;
    if (eq->def == 0) return;
    
    std::string itemval = std::to_string(eq->def);
    std::cout << "방어력: " + itemval  << std::endl;
}

void ItemUI::ShowEquipInfo()
{
    ShowName();
    ShowDesc();
    ShowAtk();
    ShowDef();
    std::cout << std::endl;
    ShowVal();
}

void ItemUI::ShowItemMenu()
{
    StackUI((UIFunc)&ItemUI::ShowItemMenu);
    
    Utilities util;
    
    std::string line;
    line = util.WrapColor("무엇을 하시겠습니까?", "yellow");
    util.PrintLine(line, 2);
    DisPoseButton(1);
    ToInvButton(2);
    
    std::string input;
    std::cin >> input;
    if (input == "1") {
        DisPoseItem();
    } 
    else if (input == "2") Goback();
}

void ItemUI::ToInvButton(int num)
{
    std::string strnum = std::to_string(num);
    std::cout << "["+ strnum +"] 인벤토리로 돌아가기" << std::endl;
}

void ItemUI::DisPoseButton(int num)
{
    std::string strnum = std::to_string(num);
    std::cout << "["+ strnum +"] 아이템 버리기" << std::endl;
}

void ItemUI::DisPoseItem()
{
    StackUI((UIFunc)&ItemUI::DisPoseItem);
    
    Utilities util;
    
    util.PrintLine("아이템을 버리면 다시 획득할 수 없습니다.");
    util.PrintLine("그래도 버리시겠습니까?");
    std::string input;
    util.YesOrNo(input);
    if (input == "1") delete this->item;
    if (input == "2") {
        Goback();
    }
}

}
