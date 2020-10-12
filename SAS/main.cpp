#ifdef _WIN32
#include <windows.h>
#define OS "WIN"
#define Blue 1
#define Green 2
#define Cyan 3
#define Red 4
#define Purple 5
#define Yellow 6
#define Default 7
#define Gray 8
#define Bblue 9
#define Bgreen 10
#define Bcyan 11
#define Bred 12
#define Pink 13
#define Byellow 14
#define Bwhite 15
#endif // _WIN32

#ifdef __linux__
#include <unistd.h>
#define OS "LINUX"
//the following are UBUNTU/LINUX, and MacOS ONLY terminal color codes.
#define Default   "\033[0m"
#define Red     "\033[31m"      /* Red */
#define Gray "\e[2m"
#define Green   "\033[32m"      /* Green */
#define Yellow  "\033[33m"      /* Yellow */
#define Blue    "\033[34m"      /* Blue */
#define Cyan    "\033[36m"      /* Cyan */
#define Bred     "\033[1m\033[31m"      /* Bold Red */
#define Bgreen   "\033[1m\033[32m"      /* Bold Green */
#define Byellow  "\033[1m\033[33m"      /* Bold Yellow */
#define Bcyan    "\033[1m\033[36m"      /* Bold Cyan */
#define Bwhite   "\033[1m\033[37m"      /* Bold White */
#define BLACK   "\033[30m"      /* Black */
#define MAGENTA "\033[35m"      /* Magenta */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#endif // linux

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
//#include <windows.h>
#include <fstream>
#include <iterator>
#include <chrono>
#include <thread>
#include <cstring>
//#include <cstdlib>

using namespace std;

string Color(int color, string Message);
string Color(string color, string Message);
void getMetodo(string metodo);
void getHack();
string getTarget();
vector<string> getLines(string fileName);
int getNRighe(string fileName);
void slow_print(const string& str, int delay_time);

int main()
{
    cout << "Selected OS:" << OS << endl;
    string path {"../../Methods/"};
    string g;
    cin >> g;
    getMetodo(path + g + ".txt");
    //system("Pause");
    return 0;
}

void getMetodo(string metodo){
    vector<string> lines{getLines(metodo)};
    //cout << lines.size() << endl;
    #ifdef _WIN32
    for(string cx:lines){
        slow_print(Color(Gray,cx),70);
        this_thread::sleep_for(chrono::milliseconds(150));
        slow_print("... ",200);
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << Color(Green," [done]") << endl;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    Color(Default,"");
    #endif // _WIN32

    #ifdef __linux__
    for(string cx:lines){
        slow_print(Color(Gray,cx),70);
        this_thread::sleep_for(chrono::milliseconds(150));
        slow_print("... ",200);
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << Color(Green," [done]") << endl;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    #endif // linux
}

void slow_print(const string& str, int delay_time) {
    #ifdef _WIN32
    for (size_t i = 0; i != str.size(); ++i) {
        cout << str[i];
            if(isblank(str[i])) Sleep(delay_time + 150);
            else Sleep(delay_time);
    }
    #endif // _WIN32

    #ifdef __linux__
    string message = str;
    for(char c:message){
        if(isblank(c)) std::this_thread::sleep_for(std::chrono::milliseconds(delay_time+150));
        else std::this_thread::sleep_for(std::chrono::milliseconds(delay_time));
        cout << c << std::flush;
        //std::this_thread::sleep_for(std::chrono::milliseconds())
    }

    /*for (size_t i = 0; i != str.size(); ++i) {
        cout << str[i];
            if(isblank(str[i])) usleep(delay_time + 150);
            else usleep(delay_time);
    }*/
    #endif // linux
}
/*
int getNRighe(string fileName){
    int out,i=0;
    string line;
    ifstream meth{fileName};
        while(getline(meth, line) && i < out){
            i++;
        }
    out = i;
    meth.close();
    return out;
}
*/
vector<string> getLines(string fileName){
    vector<string> lines{};
    string line{""};
    ifstream meth{fileName};
    while(getline(meth, line)) {
        lines.emplace_back(line + getTarget() + ")");
    }
    /*copy(istream_iterator<string>(meth), istream_iterator<string>(),
         [&] (string const& l) -> void { lines.emplace_back(l + getTarget() + ")"); });*/
    meth.close();
    return lines;
}

string getTarget(){
    return "Amos Bruciaferri";
}

#ifdef _WIN32
    string Color(int color, string Message){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
        return Message;
    }
#endif // _WIN32

#ifdef __linux__
    string Color(string color, string Message){return color + Message + Default;}
#endif // __linux__
