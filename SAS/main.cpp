#include <iostream>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <fstream>

using namespace std;

#define RESET_COLOR "\e[m"
#define MAKE_GREEN "\e[32m"

string Color(int color, string Message);
void getMetodo(string metodo);

int main()
{
    ifstream ifs("whatsapp.txt");
    string content((istreambuf_iterator<char>(ifs)),
                       (istreambuf_iterator<char>()));

    cout << content;
    string metodo;
    cout << MAKE_GREEN "this will show up green" RESET_COLOR "\n";
    cout << Color(12,"Hey! I'm in color 12!") << endl; //Sets a color and prints the text
    cout << Color(10," Nice C: 10"); //Sets another color and prints the text
    //cin >> metodo;
    //getMetodo(metodo);
    Color(7, "");
    return 0;
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
