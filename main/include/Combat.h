#pragma once

class Entities;
class Player;

class Combat {
    private:
    Player* player;
    Entities* injectedEnt;
    public:
    Combat() = default;
    Combat(Player* p);

    void SpeedSort(Entities* entities[]);
    void TakeDamage(Entities* entity, int damage);
    void BattleUI(Entities* entities[]);
    void Loop(Entities* enemy);
};