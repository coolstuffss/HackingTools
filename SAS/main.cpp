#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

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

int main()
{
    getHack();
    return 0;
}

void getHack()
{
    string line;
    fstream meth{"whatsapp.txt", ios::in};
    string out;
    string *lines=nullptr;

        if(!meth)
        {
            cout << "no such file!" << endl;
            exit(1);
        }

    int linesnum=0;
        while(getline(meth,line)){
            linesnum++;
        }
    cout << linesnum;
    lines = new string[linesnum];
    int i=0;
        while(getline(meth,line) && i<linesnum){
            lines[i] = new string;
            lines[i] = line;
            i++;
        }
    meth.close();

        for(int j=0;j<linesnum;j++){
            cout << lines[j] << endl;
        }
}
string getTarget(){
    return "Amos";
}
/*
void getMetodo(string metodo){
    string postfix=".txt";
    ofstream.open(strcat(metodo,postfix));
}
*//*
string Color(int color, string Message){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    return Message;
}
*/
