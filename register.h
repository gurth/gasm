//
// Created by gurth on 9/16/20.
//

#ifndef GASM_REGISTER_H
#define GASM_REGISTER_H

typedef unsigned long long size64;
typedef short BOOL;

#define TRUE 1
#define FALSE 0

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


    BOOL fresh();

    size64 Getrax();
    size64 Getrbx();
    size64 Getrcx();
    size64 Getrdx();
    size64 Getr8();
    size64 Getr9();
    size64 Getr10();
    size64 Getr11();
    size64 Getr12();
    size64 Getr13();
    size64 Getr14();
    size64 Getr15();
    size64 Getrip();
    size64 Getrfp();

#endif //GASM_REGISTER_H
