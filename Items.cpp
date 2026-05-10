#include <iostream>
#include <string>

#include "Utils.h"
#include "Items.h"

static Utilities util;

void Items::ShowName()
{
    std::string itemname = util.WrapColor(this->name, this->nameColor);
    std::cout << "아이템명: " + itemname +"\n" << std::endl;
}

void Items::ShowDesc()
{
    std::cout << this->desc + "\n" << std::endl;
}

void Items::ShowVal()
{
    std::string itemval = std::to_string(this->value);
    std::cout << "아이템 가치: " + itemval +"\n" << std::endl;
}

void Items::ShowItemInfo()
{
    ShowName();
    ShowDesc();
    ShowVal();
}

void Items::DisposeButton(int num)
{
    std::string strnum = std::to_string(num);
    std::cout << "["+ strnum +"] 아이템 버리기" << std::endl;
}

void Items::DisposeItem()
{
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

void Items::ToInv()
{

}

void Items::ShowItemMenu() //UI용 클래스 있어야겠네..
{
    std::string line;
    line = util.WrapColor("무엇을 하시겠습니까?", "yellow");
    util.PrintLine(line, 2);
    DisposeButton(1);
    ToInvButton(2);
    int input;
    std::cin >> input; 
    
}

Equipments::Equipments(Equipments *eq)
{
    name = eq->name;
    desc = eq->desc;
    value = eq->value;
    
    atk = eq->atk;
    def = eq->def;
}

void Equipments::ShowItemInfo()
{
    ShowName();
    ShowDesc();
    ShowVal();
    std::string intval = std::to_string(this->atk);
    std::cout << "공격력:" + intval << std::endl;
    intval = std::to_string(this->def);
    std::cout << "방어력:" + intval << std::endl;
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

