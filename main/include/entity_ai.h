#pragma once

#include <string>
#include <unordered_map>

class Entities;
class EntityAI;

extern std::unordered_map<std::string, EntityAI*> aiMap;

class AIManager {    
    Entities* ent = nullptr;

    public:

    AIManager() = default;
};

class EntityAI {

    public:
    Entities* ent = nullptr;
    
    EntityAI();

    virtual void Act();
};

class DefaultAI : public EntityAI {
    public:
    DefaultAI() = default;

    void Act() override;
};

class SlaveAI : public EntityAI {
    public:
    SlaveAI() = default;

    void Act() override;
};

class SubterranAI : public EntityAI {
    public:
    SubterranAI() = default;

    void Act() override;
};

class RatAI : public EntityAI {
    public:
    RatAI() = default;

    void Act() override;
};