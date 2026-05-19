#include "entity_ai.h"

void AIManager::LoadMap()
{
    aiMap["default"] = new const DefaultAI();
    aiMap["subterran"] = new const SubterranAI();
    aiMap["slave"] = new const SlaveAI();
}