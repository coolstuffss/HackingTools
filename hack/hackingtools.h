#ifndef HACKINGTOOLS_H
#define HACKINGTOOLS_H

#include <fstream>
#include <string>
#include <windows.h>

namespace hackingtools
{
    //class Traget
    class Target
    {
        public:
            Target(std::string, int);
            std::string getTarget();
            int getColor();

        private:
            std::string TName;
            int TColor;
    };
    //class Target

    std::string Color(int, std::string);
}

#endif //HACKINGTOOLS_H