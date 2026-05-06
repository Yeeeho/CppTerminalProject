#include "Entities.h"

class Entities;

class Combat {
    private:
    Player* player;
    public:
    Combat() = default;
    Combat(Player* p);

    void SpeedSort(Entities* entities[]);
    void TakeDamage(Entities* entity, int damage);
    void BattleUI(Entities* entities[]);
    void Loop(Entities* enemy);
};