//
// Created by gurth on 9/16/20.
//

#include <iostream>
#include <fstream>
#include <string>
#include "error.h"
#include "process.h"
#include "register.h"

using namespace std;

Process::Process()
{
    this_info=default_info;
    init();
}

Process::Process(system_info sysinfo)
{
    this_info=sysinfo;
    init();
}

Process::~Process()
{
    uninit();
    ofstream out("./.cache/history",ios::out);
    if(!out.is_open())
        throw FileCannotOpen();
    for(int i=0;i<len_history;i++)
        out <<history[i]<<endl;
    out.close();
}

void Process::CmdParsing(std::string cmd)
{
    history.push_back(cmd);
    len_history++;
    try
    {
        Translate trans(cmd);
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
    }
}

void Process::ShowRegisterStatus()
{
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