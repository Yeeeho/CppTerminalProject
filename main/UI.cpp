#include <iostream>

#include "UI.h"
#include "Utils.h"
#include "Items.h"


void UI::Show()
{
}

void UI::Stack()
{
    if (!this->isStacked) {
        this->isStacked = true;
        uiStack.push_back(this);
    }

    std::cout << "current stack size:";
    std::cout << uiStack.size() << std::endl;
}

void UI::Goback()
{
    std::cout << "이전 메뉴로 돌아갑니다." << std::endl;

    UI* last = uiStack.back();
    delete last;
    uiStack.pop_back();

    UI* prev = uiStack.back();
    last->Show();
}

ItemUI::ItemUI(Items* it) { //생성자에서 타입변환
    item = it;
    switch (item->type)
    {
    case ItemType::Equipment:
        
        break;
    default:
        break;
    }
}

PlayerUI::PlayerUI(Player*p) { //생성자 주입
    player = p;
}

InvUI::InvUI(Player *p)
{
    player = p;
}

void ItemUI::Show()
{
    Utilities util;

    this->Stack();

    switch(item->type) {
        case ItemType::Item:
            ShowItem();
            break;
        case ItemType::Equipment:
            ShowEq();
            break;
        default:
            std::cout << "아이템 타입을 가져오지 못함." << std::endl;
    }
}

void InvUI::Show()
{
    Utilities util;

    this->Stack();

    std::string line = player->name + "의 인벤토리";
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
    itemui.Show();
}

void ItemUI::ShowItem() {
    Utilities util;

    ShowName();
    ShowDesc();
    ShowVal();
    std::string line;
    line = util.WrapColor("무엇을 하시겠습니까?", "yellow");
    util.PrintLine(line, 2);
    DisPoseButton(1);
    GobackButton(2);
    int input;
    while (true) {
        std:: cin >> input;
        if (input == 1) {
            
            break;
        }
        else if (input == 2) {

            break;
        }
        else std::cout << "다시 입력해 주십시오" << std::endl;
    }
}

void ItemUI::ShowEq()
{
    ShowName();
    ShowDesc();
    ShowAtk();
    ShowDef();
    std::cout << std::endl;
    ShowVal();
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

void ItemUI::DisPoseButton(int num)
{
    std::string strnum = std::to_string(num);
    std::cout << "["+ strnum +"] 아이템 버리기" << std::endl;
}

void ItemUI::GobackButton(int num)
{
    std::string strnum = std::to_string(num);
    std::cout << "["+ strnum +"] 돌아가기" << std::endl;
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