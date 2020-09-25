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
    if(!ftmp)
        throw FileCannotOpen();
    fputs(raw_cmd.c_str(),ftmp);
    fclose(ftmp);
    int asm_pipe = system("nasm -f elf64 ./.cache/tmp.asm -o ./.cache/tmp.o");
    if(asm_pipe)
        throw ErrorCommand();
    FILE* cmd_pipe=popen("objdump -M intel -d ./.cache/tmp.o | cut -f 2 | cut -d ':' -f 3", "r");
    if(!cmd_pipe)
        throw PipeCannotOpen();
    unsigned long long ctmp=0;
    char *pb=machine_code;
    while (!feof(cmd_pipe))
    {
        if(fscanf(cmd_pipe,"%02x",&ctmp) == EOF) break;
        (*pb)=(char)ctmp;
        pb++;
        length++;
    }
    pclose(cmd_pipe);

    system("rm ./.cache/* -f");
#endif //OUTSIDE_PARSING
}