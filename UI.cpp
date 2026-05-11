#include <iostream>

#include "UI.h"
#include "Utils.h"

std::vector<UI*> UIState::UIStack = {}; //정적 멤버 변수 초기화

UI* UI::GetObject()
{
    return this;
}

PlayerUI::PlayerUI(Player *playerInj)
{
    player = playerInj;
}

void PlayerUI::ShowInv()
{
    this->curFunc = &PlayerUI::ShowInv; //일일이 할당하면 의존성이 높아지긴 하지만.. 일단 템플릿 배우기 전이니..
    UIState::UIStack.push_back(this);

    std::cout << "UIStack Size: ";
    std::cout << UIState::UIStack.size() << std::endl;

    Utilities util;

    std::string line = "인벤토리";
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
    curItem->ShowItemMenu();
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
    this->curFunc = &ItemUI::ShowItemMenu;
    UIState::UIStack.push_back(this);

    Utilities util;

    std::string line;
    line = util.WrapColor("무엇을 하시겠습니까?", "yellow");
    util.PrintLine(line, 2);
    DisPosebutton(1);
    ToInvButton(2);
    int input;
    std::cin >> input;
}

void ItemUI::ToInvButton(int num)
{
    std::string strnum = std::to_string(num);
    std::cout << "["+ strnum +"] 인벤토리로 돌아가기" << std::endl;
}

void ItemUI::DisPosebutton(int num)
{
    std::string strnum = std::to_string(num);
    std::cout << "["+ strnum +"] 아이템 버리기" << std::endl;
}

void ItemUI::DisPoseWarning()
{
    this->curFunc = &ItemUI::DisPoseWarning;
    UIState::UIStack.push_back(this);

    Utilities util;

    util.PrintLine("아이템을 버리면 다시 획득할 수 없습니다.");
    util.PrintLine("그래도 버리시겠습니까?");
    std::string input;
    util.YesOrNo(input);
    if (input == "1") delete this->item;
    if (input == "2") {
        UIState::UIStack.pop_back();
    }
}

void ItemUI::ToInv()
{

}
