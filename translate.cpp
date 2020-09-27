//
// Created by gurth on 9/16/20.
//

#include "translate.h"
#ifndef OUTSIDE_PARSING
#include <vector>
#endif //OUTSIDE_PARSING
#ifdef OUTSIDE_PARSING
#include <fstream>
#include <cstdio>
#endif //OUTSIDE_PARSING
#include<cstring>
#include "error.h"

using namespace std;

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

void Translate::AttchSuffix(char *suffix, short suf_len)
{
    memcpy(machine_code+length,suffix,suf_len);
    length+=suf_len;
}

void Translate::Parsing()
{
#ifndef OUTSIDE_PARSING
    string::size_type pos = raw_cmd.find(' ');
    string hcmd=raw_cmd.substr(0,pos);
    vector<string> tcmd;
    string::size_type bpos=pos+1;
    while(true)
    {
        pos = raw_cmd.find(',', bpos);
        if(string::npos == pos)
        {
            tcmd.push_back(raw_cmd.substr(bpos,raw_cmd.size()-bpos));
            break;
        }
        tcmd.push_back(raw_cmd.substr(bpos,pos-bpos));
        bpos = pos + 1;
    }
#endif //OUTSIDE_PARSING
#ifdef OUTSIDE_PARSING
    FILE* ftmp=fopen("./.cache/tmp.asm","w");
    char elfbuff[0x00000200];
    if(!ftmp)
        throw FileCannotOpen();
    fputs(raw_cmd.c_str(),ftmp);
    fclose(ftmp);
    int sysresult = system("nasm -f elf64 ./.cache/tmp.asm -o ./.cache/tmp.o");
    if(sysresult)
        throw ErrorCommand();
    char*p=machine_code;
    ifstream elf64("./.cache/tmp.o",ios::in | ios::binary);
    if(!elf64.is_open())
        throw FileCannotOpen();
    elf64.read(elfbuff,0x00000200*sizeof(char));
    length=(short)elfbuff[0xa0];
    for(short i=0;i<length;i++)
    {
        *p=elfbuff[0x0000180+i];
        p++;
    }
    elf64.close();
#endif //OUTSIDE_PARSING
}