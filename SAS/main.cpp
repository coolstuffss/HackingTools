#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <fstream>
#include <iterator>
#include <chrono>
#include <thread>

using namespace std;

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
#define BYellow 14
#define Bwhite 15

string Color(int color, string Message);
void getMetodo(string metodo);
void getHack();
string getTarget();
vector<string> getLines(string fileName);
int getNRighe(string fileName);

int main()
{
    string path {"../../Methods/"};
    string g;
    cin >> g;
    getMetodo(path + g + ".txt");
    return 0;
}

void getMetodo(string metodo){
    vector<string> lines{getLines(metodo)};
    //cout << lines.size() << endl;
    for(string cx:lines){
        cout << Color(Gray,cx);
        this_thread::sleep_for(chrono::milliseconds(760));
        cout << Color(Green," [done]") << endl;
        this_thread::sleep_for(chrono::milliseconds(400));
    }
    Color(Default,"");
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
    return "SteU";
}
/*
void getMetodo(string metodo){
    string postfix=".txt";
    ofstream.open(strcat(metodo,postfix));
}
*/
string Color(int color, string Message){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    return Message;
}