//
// Created by gurth on 9/16/20.
//

#include "register.h"


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
size64 rip=0;
size64 rfp=0;


BOOL __attribute__((naked)) fresh()
{
    __asm__ __volatile__(
            "mov %%rax,%0\n"
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
    __asm__ __volatile__(
            "call Getrip\n"\
            "mov %%rax,%0"
            :"=rip"((size64)rip)
            :"rip"((size64)rip)
            :
    );
    __asm__ __volatile__(
            "call Getrfp\n"\
            "mov %%rax,%0"
            :"=rfp"((size64)rfp)
            :"rfp"((size64)rfp)
            :
    );
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

size64 __attribute__((naked)) Getrip()
{
    __asm__ __volatile__(
            //"mov %rip,%rax"
            "\nret"
    );
}

size64 __attribute__((naked)) Getrfp()
{
    __asm__ __volatile__(
            //"mov %rfp,%rax"
            "\nret"
    );
}
