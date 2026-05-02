#include <iostream>
#include <string>

#include "Utils.h"
#include "Scenes.h"
#include "Entities.h"

void Scenario::YesOrNo(std::string& input)
{
    std::cout << "[1] 예\n";
    std::cout << "[2] 아니오\n";
    util.PrintLine("숫자를 입력해서 선택하십시오.\n\n");
    std::cin >> input;
    util.NewLine5();
}

void Scenario::Init() {
    player = new Player(); 

    curScene = "intro0";

    std::cout << "\n\n\n";
    util.PrintLine("Praise the Machine-spirit");
    util.PrintLine("머신-스피릿에게 영광을", false);
    std::cout << "\n\n\n";
    std::cout << "\'예아\' 를 입력하여 게임을 시작하십시오\n\n";
    std::cout << "\'안해\' 를 입력하여 게임을 종료할 수 있습니다\n\n";

    std::string input;
    
    while (1) {
        input = util.DefaultInput();

        if (!input.compare("예아")) {
            break;
        }
        if (!input.compare("안해")) {
            std::cout << "게임을 종료합니다...\n\n";
            return;
        }
        else {
            std::cout << "다시 입력해 주십시오.\n\n";
        }
    }

    std::cout << "이름을 입력해 주십시오.\n\n";

    while(1) {
        std::cin >> input;
        player->name = input;
        util.NewLine5();

        std::string line = "[플레이어 이름]: " + input + "\n\n";
        util.PrintLine(line);
        util.PrintLine("이 이름으로 하시겠습니까? 중간에 못바꾼다구~\n\n");

        YesOrNo(input);

        util.NewLine5();

        if (input == "1") {
            util.PrintLine("이름을 정했습니다\n\n");
            break;
        }
        else {
            util.PrintLine("다시 입력해 주십시오.");
            continue;
        }
    }

    //인트로 스킵 포인트
    util.PrintLine("이미 인트로를 본 사람이거나.. 디버깅을 하고 있는 컴붕이라면 여기서 건너뛸 수 있습니다.");
    util.PrintLine("특정 키워드를 입력해서 건너뛰세요!");
    while (true) {
        std::cin >> input;
        util.NewLine5();

        if (input == "그래") {
            util.PrintLine("키워드 입력 성공.");
            curScene = "intro1";
            return;
        }
        else {
            util.PrintLine("");
            break;
        }
    }

    util.DotEffect();
    std::cout << "\n";

    std::string line = "어서 오십시오 사용자 \'" + player->name + "\'\n";
    util.PrintLine(line, true, 300);
    util.PrintLine("터미널 아이디: A2D934F1");
    util.PrintLine("현재 1903 건의 부재중 전화가 있습니다.");
    util.PrintLine("현재 10234 건의 미열람 메일이 있습니다.");
    util.PrintLine("현재 85879 건의 시스템 경고 메시지를 확인했습니다.");
    util.LoadingLine("시스템 점검 서브루틴 실행중", 2);
    util.PrintLine("현재 1509 건의 중대한 시스템 결함을 발견했습니다.");
    util.LoadingLine("시스템 복구 서브루틴 실행중", 3);
    util.PrintLine("에러코드 1233: 손상 임계점 초과");
    util.LoadingLine("시스템 관리자에게 보고서 제출중", 2);
    util.PrintLine("에러코드 404: 존재하지 않는 주소입니다.");
    util.LoadingLine("비상연락망에 브로드캐스팅을 시도합니다", 2);
    util.PrintLine("B1E900A2 터미널에서 신호를 수신했습니다. 통신을 시작하시겠습니까?");

    while(true) {
        YesOrNo(input);

        util.NewLine5();

        if(input == "1") {
            util.PrintLine("통신을 시작합니다.");
            curScene = "intro1";
            return;
        }
        else if (input == "2") {
            util.PrintLine("통신을 종료합니다.");
            curScene = "cut_comm_ending";
            return;
        }
        else {
            util.PrintLine("다시 입력해 주십시오.");
        }
    }
}

void Scenario::CutCommEnding()
{
    util.LoadingLine("",1);
    util.PrintLine("B1E900A2 터미널과의 통신이 끊어졌습니다.");
    util.LoadingLine("통신 가능한 단말기를 검색중", 2);


    util.PrintLine("터미널을 찾지 못했습니다.");
    util.PrintLine("현재 수행 가능한 모든 서브루틴을 실행했습니다.");
    util.PrintLine("시스템 프로토콜 C290에 따라 본 터미널은 연결이 종료됩니다.");
    util.PrintLine("지금까지 이용해 주셔서 감사합니다.");

    util.PrintLine("....", true, 50, 500);
    util.PrintLine("...", true, 50, 500);
    util.PrintLine("..", true, 50, 500);

    util.PrintLine("\033[31m엔딩 1: 모르는 전화는 받지말랬다", false, 50, 100);
    std::cout << "\033[0m\n";

    util.LoadingLine("", 2);

    util.PrintLine("아참, 건너뛰기 키워드는 \'그래\' 입니다.");
}

void Scenario::Intro1()
{
    util.PrintLine("");
}
