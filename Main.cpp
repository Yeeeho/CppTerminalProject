#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "Scenes.h"
#include "Entities.h"

Player* player = new Player();
//씨발 생성자 주입
Scenario scene = Scenario(player);

void DebugLoop() {
    scene.DebugScene();
}


int main() {
    system("");
    DebugLoop();

    while (true) {
        scene.Init();
        if (scene.curScene == "intro1") {
            // std::cout << "intro1 을 실행합니다.";
            scene.Intro1();
            break;
        }
        else if (scene.curScene == "cut_comm_ending") {
            // std::cout << "통신종료 엔딩을 실행합니다.";
            scene.CutCommEnding();
            break;
        }
        else break;
    }
    return 0;
}





