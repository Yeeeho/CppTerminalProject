#include "Effects.h"

Defence::Defence(Entities *ent)
{
    name = "방어";
    lastTurn = 2;
    buffDef = ent->hp/10;
}
