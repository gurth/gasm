//
// Created by gurth on 10/8/20.
// It is NOT recommended to modify this file.
//

#include "register.h"

void __attribute__((naked)) prefixcode()
{
    __asm__ __volatile__(
            "mov %rsp,%rax\n"\
            "mov %rax,0xaaaaaaaaaaaaaaaa\n"\
            "mov 0xaaaaaaaaaaaaaaaa,%rax\n"\
            "mov %rax,%rsp\n"\
            "mov 0xaaaaaaaaaaaaaaaa,%rax"
    );
}

void __attribute__((naked)) suffixcode()
{
    __asm__ __volatile__(
            "mov %rax,0xaaaaaaaaaaaaaaaa\n"\
            "mov %rsp,%rax\n"\
            "mov %rax,0xaaaaaaaaaaaaaaaa\n"\
            "mov 0xaaaaaaaaaaaaaaaa,%rax\n"\
            "mov %rax,%rsp\n"\
            "ret"
    );
}

void __attribute__((naked)) tag(){}

