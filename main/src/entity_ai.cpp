#include "pch.h"

#include "entity_ai.h"
#include "skills.h"
#include "entities.h"

std::unordered_map<std::string, EntityAI*> aiMap = {};

EntityAI::EntityAI()
{
    ent = new Entities("default");
}

void EntityAI::Act()
{
    std::cout << "this ai object is abstract" << std::endl;
}

void DefaultAI::Act()
{
    std::cout << "this is default ai" << std::endl;
}

void SlaveAI::Act()
{
    BasicAttack(ent).Do();
}

void SubterranAI::Act()
{
    BasicAttack(ent).Do();
}

void RatAI::Act()
{
    BasicAttack(ent).Do();
}
