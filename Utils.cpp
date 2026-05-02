#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "Utils.h"

void Utilities::Wait05() {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}
void Utilities::Wait005() {
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}
void Utilities::Wait(int milsec) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milsec));
}

std::string Utilities::DefaultInput() {
    std::string string;
    std::cin >> string;
    NewLine5();
    return string;
}

void Utilities::PrintLine(std::string string, bool isNewLine, int lineInterval, int wordInterval) {
    for (int i = 0; i < string.length(); i++) {
        std::cout << string[i] << std::flush;
        Wait(wordInterval);
    }
    if (isNewLine) std::cout << "\n";

    Wait(lineInterval);
}
void Utilities::NewLine5() {
    std::cout << "\n\n\n\n\n";
}
void Utilities::LoadingLine(std::string message ,int iteration) {
    PrintLine(message, false);
    for (int i = 0; i < iteration; i++) {
        std::cout << "\r\033[K";
        std::cout << message << std::flush;
        DotEffect();
    }
    std::cout << "\n";
}

void Utilities::DotEffect() {
    for (int i = 0; i < 3; i++) {
        std::cout << "." << std::flush;
        Wait05();
    }
}



