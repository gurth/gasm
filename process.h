//
// Created by gurth on 9/16/20.
//

#ifndef STRUCT_SYSTEM_INFO
#define STRUCT_SYSTEM_INFO

struct system_info
{
    unsigned long long mem;
};

typedef struct system_info system_info;

#endif //STRUCT_SYSTEM_INFO

#ifndef GASM_PROCESS_H
#define GASM_PROCESS_H

class Process
{
private:
    constexpr static const system_info default_info={0x2000000};
    system_info this_info;
    bool init();
    bool uninit();
public:
    Process();
    Process(system_info sysinfo);
    ~Process();

};


#endif //GASM_PROCESS_H
