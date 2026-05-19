#include "pch.h"

#include "entities.h"
#include "skills.h"
#include "utils.h"
#include "combat.h"

void Skill::Do()
{
    std::cout << "this is virtual function for skill object" << std::endl;
}

Skill::Skill(Entities* ent)
{
    this->ent = ent;
}

void DefaultSkill::Do()
{
    std::cout << "this is default skill object" << std::endl;
}

void BasicAttack::Do()
{
    Utilities util;
    Combat combat;

    std::string entityName = util.WrapColor(ent->name, ent->nameColor);
    util.PrintLine(entityName + "가 공격합니다!", 2);

    combat.TakeDamage(ent->target, ent->atk);
}
