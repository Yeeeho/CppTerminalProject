#pragma once

#include <string>

#include "Entities.h"

class Entities;
class Utilities;

// static Utilities* util; 전역에 쓸 인스턴스 였던것

class Utilities {
    public:
    void Wait005();
    void Wait05();
    void Wait(int milsec);

    std::string DefaultInput();
    void PrintLine(std::string string, int newLines = 1, int lineInterval = 50, int wordInterval = 20);
    void LoadingLine(std::string message ,int iteration);

    void NewLine5();
    void NewLine(int lines);

    std::string TerminalColor(std::string color);
    std::string TerminalColor();
    std::string WrapColor(std::string line, std::string color);
    std::string EntityColorName(Entities* entity);

    void DotEffect();

    void IntClamp(int& num, int min, int max);
    
    void YesOrNo(std::string& input);
};
