//
// Created by gurth on 9/16/20.
//

#include "register.h"

FR flags;

size64 rax=0;
size64 rbx=0;
size64 rcx=0;
size64 rdx=0;
size64 r8=0;
size64 r9=0;
size64 r10=0;
size64 r11=0;
size64 r12=0;
size64 r13=0;
size64 r14=0;
size64 r15=0;

size64 rsi=0;
size64 rdi=0;

size64 rfr=0;


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
            :"=rdi"((size64)rfr)
            :"rdi"((size64)rfr)
            :
            );
    __asm__ __volatile__(
            "pop %0"
            :"=rdi"((size64)rdi)
            :"rdi"((size64)rdi)
            :
    );
    __asm__ __volatile__(
            "pop %0"
            :"=rsi"((size64)rsi)
            :"rsi"((size64)rsi)
            :
    );
    __asm__ __volatile__(
            "pop %0"
            :"=rax"((size64)rax)
            :"rax"((size64)rax)
            :
    );
    __asm__ __volatile__(
            "call Getrbx\n"\
            "mov %%rax,%0"
            :"=rbx"((size64)rbx)
            :"rbx"((size64)rbx)
            :
    );
    __asm__ __volatile__(
            "call Getrcx\n"\
            "mov %%rax,%0"
            :"=rcx"((size64)rcx)
            :"rcx"((size64)rcx)
            :
    );
    __asm__ __volatile__(
            "call Getrdx\n"\
            "mov %%rax,%0"
            :"=rdx"((size64)rdx)
            :"rdx"((size64)rdx)
            :
    );
    __asm__ __volatile__(
            "call Getr8\n"\
            "mov %%rax,%0"
            :"=r"((size64)r8)
            :"r"((size64)r8)
            :
    );
    __asm__ __volatile__(
            "call Getr9\n"\
            "mov %%rax,%0"
            :"=r"((size64)r9)
            :"r"((size64)r9)
            :
    );
    __asm__ __volatile__(
            "call Getr10\n"\
            "mov %%rax,%0"
            :"=r"((size64)r10)
            :"r"((size64)r10)
            :
    );
    __asm__ __volatile__(
            "call Getr11\n"\
            "mov %%rax,%0"
            :"=r"((size64)r11)
            :"r"((size64)r11)
            :
    );
    __asm__ __volatile__(
            "call Getr12\n"\
            "mov %%rax,%0"
            :"=r"((size64)r12)
            :"r"((size64)r12)
            :
    );
    __asm__ __volatile__(
            "call Getr13\n"\
            "mov %%rax,%0"
            :"=r"((size64)r13)
            :"r"((size64)r13)
            :
    );
    __asm__ __volatile__(
            "call Getr14\n"\
            "mov %%rax,%0"
            :"=r"((size64)r14)
            :"r"((size64)r14)
            :
    );
    __asm__ __volatile__(
            "call Getr15\n"\
            "mov %%rax,%0"
            :"=r"((size64)r15)
            :"r"((size64)r15)
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
    short fr=rfr & 0x000000000000ffff;
    if(fr & POS_CF)
        flags.CF=1;
    else flags.CF=0;
    if(fr & POS_PF)
        flags.PF=1;
    else flags.PF=0;
    if(fr & POS_AF)
        flags.AF=1;
    else flags.AF=0;
    if(fr & POS_ZF)
        flags.ZF=1;
    else flags.ZF=0;
    if(fr & POS_SF)
        flags.SF=1;
    else flags.SF=0;
    if(fr & POS_TF)
        flags.TF=1;
    else flags.TF=0;
    if(fr & POS_IF)
        flags.IF=1;
    else flags.IF=0;
    if(fr & POS_DF)
        flags.DF=1;
    else flags.DF=0;
    if(fr & POS_OF)
        flags.OF=1;
    else flags.OF=0;
    return;
}
