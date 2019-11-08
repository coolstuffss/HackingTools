#include <iostream>
#include <thread>
#include <chrono>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <windows.h>

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
    funzione per hackerare bersagli multipli
    parametri:
        char**: array di stringa contenente i bersagli
        int: dimensione dell'array
*/
void multipletargets(int, char**);

int main(int argc, char **argv)
{
    int optionNumber = options(argv[1]);
    /*Your favorite pausing goes here*/
    switch (optionNumber)
    {
    case 1:
        //multipletargets(argc, argv);
        break;

    case 2:
        cout << "whataspp exploit not implemented yet" << endl;
        break;
    
    case 0:
        cout << "unknown option: " << argv[1] << endl << "to seek help try running hack -h" << endl;
        break;

    default:
        cout << "no options inserted" << endl << "to seek help try running hack -h" << endl;
        break;
    }
    

    return 0;
}

int options(char *option)
{
    int response = 0;

    if(strcmp(option, "-m") == 0)
        response = 1;
    else
    {
        if(strcmp(option, "-w") == 0)
            response = 2;
    }

    return response;
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
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    cout << endl << "--------------------" << endl << endl;
    cout << "all hackings done!" << endl << "number of files stolen " << 126500 + ((N - 3) * 15421) << endl;
}