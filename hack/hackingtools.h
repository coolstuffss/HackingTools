#include <fstream>
#include <string>

#ifndef HACKINGTOOLS_H
#define HACKINGTOOLS_H
namespace hackingtools
{
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

    void prova(std::string);
}

#endif //HACKINGTOOLS_H