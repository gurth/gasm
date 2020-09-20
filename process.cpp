//
// Created by gurth on 9/16/20.
//

#include <iostream>
#include <string>
#include "process.h"
#include "register.h"

extern size64 rax;
extern size64 rbx;
extern size64 rcx;
extern size64 rdx;
extern size64 r8;
extern size64 r9;
extern size64 r10;
extern size64 r11;
extern size64 r12;
extern size64 r13;
extern size64 r14;
extern size64 r15;
extern size64 rip;
extern size64 rfp;

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

void Process::ShowRegisterStatus()
{
    printf("rax=0x%016x rbx=0x%016x rcx=0x%016x rdx=0x%016x\n",rax,rbx,rcx,rdx);
    printf("r8=0x%016x r9=0x%016x r10=0x%016x r11=0x%016x\n",r8,r9,r10,r11);
    printf("r12=0x%016x r13=0x%016x r14=0x%016x r15=0x%016x\n",r12,r13,r14,r15);
}