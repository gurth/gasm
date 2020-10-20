#include <iostream>
#include <string>
#include <readline/readline.h>
#include <readline/history.h>
#include <yaml-cpp/yaml.h>
#include "error.h"
#include "process.h"

using namespace std;

short Translate::max_length=0;

int main(int argc, char * argv[])
{
    cout << "<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    cout << ">>>>>>   Gasm: A Assembly Interpreter   <<<<<<" << endl;
    cout << ">>>>>>>         Type q. to exit        <<<<<<<"<<endl;
    cout << "<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    try {
        string buff;
        Process main;
        main.ArgParsing(argc,argv);
        if(!main.init()) throw InitFailed();
        main.ShowVirtualMemoryStruct();
        main.ShowRecommendInfo();
        main.ShowRegisterStatus();
        read_history("./.gasm/history");
        while (true)
        {
            if(main.input_mode==0)
                buff = ::readline(">> ");
            else if(main.input_mode==1)
                main.FillCmdFromFile(buff);
            if (!buff.empty())
                add_history(buff.c_str());
            if (buff == "q.") break;
            else if(buff.empty()) continue;
            main.CmdParsing(buff);
			main.ShowRegisterStatus();
        }
        write_history("./.gasm/history");
        main.uninit();
    }
    catch (InitFailed& ex)
    {
        cout << ex.what() << endl;
    }
    catch (YAML::ParserException& ex)
    {
        cout << ex.what() << endl;
    }
    catch (...)
    {
        cout << "Unknown Error." << endl;
    }
    return 0;
}