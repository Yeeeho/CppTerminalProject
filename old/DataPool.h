#pragma once

#include "Entities.h"
#include "Events.h"

class Events;

class DataPool {
    private:
    public:
    DataPool();

    const std::vector<Entities*> ENEMY_POOL = {
        new Entities("slave"), new Entities("subterran")
    };

    //함수 포인터 배열, 연습용
    void (Events::*EVENT_POOL_TEST[2])();

    //멤버 함수 테이블. 모든 객체가 공유하므로 스태틱 사용.
    using Event = void (Events::*)(); //함수 포인터 타입이 너무 기니까 줄인다.
    static const Event EVENT_TABLE[];
};