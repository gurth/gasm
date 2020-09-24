//
// Created by gurth on 9/16/20.
//

#include "register.h"

Register reg;
Register bak;

void __attribute__((naked)) fresh()
{
    __asm__ __volatile__(
    "push %rax\n"\
            "push %rsi\n"\
            "push %rdi\n"\
            "push %rbx\n"\
            "push %rcx\n"\
            "push %rdx\n"\
            "push %r8\n"\
            "push %r9\n"\
            "push %r10\n"\
            "push %r11\n"\
            "push %r12\n"\
            "push %r13\n"\
            "push %r14\n"\
            "push %r15\n"\
            "pushf"
    );
    __asm__ __volatile__(
            "pop %0"\
            :"=rdi"((size64)reg.rfr)
            :
            :
    );
    __asm__ __volatile__(
            "pop %0"\
            :"=r"((size64)reg.r15)
            :
            :
    );
    __asm__ __volatile__(
            "pop %0"\
            :"=r"((size64)reg.r14)
            :
            :
    );
    __asm__ __volatile__(
            "pop %0"\
            :"=r"((size64)reg.r13)
            :
            :
    );
    __asm__ __volatile__(
            "pop %0"\
            :"=r"((size64)reg.r12)
            :
            :
    );
    __asm__ __volatile__(
            "pop %0"\
            :"=r"((size64)reg.r11)
            :
            :
    );
    __asm__ __volatile__(
            "pop %0"\
            :"=r"((size64)reg.r10)
            :
            :
    );
    __asm__ __volatile__(
            "pop %0"\
            :"=r"((size64)reg.r9)
            :
            :
    );
    __asm__ __volatile__(
            "pop %0"\
            :"=r"((size64)reg.r8)
            :
            :
    );

    __asm__ __volatile__(
            "pop %0"\
            :"=rdx"((size64)reg.rdx)
            :
            :
    );
    __asm__ __volatile__(
            "pop %0"\
            :"=rcx"((size64)reg.rcx)
            :
            :
    );
    __asm__ __volatile__(
            "pop %0"\
            :"=rbx"((size64)reg.rbx)
            :
            :
    );
    __asm__ __volatile__(
            "pop %0"
            :"=rdi"((size64)reg.rdi)
            :
            :
    );
    __asm__ __volatile__(
            "pop %0"
            :"=rsi"((size64)reg.rsi)
            :
            :
    );
    __asm__ __volatile__(
            "pop %0"
            :"=rax"((size64)reg.rax)
            :
            :
    );
    __asm__ __volatile__("call ParsingFR");
    __asm__ __volatile__("ret");
}

void __attribute__((naked)) restore()
{
    __asm__ __volatile__(
        "mov %0,%%rbx"
        :
        :"rax"((size64)reg.rbx)
        :
    );
    __asm__ __volatile__(
        "mov %0,%%rcx"
        :
        :"rax"((size64)reg.rcx)
        :
    );
    __asm__ __volatile__(
        "mov %0,%%rdx"
        :
        :"rax"((size64)reg.rdx)
        :
    );
    __asm__ __volatile__(
        "mov %0,%%r8"
        :
        :"r"((size64)reg.r8)
        :
    );
    __asm__ __volatile__(
        "mov %0,%%r9"
        :
        :"r"((size64)reg.r9)
    :
    );
    __asm__ __volatile__(
        "mov %0,%%r10"
        :
        :"r"((size64)reg.r10)
        :
    );
    __asm__ __volatile__(
        "mov %0,%%r11"
        :
        :"r"((size64)reg.r11)
        :
    );
    __asm__ __volatile__(
        "mov %0,%%r12"
        :
        :"r"((size64)reg.r12)
        :
    );
    __asm__ __volatile__(
        "mov %0,%%r13"
        :
        :"r"((size64)reg.r13)
        :
    );
    __asm__ __volatile__(
        "mov %0,%%r14"
        :
        :"r"((size64)reg.r14)
        :
    );
    __asm__ __volatile__(
        "mov %0,%%r15"
        :
        :"r"((size64)reg.r15)
        :
    );
    __asm__ __volatile__(
        "mov %0,%%rax\n"\
        "mov %%rax,%%rdi"
        :
        :"rdi"((size64)reg.rdi)
        :
    );
    __asm__ __volatile__(
        "mov %0,%%rax\n"\
        "mov %%rax,%%rsi"
        :
        :"rdi"((size64)reg.rsi)
        :
    );
    __asm__ __volatile__(
        "push %0\n"\
        "popf"
        :
        :"rfr"((size64)reg.rfr)
        :
    );
    __asm__ __volatile__(
        "push %0"
        :
        :"rax"((size64)reg.rax)
        :
    );
    __asm__ __volatile__(
            "pop %rax\n"\
            "ret"
            );
}

