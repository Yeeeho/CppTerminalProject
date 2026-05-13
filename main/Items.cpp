#include <iostream>
#include <string>

#include "System.h"
#include "Utils.h"
#include "Items.h"

Items::~Items()
{
    std::cout << "아이템이 삭제되었습니다." << std::endl;
}

Items *Items::Clone() const
{
    return new Items(*this);
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

Items *IronDagger::Clone() const
{
    return new IronDagger(*this);
}

RagCape::RagCape()
{
    name = "누더기 망토";
    nameColor = "default";
    desc = "직물 조각들을 기워 만든 망토다.\n없는 것보단 낫다.";
    value = 10;

    atk = 0;
    def = 2;
}
Items *RagCape::Clone() const
{
    return new RagCape(*this);
};
