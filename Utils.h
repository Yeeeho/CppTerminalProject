#ifndef UTILS_H
#define UTILS_H

#include <string>

class Utilities {
    public:
    void Wait005();
    void Wait05();
    void Wait(int milsec);

    std::string DefaultInput();
    void PrintLine(std::string string, bool isNewLine = true, int lineInterval = 50, int wordInterval = 20);
    void LoadingLine(std::string message ,int iteration);

    void NewLine5();
    void NewLine(int lines);

    void TerminalColor(std::string color);
    void TerminalColor();

    void DotEffect();

};

#endif