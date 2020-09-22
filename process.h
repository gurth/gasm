//
// Created by gurth on 9/16/20.
//

#ifndef STRUCT_SYSTEM_INFO
#define STRUCT_SYSTEM_INFO

#include "translate.h"

struct system_info
{
    unsigned long long mem;
    unsigned long long stack;
    unsigned long long data;
    short exe_buff;
};

typedef struct system_info system_info;

#endif //STRUCT_SYSTEM_INFO

#ifndef GASM_PROCESS_H
#define GASM_PROCESS_H

typedef void(*EX)(void);

class Process
{
private:
    void* exe_buff= nullptr;
    void* vmem= nullptr;
    void* data_seg= nullptr;
    void* stack_seg= nullptr;
    EX ex;
    system_info this_info;
private:
    constexpr static const system_info default_info={0x2000000, 0x2000,0x40000,16};
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
