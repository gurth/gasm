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
    buff=mmap(nullptr,this_info.buffer,
              PROT_EXEC | PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS,-1,0);
    if(!(vmem || buff))
        return false;
    return true;
}

bool Process::uninit()
{
    if(buff)
        munmap(buff,this_info.buffer);
    if(vmem)
        munmap(vmem, this_info.mem);
    return true;
}