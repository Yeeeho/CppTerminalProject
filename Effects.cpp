#include "Effects.h"

Defence::Defence(Entities *ent)
{
    name = "방어";
    lastTurn = 1;
    buffDef = ent->hp/10;
}
