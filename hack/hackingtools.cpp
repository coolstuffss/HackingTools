#include <iostream>
#include <string>

#include "hackingtools.h"

namespace hackingtools
{

    Target::Target(std::string name, int color)
        :TName(name),
        TColor(color)
    {}

    std::string Target::getTarget(){ return TName; }

    int Target::getColor(){ return TColor; }

    void prova(std::string sas)
    {
        std::cout << sas << std::endl;
    }
}