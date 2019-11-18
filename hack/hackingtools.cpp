#include <iostream>
#include <string>
#include <windows.h>

#include "hackingtools.h"

namespace hackingtools
{
    //class Target
    Target::Target(std::string name, int color)
        :TName(name),
        TColor(color)
    {}

    std::string Target::getTarget(){ return TName; }

    int Target::getColor(){ return TColor; }
    //class Target
    
    std::string Color(int color, std::string Message){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
        return Message;
    }
}