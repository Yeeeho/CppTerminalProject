#include <string>

#include "Entities.h"
#include "Utils.h"

Utilities util;

void Entities::Attack(Entities* target) {}

void Player::Attack(Entities* target)
{
    std::string line = this->name + "이 공격했다.";
    util.PrintLine(line);

    int prevTargetHp = target->hp;
    target->hp = target->hp - this->atk;

    std::string thp = std::to_string(target->hp);
    std::string pthp = std::to_string(prevTargetHp);
    line = "적의 체력 변화: " + pthp + "->" + thp;
    util.PrintLine(line);
}

Player::Player()
{
    name = "default_name";
    hp = 100;
    atk = 10;
    spd = 10;
}
Player::~Player() {
    name = "default_name";
    hp = 100;
    atk = 10;
    spd = 10;
}

Slave::Slave() {
    name = "노예";
    desc = "이 친구는 말라비틀어진 사람의 몸에 전자부품이 덕지덕지 붙은 머리를 하고 있습니다\n";
    hp = 20;
    atk = 10;
    spd = 5;
}

Slave::~Slave()
{
}
