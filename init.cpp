//
// Created by gurth on 4/17/20.
//
#include "error.h"
#include "process.h"
#include <sys/mman.h>
#include <iostream>

bool Process::init()
{
    vmem=mmap(nullptr,this_info.mem,
            PROT_EXEC | PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS,-1,0);
    exe_buff=mmap(nullptr,this_info.exe_buff,
              PROT_EXEC | PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS,-1,0);
    if(!(vmem || exe_buff))
        return false;
    data_seg=vmem;
    stack_seg=(void*)((char*)vmem+this_info.data+this_info.stack);
    ex=(EX)exe_buff;
    return true;
}

bool Process::uninit()
{
    if(exe_buff)
        munmap(exe_buff,this_info.exe_buff);
    if(vmem)
        munmap(vmem, this_info.mem);
    return true;
}