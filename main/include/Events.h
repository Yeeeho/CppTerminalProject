#pragma once

#include <string>
#include <unordered_map>

class Events;

extern std::unordered_map<std::string, Events*> eventMap;

class Events {
    public:
    virtual void Run();
};

class ItemsEvent : public Events {
    public:
    void Run() override;
};

class EmptyEvent : public Events {
    public:
    void Run() override;
};