void __attribute__((naked)) regbak()
{
    __asm__ __volatile__(
            "push %rax\n"\
            "push %rsi\n"\
            "push %rdi\n"\
            "push %rbx\n"\
            "push %rcx\n"\
            "push %rdx\n"\
            "push %r8\n"\
            "push %r9\n"\
            "push %r10\n"\
            "push %r11\n"\
            "push %r12\n"\
            "push %r13\n"\
            "push %r14\n"\
            "push %r15\n"\
            "pushf"
    );
    __asm__ __volatile__(
            "pop %0"\
            :"=rdi"((size64)bak.rfr)
            :
            :
    );
    __asm__ __volatile__(
            "pop %0"\
            :"=r"((size64)bak.r15)
            :
            :
    );
    __asm__ __volatile__(
            "pop %0"\
            :"=r"((size64)bak.r14)
            :
            :
    );
    __asm__ __volatile__(
            "pop %0"\
            :"=r"((size64)bak.r13)
            :
            :
    );
    __asm__ __volatile__(
            "pop %0"\
            :"=r"((size64)bak.r12)
            :
            :
    );
    __asm__ __volatile__(
            "pop %0"\
            :"=r"((size64)bak.r11)
            :
            :
    );
    __asm__ __volatile__(
            "pop %0"\
            :"=r"((size64)bak.r10)
            :
            :
    );
    __asm__ __volatile__(
            "pop %0"\
            :"=r"((size64)bak.r9)
            :
            :
    );
    __asm__ __volatile__(
            "pop %0"\
            :"=r"((size64)bak.r8)
            :
            :
    );

    __asm__ __volatile__(
            "pop %0"\
            :"=rdx"((size64)bak.rdx)
            :
            :
    );
    __asm__ __volatile__(
            "pop %0"\
            :"=rcx"((size64)bak.rcx)
            :
            :
    );
    __asm__ __volatile__(
            "pop %0"\
            :"=rbx"((size64)bak.rbx)
            :
            :
    );
    __asm__ __volatile__(
            "pop %0"
            :"=rdi"((size64)bak.rdi)
            :
            :
    );
    __asm__ __volatile__(
            "pop %0"
            :"=rsi"((size64)bak.rsi)
            :
            :
    );
    __asm__ __volatile__(
            "pop %0"
            :"=rax"((size64)bak.rax)
            :
            :
    );
    __asm__ __volatile__("call ParsingFR");
    __asm__ __volatile__("ret");
}

void __attribute__((naked)) regdisbak()
{
    __asm__ __volatile__(
            "mov %0,%%rbx"
            :
            :"rbx"((size64)bak.rbx)
            :
    );
    __asm__ __volatile__(
            "mov %0,%%rcx"
            :
            :"rcx"((size64)bak.rcx)
            :
    );
    __asm__ __volatile__(
            "mov %0,%%rdx"
            :
            :"rdx"((size64)bak.rdx)
            :
    );
    __asm__ __volatile__(
            "mov %0,%%r8"
            :
            :"r"((size64)bak.r8)
            :
    );
    __asm__ __volatile__(
            "mov %0,%%r9"
            :
            :"r"((size64)bak.r9)
            :
    );
    __asm__ __volatile__(
            "mov %0,%%r10"
            :
            :"r"((size64)bak.r10)
            :
    );
    __asm__ __volatile__(
            "mov %0,%%r11"
            :
            :"r"((size64)bak.r11)
            :
    );
    __asm__ __volatile__(
            "mov %0,%%r12"
            :
            :"r"((size64)bak.r12)
            :
    );
    __asm__ __volatile__(
            "mov %0,%%r13"
            :
            :"r"((size64)bak.r13)
            :
    );
    __asm__ __volatile__(
            "mov %0,%%r14"
            :
            :"r"((size64)bak.r14)
            :
    );
    __asm__ __volatile__(
            "mov %0,%%r15"
            :
            :"r"((size64)bak.r15)
            :
    );
    __asm__ __volatile__(
            "mov %0,%%rax\n"\
            "mov %%rax,%%rdi"
            :
            :"rdi"((size64)bak.rdi)
            :
    );
    __asm__ __volatile__(
            "mov %0,%%rax\n"\
            "mov %%rax,%%rsi"
            :
            :"rdi"((size64)bak.rsi)
            :
    );
    __asm__ __volatile__(
            "push %0\n"\
            "popf"
            :
            :"rfr"((size64)bak.rfr)
            :
    );
    __asm__ __volatile__(
            "push %0"
            :
            :"rax"((size64)bak.rax)
            :
    );
    __asm__ __volatile__(
            "pop %rax\n"\
            "ret"
    );
}


void ParsingFR()
{
    unsigned short fr=(unsigned short)reg.rfr & 0x000000000000ffff;
    if(fr & POS_CF)
        reg.flags.CF=1;
    else reg.flags.CF=0;
    if(fr & POS_PF)
        reg.flags.PF=1;
    else reg.flags.PF=0;
    if(fr & POS_AF)
        reg.flags.AF=1;
    else reg.flags.AF=0;
    if(fr & POS_ZF)
        reg.flags.ZF=1;
    else reg.flags.ZF=0;
    if(fr & POS_SF)
        reg.flags.SF=1;
    else reg.flags.SF=0;
    if(fr & POS_TF)
        reg.flags.TF=1;
    else reg.flags.TF=0;
    if(fr & POS_IF)
        reg.flags.IF=1;
    else reg.flags.IF=0;
    if(fr & POS_DF)
        reg.flags.DF=1;
    else reg.flags.DF=0;
    if(fr & POS_OF)
        reg.flags.OF=1;
    else reg.flags.OF=0;
    return;
}
