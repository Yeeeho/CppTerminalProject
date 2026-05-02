#include "Combat.h"
#include "Scenes.h"
#include "Utils.h"

Combat::Combat(Player *p)
{
    player = p;
}

void Combat::SpeedSort(Entities *entities[])
{
    if (entities[0]->spd < entities[1]->spd) {
        Entities* temp = entities[0];
        entities[0] = entities[1];
        entities[1] = temp;
    }
}

void Combat::Loop(Entities* enemy)
{
    Utilities util;

    Entities* entityPool[2] = {};
    entityPool[0] = player;
    entityPool[1] = enemy;

    while (true) {
        SpeedSort(entityPool);
        std::string line = entityPool[0]->name + "이(가) 행동할 차례입니다.";
        util.PrintLine(line);
        util.NewLine(3);
        entityPool[0]->Attack(entityPool[1]);

        line = entityPool[1]->name + "이(가) 행동할 차례입니다.";
        util.PrintLine(line);
        util.NewLine(3);
    }
}
