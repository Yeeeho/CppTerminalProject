#include "Entities.h"

class Combat {
    private:
    Player* player;
    public:
    Combat() = default;
    Combat(Player* p);
    void SpeedSort(Entities* entities[]);
    void Loop(Entities* enemy);
};