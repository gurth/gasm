#include <iostream>
#include <string>
#include "error.h"
#include "process.h"
#include "register.h"

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

			__asm__ __volatile__("call fresh");
			main.ShowRegisterStatus();
        }
    }
    catch (InitFailed& ex)
    {
        cout << ex.what() << endl;
    }
    return 0;
}