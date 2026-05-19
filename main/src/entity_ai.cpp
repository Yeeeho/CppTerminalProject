#include <iostream>

#include "entity_ai.h"
#include "skills.h"

void EntityAI::Act(Entities* ent)
{
    std::cout << "this object is abstract" << std::endl;
}

void DefaultAI::Act(Entities *)
{
    std::cout << "this is default ai" << std::endl;
}

void SlaveAI::Act(Entities* ent)
{
    BasicAttack(ent).Do();
}

void SubterranAI::Act(Entities* ent)
{
    BasicAttack(ent).Do();
}

void RatAI::Act(Entities* ent)
{
    BasicAttack(ent).Do();
}

