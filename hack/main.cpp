#include <iostream>
#include <thread>
#include <chrono>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    cout << "number of targets: " << argc - 2 << endl << endl; //two because the first one is the name of the project and the second one the option -m (multiple targets)
    cout << "--------------------" << endl << endl;

    for(int i = 2; i < argc; i++)
    {
        cout << "initializing attcsks to target no: " << i - 1 << ' ' << argv[i] << endl;
        this_thread::sleep_for(chrono::milliseconds(760));
    }

    cout << endl << "--------------------" << endl << endl;

    for(int i = 2; i < argc; i++)
    {
        cout << "hacking target no: " << i - 1 << " (" << argv[i] << ')';
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << " done" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    cout << endl << "--------------------" << endl << endl;
    cout << "all hackings done!" << endl << "number of files stolen " << 126500 + ((argc - 3) * 15421);

    return 0;
}

void Whatsapp(){
        cout << "" << i - 1 << " (" << argv[i] << ')';
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << " done" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
}
