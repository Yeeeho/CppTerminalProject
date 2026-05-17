#include <iostream>
#include <fstream>
#include <string>

#include "json.hpp"

using json = nlohmann::json;

std::fstream item("test.json");
json jitem = json::parse(item);
json itemPool = jitem["items"];

struct Item {
    std::string type;
    std::string name;
    int id;
    int value;

    Item(std::string n) {
        json item = itemPool[n];
        
        type = jitem["type"].get<std::string>();
        name = n;
        id = item["id"].get<int>();
        value = item["value"].get<int>();
    }
};

int main() {

    Item it = Item("babo");
    std::cout << it.name << std::endl;
    std::cout << it.type << std::endl;
    std::cout << it.id << std::endl;
    std::cout << it.value << std::endl;
}