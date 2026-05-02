#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "Scenes.h"


int main() {
    Scenario scene;
    scene.Init();
    while (true) {
        if (scene.curScene == "intro1") {
            std::cout << "intro1 을 실행합니다.";
            break;
        }
        else if (scene.curScene == "cut_comm_ending") {
            std::cout << "통신종료 엔딩을 실행합니다.";
            scene.CutCommEnding();
            break;
        }
        else break;
    }
    return 0;
}