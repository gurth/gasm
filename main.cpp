#include <iostream>
#include <string>
#include "error.h"
#include "process.h"

using namespace std;

int main()
{
    try {
        string buff;
        Process main;
        while (true) {
            cout << ">> ";
            getline(cin, buff);
            if (buff == ".q") break;
        }
    }
    catch (InitFailed& ex)
    {
        cout << ex.what() << endl;
    }
    return 0;
}
