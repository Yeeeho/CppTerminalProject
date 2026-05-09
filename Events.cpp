#include <iostream>
#include <random>

#include "Events.h"
#include "DataPool.h"

void Events::ItemEvent()
{
    static std::default_random_engine dre;
    static std::uniform_int_distribution itemIdx(0,1);

    DataPool pool;
    Equipments* eq = new Equipments();
    *eq = *pool.EQUIP_POOL[itemIdx(dre)];

    std::cout << eq->name;
}

void Events::EmptyEvent()
{
    std::cout << "empty event";
}
