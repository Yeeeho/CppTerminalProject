#include <iostream>
#include <random>

#include "Events.h"
#include "DataPool.h"

void Events::ItemEvent()
{
    static std::default_random_engine dre;
    static std::uniform_int_distribution<int> itemIdx(0,1);

}

void Events::EmptyEvent()
{
    std::cout << "empty event";
}
