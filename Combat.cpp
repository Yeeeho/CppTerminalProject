#include <vector>

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

void Combat::TakeDamage(Entities *ent, int damage)
{
    Utilities util;
    int buffDef = 0;

    std::string name = util.WrapColor(ent->name, ent->nameColor);
    
    for (auto effect : ent->effects) {
        if (effect->name == "방어") {
            buffDef = effect->buffDef;
        }
    }

    if (buffDef > 0) {
        std::string defString = std::to_string(buffDef);
        std::string line = name + " 은 피해를 " + defString + "만큼 방어했다.";
        util.PrintLine(line, 2);
    }

    damage = damage - buffDef;
    util.IntClamp(damage, 0, 9999999);

    int prevHp = ent->hp;
    ent->hp = ent->hp - damage;

    std::string thp = std::to_string(ent->hp);
    std::string pthp = std::to_string(prevHp);
    std::string line = name + "의 체력 변화: " + pthp + " -> " + thp;
    util.PrintLine(line, 4);

    if (ent->hp <= 0) {
        ent->Dead();
    }
}

void Combat::SkillsUI(Player *pl)
{
    Utilities util;

    util.PrintLine("사용할 기술을 선택하십시오", 2);

    
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

    util.NewLine(1);
    std::cout << "경험치: " + std::to_string(playerUI->exp);

    util.NewLine(4);
}

void Combat::Loop(Entities* enemy)
{
    std::cout << "combat loop";

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
        util.LoadingLine("",1);
        std::cout << "\033[2J\033[H";

        BattleUI(entityPool);

        Entities* curEntity;
        curEntity = entityPool[i%2];
        std::string name = util.WrapColor(curEntity->name, curEntity->nameColor);
        line = name + "이(가) 행동할 차례입니다.";
        util.PrintLine(line, 2);

        curEntity->TakeTurn();

        if (!curEntity->effects.empty()) {
            for (auto effect : curEntity->effects) {
                if (effect->lastTurn > 0) {
                    effect->lastTurn -= 1;
                }
                if (effect->lastTurn <= 0) {
                    delete effect;
                }
            }
        }

        i += 1;

        int targetNum = i%2;

        if (entityPool[targetNum]->isDead) {
            break;
        }
    }
}
