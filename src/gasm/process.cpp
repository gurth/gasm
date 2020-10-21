//
// Created by gurth on 9/16/20.
//

#include <iostream>
#include <string>
#include <getopt.h>
#include <yaml-cpp/yaml.h>
#include "error.h"
#include "process.h"

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
        trans.ShowMachineCode();
        trans.AttchSuffix(suffix,this_info.suffix);
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
    if(reg.rax!=regprevious.rax)
        printf("\033[34mrax=0x%016lx\033[m ",reg.rax);
    else
        printf("rax=0x%016lx ",reg.rax);
    if(reg.rbx!=regprevious.rbx)
        printf("\033[34mrbx=0x%016lx\033[m ",reg.rbx);
    else
        printf("rbx=0x%016lx ",reg.rbx);
    if(reg.rcx!=regprevious.rcx)
        printf("\033[34mrcx=0x%016lx\033[m ",reg.rcx);
    else
        printf("rcx=0x%016lx ",reg.rcx);
    if(reg.rdx!=regprevious.rdx)
        printf("\033[34mrdx=0x%016lx\033[m ",reg.rdx);
    else
        printf("rdx=0x%016lx ",reg.rdx);
    printf("\n");
    if(reg.r8!=regprevious.r8)
        printf("\033[34mr8 =0x%016lx\033[m ",reg.r8);
    else
        printf("r8 =0x%016lx ",reg.r8);
    if(reg.r9!=regprevious.r9)
        printf("\033[34mr9 =0x%016lx\033[m ",reg.r9);
    else
        printf("r9 =0x%016lx ",reg.r9);
    if(reg.r10!=regprevious.r10)
        printf("\033[34mr10=0x%016lx\033[m ",reg.r10);
    else
        printf("r10=0x%016lx ",reg.r10);
    if(reg.r11!=regprevious.r11)
        printf("\033[34mr11=0x%016lx\033[m ",reg.r11);
    else
        printf("r11=0x%016lx ",reg.r11);
    printf("\n");
    if(reg.r12!=regprevious.r12)
        printf("\033[34mr12=0x%016lx\033[m ",reg.r12);
    else
        printf("r12=0x%016lx ",reg.r12);
    if(reg.r13!=regprevious.r13)
        printf("\033[34mr13=0x%016lx\033[m ",reg.r13);
    else
        printf("r13=0x%016lx ",reg.r13);
    if(reg.r14!=regprevious.r14)
        printf("\033[34mr14=0x%016lx\033[m ",reg.r14);
    else
        printf("r14=0x%016lx ",reg.r14);
    if(reg.r15!=regprevious.r15)
        printf("\033[34mr15=0x%016lx\033[m ",reg.r15);
    else
        printf("r15=0x%016lx ",reg.r15);
    printf("\n");
    if(reg.rsi!=regprevious.rsi)
        printf("\033[34mrsi=0x%016lx\033[m ",reg.rsi);
    else
        printf("rsi=0x%016lx ",reg.rsi);
    if(reg.rdi!=regprevious.rdi)
        printf("\033[34mrdi=0x%016lx\033[m ",reg.rdi);
    else
        printf("rdi=0x%016lx ",reg.rdi);
    printf("\nflags: ");
    if(reg.flags.CF==1)
        printf("\033[34mCF=%d\033[m ",reg.flags.CF);
    else
        printf("CF=%d ",reg.flags.CF);
    if(reg.flags.AF==1)
        printf("\033[34mAF=%d\033[m ",reg.flags.AF);
    else
        printf("AF=%d ",reg.flags.AF);
    if(reg.flags.ZF==1)
        printf("\033[34mZF=%d\033[m ",reg.flags.ZF);
    else
        printf("ZF=%d ",reg.flags.ZF);
    if(reg.flags.SF==1)
        printf("\033[34mSF=%d\033[m ",reg.flags.SF);
    else
        printf("SF=%d ",reg.flags.SF);
    printf("\n");
    regprevious=reg;
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
            {"load",required_argument, nullptr,'l'},
            {0, 0, 0, 0}
    };
    static const char simple_options[]="g:hc:l:";
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
            case 'l':
                LoadCode(optarg);
                break;
            case 'h':
            default:
                ShowHelpInfo();
                exit(0);
                break;
        }
    }
}

void Process::FillCmdFromFile(std::string& buff)       // Unfinished
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

void Process::LoadCode(std::string filename)
{
    ifstream in(filename,ios::in);
    if(!in.is_open())
        throw FileCannotOpen();
    stringstream buffer;
    buffer << in.rdbuf();
    Translate trans(buffer.str());
    trans.CopyCode((char*)code_seg+code_offset);
    in.close();
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