#include <iostream>

#include "entity_ai.h"
#include "skill.h"


EntityAI::EntityAI(Entities* ent)
{
    this->ent = ent;
}

void EntityAI::Act()
{
    std::cout << "virtual function for entity ai" << std::endl;
}

void SlaveAI::Act()
{
    BasicAttack(this->ent).Do();
}

void SubterranAI::Act()
{
    BasicAttack(this->ent).Do();
}

void RatAI::Act()
{
    BasicAttack(this->ent).Do();
}
