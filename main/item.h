#pragma once

#include <string>
#include <vector>
#include <fstream>

#include "json.hpp"
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
    
    Item(std::string name) {
        std::cout << "Item instantiate" << std::endl;

        if (itemPool == nullptr) std::cout << "nullptr pool" << std::endl;


        const json& item = (*itemPool)["items"][name];
        if(isDebug) std::cout << "fetch item info from pool" << std::endl;

        this->type = (*itemPool)["type"].get<std::string>();
        if(isDebug) std::cout << "fetched type" << std::endl;

        this->name = item["name"].get<std::string>();
        if(isDebug) std::cout << "fetched name" << std::endl;

        this->nameColor = item["nameColor"].get<std::string>();
        if(isDebug) std::cout << "fetched color" << std::endl;

        this->desc = item["desc"].get<std::string>();
        if(isDebug) std::cout << "fetched desc" << std::endl;
        //여기까지는 필수정보임
        //이 밑으로는 타입에 따라서 가지고 있지 않을수도 있음.

        if (item.contains("atk")) this->atk = item["atk"].get<int>();
        if(isDebug) std::cout << "fetched atk" << std::endl;

        if (item.contains("def")) this->def = item["def"].get<int>();
        if(isDebug) std::cout << "fetched def" << std::endl;
    }
};