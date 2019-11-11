#include <iostream>
#include <string>

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

    void prova(std::string sas)
    {
        std::cout << sas << std::endl;
    }
}