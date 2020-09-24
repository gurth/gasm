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
    machine_code=(char*)malloc(sizeof(char)*MACHIEE_CODE_LENGTH);
}

Translate::Translate(std::string cmd)
{
    machine_code=(char*)malloc(sizeof(char)*MACHIEE_CODE_LENGTH);
    this->raw_cmd=cmd;
    Parsing();
    AttachReturn();
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

void Translate::AttachReturn()
{
    machine_code[length]=0xc3;
    length++;
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
    system("mkdir -p .cache");
    ofstream out("./.cache/tmp.asm",ios::out);
    if(!out.is_open())
        throw FileCannotOpen();
    out << raw_cmd;
    out.close();
    system("nasm -f elf64 ./.cache/tmp.asm -o ./.cache/tmp.o");
    FILE* cmd_pipe=popen("objdump -M intel -d ./.cache/tmp.o | grep 0:", "r");
    if(!cmd_pipe)
        throw PipeCannotOpen();
    unsigned long long ctmp=0;
    fscanf(cmd_pipe,"02x",&ctmp);
    while(true)
        if (fgetc(cmd_pipe) == 9) break;
    char *pb=machine_code;
    while (true)
    {
        if(!fscanf(cmd_pipe,"%02x",&ctmp)) break;
        (*pb)=(char)ctmp;
        pb++;
        length++;
    }
    pclose(cmd_pipe);
#endif //OUTSIDE_PARSING
}