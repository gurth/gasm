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

#define PTR_TABLE 0x10

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

struct Register
{
    FR flags;

    size64 rax;
    size64 rbx;
    size64 rcx;
    size64 rdx;
    size64 r8;
    size64 r9;
    size64 r10;
    size64 r11;
    size64 r12;
    size64 r13;
    size64 r14;
    size64 r15;

    size64 rsi;
    size64 rdi;

    size64 rfr;
};

struct SegPtr{
    size64 sp;
    size64 bp;
};

typedef struct Register Register;

extern Register reg;
extern size64 ptrtable[];

void fresh();
void restore();

void regbak();
void regdisbak();

void prefixcode();
void suffixcode();
void tag();

void ParsingFR();

#endif //GASM_REGISTER_H
