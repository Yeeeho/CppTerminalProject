#include "Items.h"

Equipments::Equipments(Equipments *eq)
{
    name = eq->name;
    desc = eq->desc;
    value = eq->value;
    
    atk = eq->atk;
    def = eq->def;
}

IronDagger::IronDagger()
{
    name = "쇠 단검";
    desc = "쇠로 된 검날이 있는 단검이다.\n없는 것보단 낫다.";
    value = 10;

    atk = 5;
    def = 0;
}

RagCape::RagCape()
{
    name = "누더기 망토";
    desc = "직물 조각들을 기워 만든 망토다.\n없는 것보단 낫다.";
    value = 10;

    atk = 0;
    def = 2;
};
