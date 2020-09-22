#include <iostream>
#include <string>
#include "error.h"
#include "process.h"

using namespace std;

int main()
{
    cout << "<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    cout << ">>>>>>   Gasm: A Assembly Interpreter   <<<<<<" << endl;
    cout << ">>>>>>>         Type .q to exit        <<<<<<<"<<endl;
    cout << "<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    try {
        string buff;
        Process main;
        main.ShowVirtualMemoryStruct();
        while (true) {
            cout << ">> ";
            getline(cin, buff);
            if (buff == ".q") break;
            main.CmdParsing(buff);
			main.ShowRegisterStatus();
        }
    }
    catch (InitFailed& ex)
    {
        cout << ex.what() << endl;
    }
    return 0;
}