#pragma once

#include <string>
#include <unordered_map>

class Entities;
class EntityAI;

static std::unordered_map<std::string, const EntityAI*> aiMap;

class AIManager {

    Entities* ent = nullptr;

    public:
    AIManager() = default;

    void LoadMap(); //ai_map.cpp 에 정의 존재.
};

class EntityAI {

    public:
    Entities* ent = nullptr;
    
    virtual void Act(Entities*);
};

class DefaultAI : public EntityAI {
    public:

    void Act(Entities*) override;
};

class SlaveAI : public EntityAI {
    public:

    void Act(Entities*) override;
};

class SubterranAI : public EntityAI {
    public:

    void Act(Entities*) override;
};

class RatAI : public EntityAI {
    public:

    void Act(Entities*) override;
};