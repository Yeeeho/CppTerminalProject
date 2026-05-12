#include "DataPool.h"
#include "Events.h"

DataPool::DataPool()
{
    //앞에 앰퍼샌드를 붙여야 다른 클래스 멤버함수의 주소에 접근할수 있다.
    EVENT_POOL_TEST[0] = &Events::EmptyEvent; 
    EVENT_POOL_TEST[1] = &Events::ItemEvent;
}
//하지만 이렇게 생성자로 초기화하는 방식은 번거로우니 멤버함수 테이블을 쓰는게 낫다.

//멤버함수 테이블
const DataPool::Event DataPool::EVENT_TABLE[] = {
    &Events::EmptyEvent, &Events::ItemEvent
};
