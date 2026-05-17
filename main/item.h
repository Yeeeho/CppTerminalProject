#pragma once

#include <string>
#include <vector>
#include <fstream>

#include "System.h"
#include "Utils.h"

struct Item {
    const bool isDebug = false;

    std::string type;
    std::string name;
    std::string nameColor;
    std::string desc;
    int value;
    
    int atk;
    int def;
    
    Item(std::string name);
};