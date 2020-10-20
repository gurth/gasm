//
// Created by gurth on 9/16/20.
//

#include <iostream>
#include <string>
#include <getopt.h>
#include <yaml-cpp/yaml.h>
#include "error.h"
#include "process.h"
#include "register.h"

using namespace std;

Process::Process()
{
    this_info=default_info;
}

Process::Process(system_info sysinfo)
{
    this_info=sysinfo;
}

Process::~Process()
{
}

void Process::CmdParsing(std::string cmd)
{
    try
    {
        Translate trans(cmd);
        trans.AttchSuffix(suffix,this_info.suffix,this_info.exe_buff);
        trans.CopyCode((char*)exe_cmd);
        __asm__ __volatile__("call regbak");
        __asm__ __volatile__("call restore");
        ex();
        __asm__ __volatile__("call fresh");
        __asm__ __volatile__("call regdisbak");
        reg.rax=ptrtable[0];
    }
    catch (ErrorCommand ex) {
        cout << ex.what() << endl;
    }
    catch (PipeCannotOpen ex) {
        cout << ex.what() << endl;
    }
    catch (FileCannotOpen ex) {
        cout << ex.what() << endl;
    }
    catch (...) {
        cout << "Unknown Error." << endl;
    }
}

void Process::ShowRegisterStatus()
{
    cout << "Register info:"<<endl;
    printf("rax=0x%016lx rbx=0x%016lx rcx=0x%016lx rdx=0x%016lx\n",reg.rax,reg.rbx,reg.rcx,reg.rdx);
    printf("r8 =0x%016lx r9 =0x%016lx r10=0x%016lx r11=0x%016lx\n",reg.r8,reg.r9,reg.r10,reg.r11);
    printf("r12=0x%016lx r13=0x%016lx r14=0x%016lx r15=0x%016lx\n",reg.r12,reg.r13,reg.r14,reg.r15);
    printf("rsi=0x%016lx rdi=0x%016lx\n",reg.rsi,reg.rdi);
    printf("flags: CF=%d AF=%d ZF=%d SF=%d\n",
           reg.flags.CF,reg.flags.AF,reg.flags.ZF,reg.flags.SF);
}

void Process::ShowVirtualMemoryStruct()
{
    cout << "MemoryStruct:"<<endl;
    cout << "----------------------------------------------" <<endl;
    cout << "|  d    | s  |               c                |"<<endl;
    cout << "----------------------------------------------" << endl;
    cout << "*            *" << endl;
    cout << "data         stack" <<endl;
}

void Process::ShowRecommendInfo()
{
    cout << "Recommend:"<<endl;
    printf("Data segment base at: %p\n",data_seg);
}

void Process::ArgParsing(int argc, char **argv)
{
    static option long_options[]={
            {"gasmfile", required_argument, nullptr, 'g'},
            {"help",no_argument, nullptr,'h'},
            {"config",required_argument, nullptr,'c'},
            {0, 0, 0, 0}
    };
    static const char simple_options[]="g:hc:";
    int longindex = -1;
    int opt;
    while (true)
    {
        opt = getopt_long(argc, argv, simple_options, long_options, &longindex);
        if(opt == -1) break;
        switch (opt)
        {
            case 'g':
                gasmfile.open(optarg,ios::in);
                if(!gasmfile.is_open())
                    throw FileCannotOpen();
                input_mode=1;
                break;
            case 'c':
                GetConfig(optarg);
                break;
            case 'h':
            default:
                ShowHelpInfo();
                exit(0);
                break;
        }
    }
}

void Process::FillCmdFromFile(std::string& buff)
{
    if(gasmfile.eof()) {
        input_mode = 0;
        gasmfile.close();
        gasmfile.clear();
    }
    else{
        cout << ">> ";
        getline(gasmfile, buff);
        cout << buff;
        getchar();
    }
    return;
}

void Process::GetConfig(std::string configfile)
{
    ifstream inconf(configfile);
    if(!inconf.is_open())
        throw FileCannotOpen();
    YAML::Node yamconf=YAML::Load(inconf);
    this_info.data=yamconf["system_config"]["data"].as<size64>();
    this_info.mem=yamconf["system_config"]["memory"].as<size64>();
    this_info.stack=yamconf["system_config"]["stack"].as<size64>();
    inconf.close();
}

void Process::ShowHelpInfo()
{
    cout << "OVERVIEW: gasm: An Assembly Interpreter.\n\t see: http://github.com/GurthPalarran/gasm"<<endl;
    cout << "USAGE: gasm [options] <inputs>"<<endl;
    cout << "OPTIONS:"<<endl;
    cout << "\t--gasmfile, -g <gasm file>\tRead command from gasm file "<<endl;
    cout << "\t--config, -c <config file>\tRead config from .yaml file "<<endl;
    cout << "\t--help\t\t\t\tPrint this help text"<<endl;
}