#pragma once

class Entities;

class Skill {

    
    public:
    Entities* ent = nullptr;

    virtual void Do();

    Skill() = default;
    Skill(Entities* ent);
};

class DefaultSkill : public Skill {    

    
    public:
    void Do() override;

    DefaultSkill(Entities* ent) : Skill(ent) {}; //부모 생성자 호출
};

class BasicAttack : public Skill {
    
    public:
    void Do() override;

    BasicAttack(Entities* ent) : Skill(ent) {};
};