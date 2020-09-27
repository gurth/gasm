#include <iostream>
#include <string>
#include <readline/readline.h>
#include <readline/history.h>
#include "error.h"
#include "process.h"

using namespace std;

short Translate::max_length=0;

int main()
{
    cout << "<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    cout << ">>>>>>   Gasm: A Assembly Interpreter   <<<<<<" << endl;
    cout << ">>>>>>>         Type q. to exit        <<<<<<<"<<endl;
    cout << "<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    try {
        string buff;
        Process main;
        main.ShowVirtualMemoryStruct();
        main.ShowRecommendInfo();
        main.ShowRegisterStatus();
        while (true) {
            buff = ::readline(">> ");
            if(!buff.empty())
                add_history(buff.c_str());
            if (buff == "q.") break;
            main.CmdParsing(buff);
			main.ShowRegisterStatus();
        }
    }
    catch (InitFailed& ex)
    {
        cout << ex.what() << endl;
    }
    catch (...) {
        cout << "Unknown Error." << endl;
    }
    return 0;
}