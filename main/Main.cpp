#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "System.h"
#include "Scenes.h"
#include "Entities.h"

void DebugLoop() {
    Player* player = new Player();
    Scenario scene = Scenario(player);
    scene.DebugScene();
}

int main() {
    
    system("");
    DebugLoop();
    
    Scenario scene = Scenario((Player*)GameSystem::player);

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



