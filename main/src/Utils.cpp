#include "pch.h"

#include "utils.h"
#include "entities.h"

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

void Utilities::PrintLine(std::string string, int newLines, int lineInterval, int wordInterval) {
    for (int i = 0; i < string.length(); i++) {
        std::cout << string[i] << std::flush;
        Wait(wordInterval);
    }
    
    NewLine(newLines);

    Wait(lineInterval);
}
void Utilities::NewLine5() {
    std::cout << "\n\n\n\n\n";
}
void Utilities::NewLine(int lines)
{
    for (int i = 0; i < lines; i++) {
        std::cout << "\n";
    }
}

std::string Utilities::TerminalColor(std::string color) 
{
    std::string ansiColor;

    if (color == "red") {
        ansiColor = "\033[31m";
    }
    else if (color == "blue") {
        ansiColor = "\033[34m";
    }
    else if (color == "green") {
        ansiColor = "\033[32m";
    }
    else if (color == "yellow") {
        ansiColor = "\033[33m";
    }
    else if (color == "cyan") {
        ansiColor = "\033[36m";
    }
    else if (color == "default") {
        ansiColor = "\033[0m";
    }
    std::cout << ansiColor;
    return ansiColor;
}

std::string Utilities::TerminalColor()
{
    std::string ansiColor;
    ansiColor = "\033[0m";

    std::cout << ansiColor;
    return ansiColor;
}

std::string Utilities::WrapColor(std::string line, std::string color)
{
    std::string ansiColor = TerminalColor(color);
    std::string defaultColor = TerminalColor();

    line = ansiColor + line + defaultColor;
    return line;
}

std::string Utilities::EntityColorName(Entities *entity)
{
    std::string name = entity->name;
    name = WrapColor(name, entity->nameColor);
    return name;
}

void Utilities::LoadingLine(std::string message, int iteration)
{
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

void Utilities::IntClamp(int &num, int min, int max)
{
    if (num > max) num = max;
    else if (num < min) num = min;
}