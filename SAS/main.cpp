#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
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
istringstream* getLines(string fileName);
int getNRighe(string fileName);

main()
{
    getHack();
}

void getHack()
{
    string path = "../../whatsapp.txt";
    string line;
    string token;
    istringstream *lines = nullptr;
        lines = getLines(path);       

        for(int j = 0; j < getNRighe(path); j++){
            while(getline(lines[j],token)){

                cout << token << endl;
            }
        }
}

int getNRighe(string fileName){
    int out,i=0;
    string line;
    ifstream meth; 
        meth.open(fileName);
        
        while(getline(meth, line) && i < out){
            i++;
        }
        out = i;
        meth.close();
    return out;
}

istringstream* getLines(string fileName){
    int i=0,linesnum=getNRighe(fileName);
    string line;
    istringstream *lines = nullptr;
        lines = new istringstream[linesnum];
    ifstream meth;
        meth.open(fileName);
        while(getline(meth, line) && i < linesnum){
            lines[i].str(line + "\n");
            i++;
        }

        meth.close();
    return lines;
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
