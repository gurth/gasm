//
// Created by gurth on 4/17/20.
//
#include "error.h"

extern "C"
{
    #include "register.h"
}

#include "process.h"
#include <sys/mman.h>
#include <cstring>

bool Process::init()
{
    system("mkdir -p ./.gasm");
    regprevious=reg;

    vmem=mmap(nullptr,this_info.mem,
            PROT_EXEC | PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS,-1,0);

    if(!(vmem || exe_buff))
        return false;
    data_seg=vmem;
    stack_seg=(void*)((char*)vmem+this_info.data+this_info.stack);

    this_info.prefix=(unsigned char*)suffixcode-(unsigned char*)prefixcode-7;
    this_info.suffix=(unsigned char*)tag-(unsigned char*)suffixcode-7;

    this_info.exe_buff=MACHIEE_CODE_LENGTH+this_info.prefix+this_info.suffix;

    Translate::max_length=MACHIEE_CODE_LENGTH+this_info.suffix;

    exe_buff=mmap(nullptr,this_info.exe_buff,
                  PROT_EXEC | PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS,-1,0);

    prefix=(char*)malloc(this_info.prefix*sizeof(char));
    suffix=(char*)malloc(this_info.suffix*sizeof(char));

    memcpy(prefix,((char*)prefixcode)+4,this_info.prefix);

    memcpy(suffix,((char*)suffixcode)+4,this_info.suffix);

    size64* pfix= nullptr;
    pfix=(size64*)(prefix+this_info.offset.pre_rax);
    *pfix=(size64)(&(ptrtable[0]));
    pfix=(size64*)(prefix+this_info.offset.pre_rsp);
    *pfix=(size64)(&(ptrtable[1]));
    pfix=(size64*)(prefix+this_info.offset.pre_rsp_save);
    *pfix=(size64)(&(ptrtable[2]));
    pfix=(size64*)(suffix+this_info.offset.suf_rax);
    *pfix=(size64)(&(ptrtable[0]));
    pfix=(size64*)(suffix+this_info.offset.suf_rsp);
    *pfix=(size64)(&(ptrtable[1]));
    pfix=(size64*)(suffix+this_info.offset.suf_rsp_save);
    *pfix=(size64)(&(ptrtable[2]));

    ptrtable[0]=0;
    ptrtable[1]=(size64)stack_seg;

    memcpy(exe_buff,prefix,this_info.prefix);
    exe_cmd=(void*)((char*)exe_buff+this_info.prefix);
    ex=(EX)exe_buff;
    return true;
}

bool Process::uninit()
{
    if(exe_buff)
        munmap(exe_buff,this_info.exe_buff);
    if(vmem)
        munmap(vmem, this_info.mem);
    if(prefix)
        free(prefix);
    if(suffix)
        free(suffix);
    return true;
}