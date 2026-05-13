#include <iostream>
#include <string>

#include "System.h"
#include "Utils.h"
#include "Items.h"

Items::~Items()
{
    std::cout << "아이템이 삭제되었습니다." << std::endl;
}

void Items::DisposeButton(int num)
{
    std::string strnum = std::to_string(num);
    std::cout << "["+ strnum +"] 아이템 버리기" << std::endl;
}

void Items::DisposeItem()
{
    Utilities util;

    util.PrintLine("아이템을 버리면 다시 획득할 수 없습니다.");
    util.PrintLine("그래도 버리시겠습니까?");
    std::string input;
    util.YesOrNo(input);
    if (input == "1") delete this;
    if (input == "2") {
        this->ShowItemMenu();
    }
}

void Items::ToInvButton(int num)
{
    std::string strnum = std::to_string(num);
    std::cout << "["+ strnum +"] 인벤토리로 돌아가기" << std::endl;
}

void Items::ShowItemMenu() //UI용 클래스 있어야겠네..
{
    Utilities util;

    std::string line;
    line = util.WrapColor("무엇을 하시겠습니까?", "yellow");
    util.PrintLine(line, 2);
    DisposeButton(1);
    ToInvButton(2);
    int input;
    std::cin >> input; 
    
}

Equipments::Equipments() //친절하게도 하위 클래스들은 이 생성자를 자동 호출해준다.
{
    type = ItemType::Equipment;
}

Equipments::Equipments(Equipments *eq)
{
    name = eq->name;
    nameColor = eq->nameColor;
    desc = eq->desc;
    value = eq->value;
    
    atk = eq->atk;
    def = eq->def;
}

IronDagger::IronDagger()
{
    name = "쇠 단검";
    nameColor = "default";
    desc = "쇠로 된 검날이 있는 단검이다.\n없는 것보단 낫다.";
    value = 10;

    atk = 5;
    def = 0;
}

RagCape::RagCape()
{
    name = "누더기 망토";
    nameColor = "default";
    desc = "직물 조각들을 기워 만든 망토다.\n없는 것보단 낫다.";
    value = 10;

    atk = 0;
    def = 2;
};

