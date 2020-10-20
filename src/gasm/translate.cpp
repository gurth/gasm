//
// Created by gurth on 9/16/20.
//
#include "translate.h"
#ifdef OUTSIDE_PARSING
#include <fstream>
#include <cstdio>
#endif //OUTSIDE_PARSING
#include <cstring>
#include "error.h"
#include <asmtk/asmtk.h>

using namespace std;
using namespace asmjit;
using namespace asmtk;

Translate::Translate()
{
    machine_code=(char*)malloc(sizeof(char)*max_length);
}

Translate::Translate(std::string cmd)
{
    machine_code=(char*)malloc(sizeof(char)*max_length);
    this->raw_cmd=cmd;
    Parsing();
}

Translate::~Translate()
{
    if(machine_code)
        free(machine_code);
}

void Translate::CopyCode(char* exe_buff)
{
    memcpy(exe_buff,machine_code,length);
}

void Translate::AttchSuffix(char *suffix, short suf_len, short exe_buff)
{
    memcpy(machine_code+length,suffix,suf_len);
    length+=suf_len;
    if(length > exe_buff)
        throw ExeBufferOverflow();
}

void Translate::ShowMachineCode()
{
    for(size_t i=0;i<length;i++)
        printf("%02x ",(unsigned char)machine_code[i]);
    printf("\n");
}

void Translate::Parsing()
{
#ifdef INSIDE_PARSING
    CodeInfo ci(asmjit::Environment::kArchX64);
    CodeHolder code;
    code.init(ci);
    x86::Assembler a(&code);
    AsmParser p(&a);
    Error err = p.parse(raw_cmd.c_str());
    if (err)
    {
        printf("ERROR: %08x (%s)\n", err, DebugUtils::errorAsString(err));
        throw ErrorCommand();
    }
    CodeBuffer& buffer = code.sectionById(0)->buffer();
    const uint8_t* buf=buffer.data();
    length=buffer.size();
    memcpy(machine_code,buffer.data(),length);
    ShowMachineCode();
#endif //INSIDE_PARSING
#ifdef OUTSIDE_PARSING
    FILE* ftmp=fopen("./.cache/gasm/tmp.asm","w");
    char elfbuff[0x00000200];
    if(!ftmp)
        throw FileCannotOpen();
    fputs(raw_cmd.c_str(),ftmp);
    fclose(ftmp);
    int sysresult = system("nasm -f elf64 ./.cache/gasm/tmp.asm -o ./.cache/gasm/tmp.o");
    if(sysresult)
        throw ErrorCommand();
    char*p=machine_code;
    ifstream elf64("./.cache/gasm/tmp.o",ios::in | ios::binary);
    if(!elf64.is_open())
        throw FileCannotOpen();
    elf64.read(elfbuff,0x00000200*sizeof(char));
    length=(short)elfbuff[0xa0];

    printf("Code: ");
    for(short i=0;i<length;i++)
    {
        *p=elfbuff[0x0000180+i];
        printf("%02x ",(unsigned char)*p);
        p++;
    }
    printf("\n");
    elf64.close();
#endif //OUTSIDE_PARSING
}