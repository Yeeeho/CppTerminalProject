#include "Entities.h"

class Combat {
    private:
    Player* player;
    public:
    Combat() = default;
    Combat(Player* p);

    void Loop(Entities* enemy);

    void SpeedSort(Entities* entities[]);
    void BattleUI(Entities* entities[]);
};