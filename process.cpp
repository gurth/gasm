//
// Created by gurth on 9/16/20.
//

#include <iostream>
#include <string>
#include "process.h"


Process::Process()
{
    this_info=default_info;
}

Process::Process(system_info sysinfo)
{
    this_info=sysinfo;
}

Process::~Process()
{

}