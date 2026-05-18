#pragma once

#include "Entities.h"

class EntityAI {

    public:
    Entities* ent = nullptr;
    
    EntityAI* WhatAI();
    virtual void Act();

    EntityAI(Entities* ent);
};

class SlaveAI : public EntityAI {
    public:
    SlaveAI(Entities* ent) : EntityAI(ent) {};

    void Act() override;
};

class SubterranAI : public EntityAI {
    public:
    SubterranAI(Entities* ent) : EntityAI(ent) {};

    void Act() override;
};

class RatAI : public EntityAI {
    public:
    RatAI(Entities* ent) : EntityAI(ent) {};

    void Act() override;
};