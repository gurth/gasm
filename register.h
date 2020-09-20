//
// Created by gurth on 9/16/20.
//

#ifndef GASM_REGISTER_H
#define GASM_REGISTER_H

typedef unsigned long long size64;
typedef short BOOL;

#define TRUE 1
#define FALSE 0
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
