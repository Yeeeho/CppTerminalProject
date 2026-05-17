#pragma once

#include <vector>

#include "Entities.h"

class UI; //전방 선언

class UIManager : public GameSystem { //state machine pattern 용 객체, 무조건 스택에만 인스턴스 생성.
    public:
    
    std::vector<UI*> uiStack; //스테이트 객체가 관리하는 UI 스택
    UI* currentUI;

    UIManager() = default;
    UIManager(UI* initUI); //초기 UI객체를 할당해서 currentUI에 저장해준다.

    void Run();
    void Stack();
    UI* Goback(); //스택을 pop 하고, 이전 UI 객체를 반환한다.
};

class UI : public GameSystem {
    public:
    
    //스택되었는지 확인하기 위한 변수
    bool isStacked = false; //이미 스택되어있으면 스택하지 않음.

    //UIState 상태 제어용 변수
    bool isForDelete = false; //삭제할 예정인가?
    bool isEnd = false; //UI 루프를 탈출하기 위한 플래그 변수.
    bool isBack = false; //UI 루프에서 뒤로 가기 위한 플래그 변수.

    virtual UI* Show(); // UI를 출력하고 다음에 사용할 UI 객체를 반환한다.
    virtual UI* Clone() const; //공변 반환을 위한 가상함수.

    bool YesOrNo(); //예, 아니오를 물어보는 함수.
};

class UIState : public UI { //상태 제어용 클래스
    public:
    UIState() = default;
    UIState(std::string state);
};

class PlayerUI : public UI {
    private:
    public:
    Player* player = (Player*) GameSystem::player;

    PlayerUI() = default;
    PlayerUI(Player*);
};

class InvUI: public PlayerUI {
    public:

    InvUI(Player*);
    UI* Show() override;
    UI* Clone() const override;
};

class ItemUI : public PlayerUI {
    private:
    public:
    Item* item;

    ItemUI() = default;
    ItemUI(Item*);

    UI* Show() override; //아이템 정보를 출력함.
    UI* Clone() const override;

    void ShowInfo();
    void ShowName();
    void ShowDesc();
    void ShowVal();

    void DisPoseButton(int num);
    void GobackButton(int num);

    void ShowAtk();
    void ShowDef();
};

class DisPoseUI : public ItemUI {
    private:
    
    public:

    UI* Show() override;
    UI* Clone() const override;

    DisPoseUI(Item*);
};


