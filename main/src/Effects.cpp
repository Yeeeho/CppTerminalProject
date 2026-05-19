#include "effects.h"
#include "entities.h"

Defence::Defence(Entities *ent)
{
    this->name = "방어";
    this->lastTurn = 2;
    this->buffDef = ent->hp/10;
}
