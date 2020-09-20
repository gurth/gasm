//
// Created by gurth on 9/16/20.
//

#ifndef GASM_REGISTER_H
#define GASM_REGISTER_H

typedef unsigned long long size64;
typedef short BOOL;
typedef unsigned char BYTE;

#define TRUE 1
#define FALSE 0

#define POS_CF 0b0000000000000001
#define POS_PF 0b0000000000000100
#define POS_AF 0b0000000000010000
#define POS_ZF 0b0000000001000000
#define POS_SF 0b0000000010000000
#define POS_TF 0b0000000100000000
#define POS_IF 0b0000001000000000
#define POS_DF 0b0000010000000000
#define POS_OF 0b0000100000000000

struct FR
{
    BYTE CF;
    BYTE PF;
    BYTE AF;
    BYTE ZF;
    BYTE SF;
    BYTE TF;
    BYTE IF;
    BYTE DF;
    BYTE OF;
};

typedef struct FR FR;

extern FR flags;

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

extern size64 rsi;
extern size64 rdi;
extern size64 rfr;


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

void ParsingFR();

#endif //GASM_REGISTER_H
