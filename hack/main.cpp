#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>

#include "hackingtools.h"

using namespace std;

/*
    funzione per riconoscere l'opzione inserita
    parametri:
        char*: stringa contenente l'opzione
    ritorno:
        0: se non si ha inserito nessusa delle opzioni possibili
        1: se l'opzione è "-m"
        2: se l'opzione è "-w"
*/
int options(char*);

/*
    funzione di aiuto che mostra le possibili opzioni da riga di comando
*/
void help();

/*
    funzione per hackerare bersagli multipli
    parametri:
        char**: array di stringa contenente i bersagli
        int: dimensione dell'array
*/
void multipletargets(int, char**);

int main(int argc, char **argv)
{
    int optionNumber = argc > 1 ? options(argv[1]) : -1;
    hackingtools::Target t1{"Amos", 3};

    cout << hackingtools::Color(3, t1.getTarget()) << endl << t1.getColor() << endl;
    hackingtools::Color(7, "");

    switch (optionNumber)
    {
        case 1:
            help();
            break;

        case 2:
            //multipletargets(argc, argv);
            break;

        case 3:
            cout << "whataspp exploit not implemented yet" << endl;
            break;
        
        case 0:
            cout << "hack: Option " << argv[1] << " is not supported" << endl << "run hack -h to display all of the possible options" << endl;
            break;

        default:
            cout << "hack: must specify one of the possible options" << endl << "run hack -h to display all of the possible options" << endl;
            break;
    }
    

    return 0;
}

int options(char *option)
{
    int response = 0;

    if(strcmp(option, "-h") == 0)
        response = 1;
    
    if(strcmp(option, "-m") == 0)
        response = 2;

    if(strcmp(option, "-w") == 0)
        response = 3;

    return response;
}

void help()
{
    string line;
    ifstream helpFile;
    
    helpFile.open("../../help.txt");
    if(!helpFile)
    {
        cout << "no such help file!" << endl;
        exit(1);
    }

    while(getline(helpFile, line))
        cout << line << endl;

    helpFile.close();
}

void multipletargets(int N, char **targets)
{
    cout << "number of targets: " << N - 2 << endl << endl; //two because the first one is the name of the project and the second one the option -m (multiple targets)
    cout << "--------------------" << endl << endl;

    for(int i = 2; i < N; i++)
    {
        cout << "initializing attcsks to target no: " << i - 1 << ' ' << targets[i] << endl;
        this_thread::sleep_for(chrono::milliseconds(760));
    }

    cout << endl << "--------------------" << endl << endl;

    for(int i = 2; i < N; i++)
    {
        cout << "hacking target no: " << i - 1 << " (" << targets[i] << ')';
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << " done" << endl;
        this_thread::sleep_for(chrono::milliseconds(300));
    }

    cout << endl << "--------------------" << endl << endl;
    cout << "all hackings done!" << endl << "number of files stolen " << 126500 + ((N - 3) * 15421) << endl;
}