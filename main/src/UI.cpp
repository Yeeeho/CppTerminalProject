#include <iostream>
#include <cctype>

#include "UI.h"
#include "Utils.h"

UI* UI::Show()
{
    std::cout << "default UI instance created, not good." << std::endl;
    return new UI();
}

UI *UI::Clone() const
{
    return new UI(*this);
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


UIManager::UIManager(UI *initUI)
{
    currentUI = initUI;
}

void UIManager::Run()
{
    while (true) {
        //초기 currentUI가 할당된 상태임.
        if (currentUI->isEnd) {
            break;
        }

        Stack();
        
        if (isDebug) std::cout << "stack succeed" << std::endl;

        currentUI = currentUI->Show();

        if (currentUI->isBack) {
            if (isDebug) std::cout << "going back" << std::endl;
            currentUI = Goback();
        }
    }

    if (isDebug) std::cout << "UI loop ended" << std::endl;
}

void UIManager::Stack()
{
    if (!currentUI->isStacked) {
        currentUI->isStacked = true;
        uiStack.push_back(currentUI);
    }

    if (isDebug) {        
        std::cout << "current ui stack size:";
        std::cout << uiStack.size() << std::endl;
    }
}

UI* UIManager::Goback()
{
    Utilities util;
    util.PrintLine("이전 메뉴로 돌아갑니다.");
    
    UI* last = uiStack.back();
    if (isDebug) std::cout << "found last stack" << std::endl;

    delete last;
    if (isDebug) std::cout << "stacked on delete stack" << std::endl;

    uiStack.pop_back();
    last = nullptr;
    if (isDebug) std::cout << "popped stack" << std::endl;
    
    if (uiStack.empty()) { //스택이 비면 return 한다.
        std::cout << "UI stack empty" << std::endl;
        if (isDebug) util.LoadingLine("", 1);
        return new UIState("end");
    } 

    UI* prev = uiStack.back();
    return prev;
}

UIState::UIState(std::string state)
{
    Utilities util;

    if (state == "end")
        isEnd = true;
    else if (state == "back") isBack = true;
    else util.PrintLine("uistate: not viable parameter");
}

ItemUI::ItemUI(Item* it) { 
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

UI* InvUI::Show()
{
    Utilities util;

    if (player->inventory.empty()) {
        std::cout << "인벤토리가 비었습니다." << std::endl;
        return new UIState("back");
    }

    std::cout << "\033[2J\033[H";

    std::string line = player->name + "의 인벤토리\n";
    line = util.WrapColor(line, "yellow");
    util.PrintLine(line, 0);
    std::cout << "아이템 개수:"; std::cout << player->inventory.size() << std::endl;
    util.NewLine(1);

    int i = 1;
    for (Item* item : player->inventory) {
        std::string itemname = util.WrapColor(item->name, item->nameColor);
        std::string num = std::to_string(i);
        line = "[" + num + "]" + itemname;
        std::cout << line << std::endl;
        i += 1;
    }
    util.NewLine(1);
    std::cout << util.WrapColor("숫자를 입력하여 선택하십시오.", "yellow") << std::endl;
    std::cout << "돌아가기 위해선 q 키를 누르십시오." << std::endl;

    int itindex;
    while (true) {

        std::string input;
        std::cin >> input;
        if (isdigit(input[0])) {
            int intinput = std::stoi(input);
            std::cout << "user input:" << intinput << std::endl;
            itindex = intinput;
            break;
        }
    else {
        int intinput = (int) input[0];
        std::cout << "user input:" << intinput << std::endl;
        if (intinput == 113) return new UIState("back");
        else std::cout << "다시 입력해 주십시오" << std::endl;
        }
    }
    util.NewLine(1);

    Item* curItem = player->inventory[itindex-1];
    ItemUI* itemui = new ItemUI(curItem);
    return itemui;
}

UI *InvUI::Clone() const
{
    return new InvUI(*this);
}

UI* ItemUI::Show()
{
    if (isDebug) std::cout << "showing item menu" << std::endl;

    Utilities util;

    ShowInfo();

    std::string line = util.WrapColor("무엇을 하시겠습니까?", "yellow");
    util.PrintLine(line, 2);
    DisPoseButton(1);
    GobackButton(2);

    int input;
    while (true) {
        std:: cin >> input;
        util.NewLine(1);
        if (input == 1) {
                return new DisPoseUI(item);
        }
        else if (input == 2) {
                UIState* uis = new UIState("back");
                return uis;
        }
        else {
                std::cout << "다시 입력해 주십시오" << std::endl;
        }
    }
}

UI *ItemUI::Clone() const
{
    return new ItemUI(*this);
}

void ItemUI::ShowInfo()
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
    if (item->atk == 0) return;
    
    std::string itemval = std::to_string(item->atk);
    std::cout << "공격력: " + itemval << std::endl;
}

void ItemUI::ShowDef()
{
    if (item->def == 0) return;
    
    std::string itemval = std::to_string(item->def);
    std::cout << "방어력: " + itemval  << std::endl;
}

UI* DisPoseUI::Show()
{
    Utilities util;

    util.NewLine(1);
    std::cout << "아이템을 정말 버리시겠습니까? 다시 획득할수 없어요." << std::endl;
    if(YesOrNo()) {
        delete item;
        util.EraseOneElem(player->inventory, item);
        item = nullptr;
        return new UIState("back");
    }
    else {
        return new UIState("back");
    }
}

UI *DisPoseUI::Clone() const
{
    return new DisPoseUI(*this);
}

DisPoseUI::DisPoseUI(Item* it)
{
    item = it;
}

