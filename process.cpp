//
// Created by gurth on 9/16/20.
//

#include <iostream>
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
}

void Process::CmdParsing(std::string cmd)
{
    try
    {
        Translate trans(cmd);
        trans.CopyCode((char*)exe_cmd);
        __asm__ __volatile__("call regbak");
        restore_rax();
        __asm__ __volatile__("call restore");
        ex();
        __asm__ __volatile__("call fresh");
        __asm__ __volatile__("call regdisbak");
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

void Process::restore_rax()
{
    size64 *p=(size64*)((char*)exe_buff+offset_rax);
    *p=reg.rax;
}

void Process::ShowRegisterStatus()
{
    printf("rax=0x%016x rbx=0x%016x rcx=0x%016x rdx=0x%016x\n",reg.rax,reg.rbx,reg.rcx,reg.rdx);
    printf("r8 =0x%016x r9 =0x%016x r10=0x%016x r11=0x%016x\n",reg.r8,reg.r9,reg.r10,reg.r11);
    printf("r12=0x%016x r13=0x%016x r14=0x%016x r15=0x%016x\n",reg.r12,reg.r13,reg.r14,reg.r15);
    printf("rsi=0x%016x rdi=0x%016x\n",reg.rsi,reg.rdi);
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