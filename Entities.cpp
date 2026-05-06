#include <iostream>
#include <string>

#include "Entities.h"
#include "Effects.h"
#include "Combat.h"
#include "Utils.h"

void Entities::Attack() {
    std::cout << "이 문장이 보이면 오버라이드 안된거임";
}

void Entities::TakeTurn() {
    std::cout << "이 문장이 보이면 오버라이드 안된거임";
}

void Entities::Dead()
{
    Utilities util;

    this->isDead = true;

    std::string line = this->name + "(이)가 쓰러집니다!";
    line = util.WrapColor(line, "green");
    util.PrintLine(line, 2);
}

Entities Entities::Clone()
{
    //this = Entities* entitiy = new Entitiies();
    Entities *ent = new Entities();
    return *ent;
}

void Player::Attack()
{
    Utilities util;
    Combat combat;

    Entities* target = this->target;

    std::string playerName = util.WrapColor(this->name, "green");
    std::string line = playerName + " 이 공격했다.";
    util.PrintLine(line, 2);

    combat.TakeDamage(this->target, this->atk);
}


Player::Player()
{
    name = "default_name";
    nameColor = "green";

    hp = 100;
    atk = 10;
    spd = 10;
    exp = 0;

    isPlayer = true;
}

void Player::TakeTurn()
{
    this->ShowMenu();
}

void Player::ShowMenu()
{
    Utilities util;
    Combat combat;

    util.TerminalColor("yellow");
    util.PrintLine("행동을 선택하십시오.");
    util.TerminalColor();
    util.PrintLine("[1] 공격", true, 200, 0);
    util.PrintLine("[2] 방어", true, 200, 0);
    util.PrintLine("[3] 기술 사용", true, 200, 0);
    util.PrintLine("[4] 아이템 사용", true, 200, 0);
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
            
        }

        //아이템 사용
        else if (input == "4") break;
        else util.PrintLine("다시 입력하십시오.");
    }
}

Player::~Player() {
    name = "default_name";
    hp = 100;
    atk = 10;
    spd = 10;
}

void Enemies::InitEnemyPool()
{
    Enemies enem;
    Slave* slave = new Slave();
    Subterranean* sub = new Subterranean();
    enem.ENEMY_POOL.push_back(slave);
    enem.ENEMY_POOL.push_back(sub);
}

Slave::Slave()
{
    name = "노예";
    desc = "이 친구는 말라비틀어진 사람의 몸에 전자부품이 덕지덕지 붙은 머리를 하고 있습니다.\n힘없이 움직이는 모습이 자기 의지로 움직이는 것 같진 않군요.\n";
    hp = 20;
    atk = 10;
    spd = 5;
    exp = 5;
}

void Slave::TakeTurn()
{
    this->Attack();
}

void Slave::Attack()
{
    Utilities util;
    Combat combat;

    std::string enemyName = util.WrapColor(this->name, "red");
    util.PrintLine(enemyName + "가 손을 휘적거립니다!", 2);

    combat.TakeDamage(this->target, this->atk);
}

Slave::~Slave()
{

}

void Subterranean::TakeTurn()
{
    this->Attack();
}

void Subterranean::Attack()
{
    Utilities util;
    Combat combat;

    std::string enemyName = util.WrapColor(this->name, "red");
    util.PrintLine(enemyName + "이 긴 손톱을 휘두릅니다!", 2);

    combat.TakeDamage(this->target, this->atk);
}

Subterranean::Subterranean()
{
    name = "지하인";
    desc = "이 인간과 매우 흡사한 존재는 어둠에 적응한 것인지 눈이 있어야 할 부분이 움푹 패여 있기만 합니다.\n왜인진 모르겠지만 손톱이 매우 날카롭게 발달했군요.\n";
    hp = 40;
    atk = 15;
    spd = 10;
    exp = 10;
}

Subterranean::~Subterranean()
{
}


