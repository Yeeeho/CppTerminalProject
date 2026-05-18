#include <iostream>
#include <string>
#include <random>

#include "System.h"
#include "Entities.h"
#include "Effects.h"
#include "Combat.h"
#include "item.h"
#include "Utils.h"
#include "UI.h"

Entities::Entities(std::string name)
{
    Utilities util;

    if (!entityPool["items"].contains(name)) {        
        std::cout << util.WrapColor("name not found in database. check the constructor parameter", "yellow")
        << std::endl;
        name = "default";
    }

    const json& ent = entityPool["items"][name];

    this->race = ent["race"].get<std::string>();
    this->aiType = ent["ai_type"].get<std::string>();
    this->name = ent["name"].get<std::string>();
    this->nameColor = ent["nameColor"].get<std::string>();
    this->desc = ent["desc"].get<std::string>();
    
    this->hp = ent["hp"].get<int>();
    this->atk = ent["atk"].get<int>();
    this->spd= ent["spd"].get<int>();
    this->exp = ent["exp"].get<int>();

    this->dropTable = {
        new Item("iron_dagger"), new Item("rag_cloak")
    };
}

Entities::Entities(const Entities &ent) // 복사 생성자
{
    race = ent.race;
    aiType = ent.aiType;
    name = ent.name;
    desc = ent.desc;
    nameColor = ent.nameColor;

    
    hp = ent.hp;
    atk = ent.atk;
    spd = ent.spd;
    exp = ent.exp;

    dropTable = ent.dropTable;

    effects = ent.effects;

    isDead = ent.isDead;
    isPlayer = ent.isPlayer;
    //얌전히 조건문을 쓰도록 하자.
    if (ent.target == nullptr) {
        //널포인터의 값에 접근하려고??? 코이츠 겁대가리 없는 www
        target = nullptr;
    }
    else {
        target = new Entities(*ent.target);
    }

}

void Entities::Attack()
{
    Utilities util;
    Combat comb;

    std::string name = util.WrapColor(this->name, this->nameColor);
    std::cout << name << " 이(가) 공격했다." << std::endl;

    comb.TakeDamage(this->target, this->atk);
}

void Entities::TakeTurn() {
    this->Attack();
}

void Entities::Dead()
{
    static std::default_random_engine dre;
    static std::bernoulli_distribution dropProb(0.5); //This is hardcoded, debuggin now

    int dropIdx = this->dropTable.size() - 1;
    static std::uniform_int_distribution<int> itemRand(0, dropIdx);

    Utilities util;

    this->isDead = true;

    std::string line = this->name + "(이)가 쓰러집니다!";
    line = util.WrapColor(line, "green");
    util.PrintLine(line, 2);

    this->target->exp += this->exp;

    //타겟이 경험치를 획득한다.
    std::string targetName = this->target->name; //타겟의 이름
    targetName = util.WrapColor(targetName, this->target->nameColor);
    std::string expString = std::to_string(this->exp); //경험치
    expString = util.WrapColor(expString, "green");
    line = targetName + "는 " + expString + "만큼의 경험치를 얻었습니다.";
    util.PrintLine(line);

    line = targetName + "의 현재 경험치: " + std::to_string(this->target->exp);
    util.PrintLine(line, 2);

    Player* player = (Player*)this->target;

    //플레이어가 아이템을 획득한다.
    std::string input;
    int itemIdx = itemRand(dre);
    Item* drop = this->dropTable[itemIdx];
    player->LootItem(drop);

    delete this;
}

void Player::Attack()
{
    Utilities util;
    Combat combat;

    std::string playerName = util.WrapColor(this->name, "green");
    std::string line = playerName + "이 공격했다.";
    util.PrintLine(line, 2);

    combat.TakeDamage(this->target, this->atk);
}

Player::Player()
{
    GameSystem::player = this;

    name = "default_name";
    nameColor = "green";

    hp = 100;
    atk = 40;
    spd = 10;
    exp = 0;

    isPlayer = true;
    
    invSize = 6;
}

void Player::TakeTurn()
{
    this->ShowMenu();
}

void Player::Dead()
{
    Utilities util;

    this->isDead = true;

    std::string line = "당신은 죽었습니다...";
    line = util.WrapColor(line, "red");
    util.PrintLine(line, 2);

    delete this;
}

void Player::ShowMenu()
{
    PlayerUI pui = PlayerUI(this);
    Utilities util;
    Combat combat;

    util.TerminalColor("yellow");
    util.PrintLine("행동을 선택하십시오.");
    util.TerminalColor();
    util.PrintLine("[1] 공격", true, 200, 0);
    util.PrintLine("[2] 방어", true, 200, 0);
    util.PrintLine("[3] 기술 사용", true, 200, 0);
    util.PrintLine("[4] 아이템 및 장비", true, 200, 0);
    util.NewLine(3);

    std::string input;
    while (true) {
        std::cin >> input;
        util.NewLine(1);

        //공격
        if (input == "1") {
            this->Attack();
            break;
        }
        //관찰
        else if (input == "2") {
            util.PrintLine("당신은 방어자세를 취합니다");
            Effects* defence = new Defence(this);
            this->effects.push_back(defence);
            break;
        }
        //기술 사용
        else if (input == "3") {
            util.PrintLine("기술 선택은 아직 미구현이란다..");
            break;
        }
        //아이템 사용
        else if (input == "4") {
            std::cout << "아이템을 사용한다." << std::endl;
            UIManager(new InvUI(this)).Run();
            break;
        }

        else util.PrintLine("다시 입력하십시오.");
    }
}

void Player::LootItem(Item*& drop)
{
    Utilities util;
    UI ui;

    std::string itemname = util.WrapColor(drop->name, drop->nameColor);

    std::string line = itemname + " 발견!";
    util.PrintLine(line, 2);

    line = "아이템을 얻으시겠습니까?";
    line = util.WrapColor(line, "yellow");
    util.PrintLine(line);

    while (true) {
        if (ui.YesOrNo()) {
            std::string itemname = util.WrapColor(drop->name, drop->nameColor);
            line = itemname + " 을 획득했다!";
            util.PrintLine(line);

            this->inventory.push_back(drop);
            break;
        }
        else {
            util.PrintLine("아이템을 포기합니다.", 2);
            delete drop;
            break;
        }
    }
}

Player::~Player() {
    name = "default_name";
    hp = 100;
    atk = 10;
    spd = 10;
}

