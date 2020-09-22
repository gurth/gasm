//
// Created by gurth on 9/16/20.
//

#include "register.h"

Register reg;


BOOL __attribute__((naked)) fresh()
{
    __asm__ __volatile__(
            "push %rax\n"\
            "push %rsi\n"\
            "push %rdi\n"\
            "pushf"
            );
    __asm__ __volatile__(
            "pop %0"\
            :"=rdi"((size64)reg.rfr)
            :"rdi"((size64)reg.rfr)
            :
            );
    __asm__ __volatile__(
            "pop %0"
            :"=rdi"((size64)reg.rdi)
            :"rdi"((size64)reg.rdi)
            :
    );
    __asm__ __volatile__(
            "pop %0"
            :"=rsi"((size64)reg.rsi)
            :"rsi"((size64)reg.rsi)
            :
    );
    __asm__ __volatile__(
            "pop %0"
            :"=rax"((size64)reg.rax)
            :"rax"((size64)reg.rax)
            :
    );
    __asm__ __volatile__(
            "call Getrbx\n"\
            "mov %%rax,%0"
            :"=rbx"((size64)reg.rbx)
            :"rbx"((size64)reg.rbx)
            :
    );
    __asm__ __volatile__(
            "call Getrcx\n"\
            "mov %%rax,%0"
            :"=rcx"((size64)reg.rcx)
            :"rcx"((size64)reg.rcx)
            :
    );
    __asm__ __volatile__(
            "call Getrdx\n"\
            "mov %%rax,%0"
            :"=rdx"((size64)reg.rdx)
            :"rdx"((size64)reg.rdx)
            :
    );
    __asm__ __volatile__(
            "call Getr8\n"\
            "mov %%rax,%0"
            :"=r"((size64)reg.r8)
            :"r"((size64)reg.r8)
            :
    );
    __asm__ __volatile__(
            "call Getr9\n"\
            "mov %%rax,%0"
            :"=r"((size64)reg.r9)
            :"r"((size64)reg.r9)
            :
    );
    __asm__ __volatile__(
            "call Getr10\n"\
            "mov %%rax,%0"
            :"=r"((size64)reg.r10)
            :"r"((size64)reg.r10)
            :
    );
    __asm__ __volatile__(
            "call Getr11\n"\
            "mov %%rax,%0"
            :"=r"((size64)reg.r11)
            :"r"((size64)reg.r11)
            :
    );
    __asm__ __volatile__(
            "call Getr12\n"\
            "mov %%rax,%0"
            :"=r"((size64)reg.r12)
            :"r"((size64)reg.r12)
            :
    );
    __asm__ __volatile__(
            "call Getr13\n"\
            "mov %%rax,%0"
            :"=r"((size64)reg.r13)
            :"r"((size64)reg.r13)
            :
    );
    __asm__ __volatile__(
            "call Getr14\n"\
            "mov %%rax,%0"
            :"=r"((size64)reg.r14)
            :"r"((size64)reg.r14)
            :
    );
    __asm__ __volatile__(
            "call Getr15\n"\
            "mov %%rax,%0"
            :"=r"((size64)reg.r15)
            :"r"((size64)reg.r15)
            :
    );
    __asm__ __volatile__("call ParsingFR");
    __asm__ __volatile__(
            "mov $1, %rax\n"\
            "ret");
}

size64 __attribute__((naked)) Getrax()
{
    __asm__ __volatile__("ret");
}

size64 __attribute__((naked)) Getrbx()
{
    __asm__ __volatile__(
            "mov %rbx,%rax"\
            "\nret"
            );
}

size64 __attribute__((naked)) Getrcx()
{
    __asm__ __volatile__(
            "mov %rcx,%rax"\
            "\nret"
    );
}

size64 __attribute__((naked)) Getrdx()
{
    __asm__ __volatile__(
            "mov %rdx,%rax"\
            "\nret"
    );
}

size64 __attribute__((naked)) Getr8()
{
    __asm__ __volatile__(
            "mov %r8,%rax"\
            "\nret"
    );
}

size64 __attribute__((naked)) Getr9()
{
    __asm__ __volatile__(
            "mov %r9,%rax"\
            "\nret"
    );
}

size64 __attribute__((naked)) Getr10()
{
    __asm__ __volatile__(
            "mov %r10,%rax"\
            "\nret"
    );
}

size64 __attribute__((naked)) Getr11()
{
    __asm__ __volatile__(
            "mov %r11,%rax"\
            "\nret"
    );
}

size64 __attribute__((naked)) Getr12()
{
    __asm__ __volatile__(
            "mov %r12,%rax"\
            "\nret"
    );
}

size64 __attribute__((naked)) Getr13()
{
    __asm__ __volatile__(
            "mov %r13,%rax"\
            "\nret"
    );
}

size64 __attribute__((naked)) Getr14()
{
    __asm__ __volatile__(
            "mov %r14,%rax"\
            "\nret"
    );
}

size64 __attribute__((naked)) Getr15()
{
    __asm__ __volatile__(
            "mov %r15,%rax"\
            "\nret"
    );
}

void ParsingFR()
{
    short fr=reg.rfr & 0x000000000000ffff;
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
