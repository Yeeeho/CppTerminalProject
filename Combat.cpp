#include "Combat.h"
#include "Scenes.h"
#include "Utils.h"



Combat::Combat(Player *p)
{
    player = p;
}

void Combat::SpeedSort(Entities* entities[])
{
    if (entities[0]->spd < entities[1]->spd) {
        Entities* temp = entities[0];
        entities[0] = entities[1];
        entities[1] = temp;
    }
}

void Combat::BattleUI(Entities* entities[])
{
    Entities* playerUI;
    Entities* enemyUI;

    for (int i = 0; i < 2; i++) {
        if (entities[i]->isPlayer) {
            playerUI = entities[i];
        }
        else enemyUI = entities[i];
    }

    Utilities util;
    util.PrintLine("----------------------------------------",1 ,50 ,10);
    std::string name0 = util.EntityColorName(playerUI);
    std::string name1 = util.EntityColorName(enemyUI);
    std::cout << name0 + "\r\033[20C" + name1 + "\n";
    
    std::string hp0 = std::to_string(playerUI->hp);
    std::string hp1 = std::to_string(enemyUI->hp);
    std::cout << "체력: " + hp0 + "\r\033[20C" + "체력: " + hp1 + "\n";

    std::string atk0 = std::to_string(playerUI->atk);
    std::string atk1 = std::to_string(enemyUI->atk);
    std::cout << "공격력:" + atk0 + "\r\033[20C" + "공격력" + atk1 + "\n";

    std::string spd0 = std::to_string(playerUI->spd);
    std::string spd1 = std::to_string(enemyUI->spd);
    std::cout << "속도: " + spd0 + "\r\033[20C" + "속도: " + spd1 + "\n";

    std::string effect0, effect1;
    if (playerUI->effects.empty()) effect0 = "";
    else effect0 = playerUI->effects[0]->name;

    if (enemyUI->effects.empty()) effect1 = "";
    else effect1 = enemyUI->effects[0]->name;
    std::cout << "지속효과: " + effect0 + "\r\033[20C" + "지속효과: " + effect1 + "\n";

    util.NewLine(4);
}

void Combat::Loop(Entities* enemy)
{
    Utilities util;
    Scenario scene = Scenario(player);

    Entities* entityPool[2] = {};

    entityPool[0] = player;
    entityPool[1] = enemy;
    player->target = enemy;
    enemy->target = player;

    std::string line = "\033[31m" + enemy->name + "\033[0m" + "와(과) 마주쳤습니다!";
    util.PrintLine(line, 4);

    int i = 0;
    while (true) {
        SpeedSort(entityPool);
        BattleUI(entityPool);

        std::string name = util.WrapColor(entityPool[i%2]->name, entityPool[i%2]->nameColor);
        line = name + "이(가) 행동할 차례입니다.";
        util.PrintLine(line, 2);

        entityPool[i%2]->TakeTurn();

        i += 1;

        int targetNum = i%2;

        if (entityPool[targetNum]->isDead) {
            break;
        }
    }

    if (entityPool[i%2]->isPlayer) {
        util.PrintLine("전투에서 패배했습니다.", 4);
        delete player;
        scene.DeathEnding();
    }
    else {
        line = "전투에서 승리했습니다!";
        line = util.WrapColor(line, "green");
        util.PrintLine(line, 4);        
        delete enemy;
    }
}
