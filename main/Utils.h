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

    template <typename T>
    void EraseOneElem(std::vector<T>& ,T);
};

template <typename T>
inline void Utilities::EraseOneElem(std::vector<T>& vector, T elemParam)
{
    if (vector.begin() == vector.end()) { //벡터가 비었을때.
        std::cout << "vector is empty!!" << std::endl;
        return;
    }

    for(auto elem = vector.begin(); elem != vector.end(); ++elem) {
        if (*elem == elemParam) {
            vector.erase(elem);
            break; //원소 하나만 찍 삭제하고 튄다.
            //근데 하나만 삭제하는게 아니면 꼬여버리므로 주의해야함.
        }
    }
}
