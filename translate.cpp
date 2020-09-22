//
// Created by gurth on 9/16/20.
//

#include "translate.h"
#include <vector>
#include<cstring>

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

}