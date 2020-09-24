//
// Created by gurth on 9/16/20.
//

#ifndef STRUCT_SYSTEM_INFO
#define STRUCT_SYSTEM_INFO

struct offset_info
{
    short pre_rsp_save=0x05;
    short pre_rsp=0x0f;
    short pre_rax=0x1c;

    short suf_rax=0x02;
    short suf_rsp=0x0f;
    short suf_rsp_save=0x19;
};

typedef struct offset_info offset_info;

struct system_info
{
    unsigned long long mem;
    unsigned long long stack;
    unsigned long long data;
    short exe_buff;
    short prefix;
    short suffix;
    offset_info offset;
};

typedef struct system_info system_info;

#endif //STRUCT_SYSTEM_INFO

#ifndef GASM_PROCESS_H
#define GASM_PROCESS_H

#include "translate.h"

typedef __attribute__((naked)) void(*EX)(void);

class Process
{
private:
    void* exe_buff= nullptr;
    void* exe_cmd= nullptr;
    void* vmem= nullptr;
    void* data_seg= nullptr;
    void* stack_seg= nullptr;
    EX ex;
    system_info this_info;
    constexpr static const system_info default_info={0x2000000, 0x2000,0x40000};
    char* prefix= nullptr;
    char* suffix= nullptr;
private:
    bool init();
    bool uninit();
public:
    Process();
    Process(system_info sysinfo);
    ~Process();
    void CmdParsing(std::string cmd);
    void ShowRegisterStatus();
    void ShowVirtualMemoryStruct();
};


#endif //GASM_PROCESS_H
