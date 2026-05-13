#include <iostream>

#include "UI.h"
#include "Utils.h"
#include "Items.h"


std::vector<UI*> UI::uiStack = {};

void UI::Show()
{
}

void UI::Stack()
{
    if (isDebug) {

        std::cout << "is this stacked: ";
        std::cout << this->isStacked << std::endl;
    }

    if (!this->isStacked) {
        this->isStacked = true;
        uiStack.push_back(this);
    }

    if (isDebug) {        
        std::cout << "current ui stack size:";
        std::cout << uiStack.size() << std::endl;
    }
}

void UI::Goback(int num)
{
    std::cout << "이전 메뉴로 돌아갑니다.\n" << std::endl;

    for (int i = 0; i < num; i++) {        
        UI* last = uiStack.back();
        delete last;
        uiStack.pop_back();
    }

    if (uiStack.empty()) { //스택이 비면 return 한다.
        std::cout << "ui 스택이 비었는뎁쇼?" << std::endl;
        return;
    } 

    UI* prev = uiStack.back();
    prev->Show();
}

bool UI::YesOrNo()
{
    Utilities util;

    std::string line = "숫자를 입력해서 선택하십시오.\n\n";
    util.PrintLine(util.WrapColor(line, "yellow"));
    std::cout << "[1] 예\n";
    std::cout << "[2] 아니오\n";
    util.NewLine(1);
    int input;
    while(true) {
        std::cin >> input;
        util.NewLine(1);
        switch(input) {
            case 1:
                return true;
                break;
            case 2:
                return false;
                break;
            default:
                std::cout << "다시 입력하십시오.\n" << std::endl;
        }
    }
}

ItemUI::ItemUI(Items* it) { 
    player = (Player*) GameSystem::player;
    item = it;
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

    std::cout << "아이템 메뉴" << std::endl;

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

    std::string line = player->name + "의 인벤토리\n아이템 개수: ";
    line = util.WrapColor(line, "yellow");
    util.PrintLine(line, 0);
    std::cout << player->inventory.size() << std::endl;
    util.NewLine(1);

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
    ItemUI* itemui = new ItemUI(curItem);
    itemui->Show();
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
        util.NewLine(1);
        switch(input) {
            case 1:
                new DisPoseUI(item);
                break;
            case 2:
                Goback();
                break;
            default:
                std::cout << "다시 입력해 주십시오" << std::endl;
        }
    }
}

void ItemUI::ShowEq()
{
    Utilities util;

    ShowName();
    ShowDesc();
    ShowAtk();
    ShowDef();
    std::cout << std::endl;
    ShowVal();
    std::string line = util.WrapColor("무엇을 하시겠습니까?", "yellow");
    util.PrintLine(line, 2);
    DisPoseButton(1);
    GobackButton(2);

    int input;
    while (true) {
        std:: cin >> input;
        util.NewLine(1);
        switch(input) {
            case 1:
                (new DisPoseUI(item))->Show();
                break;
            case 2:
                Goback();
                break;
            default:
                std::cout << "다시 입력해 주십시오" << std::endl;
        }
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

void DisPoseUI::Show()
{
    Utilities util;

    this->Stack();

    util.NewLine(1);
    std::cout << "아이템을 정말 버리시겠습니까? 다시 획득할수 없어요." << std::endl;
    if(YesOrNo()) {
        delete item;
        util.EraseOneElem(player->inventory, item);
        item = nullptr;
        Goback(2);
    }
    else {
        Goback();
    }
}

DisPoseUI::DisPoseUI(Items* it)
{
    item = it;
}
