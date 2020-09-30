//
// Created by gurth on 9/16/20.
// Use inline assembly to realize some nake function to get and save register
// status, or prepare the execution of command.
//

#ifndef GASM_REGISTER_H
#define GASM_REGISTER_H

typedef unsigned long long size64;
typedef short BOOL;
typedef unsigned char BYTE;

#define TRUE 1
#define FALSE 0

// This define the position of flags
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

struct FR    // flag status
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

struct Register // register status
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

typedef struct Register Register;

extern Register reg;
extern size64 ptrtable[];

void fresh();                // Get reg status
void restore();              // Restore reg status (outside)

void regbak();               // Back reg status
void regdisbak();            // Restore reg status (inside)

void prefixcode();           // Execution prefix code
void suffixcode();           // Execution suffix code
void tag();                  // Function pointer tag, for getting function length

void ParsingFR();            // From flags register to flags' status

#endif //GASM_REGISTER_H
