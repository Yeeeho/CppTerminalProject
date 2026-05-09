#pragma once

#include "Entities.h"
#include "Items.h"
#include "Events.h"

class Events;

class DataPool {
    private:
    public:
    DataPool();

    const std::vector<Enemies*> ENEMY_POOL = {
        new Slave(), new Subterranean()
    };

    const std::vector<Equipments*> EQUIP_POOL = {
        new IronDagger(), new RagCape()
    };

    //함수 포인터 배열, 연습용
    void (Events::*EVENT_POOL_TEST[2])();

    //멤버 함수 테이블. 모든 객체가 공유하므로 스태틱 사용.
    using Event = void (Events::*)(); //함수 포인터 타입이 너무 기니까 줄인다.
    static const Event EVENT_TABLE[];
};