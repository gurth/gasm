//
// Created by gurth on 9/16/20.
//

#include "translate.h"
#include <vector>

using namespace std;

Translate::Translate()
{

}

Translate::Translate(std::string cmd)
{
    this->raw_cmd=cmd;
    Parsing();
}

Translate::~Translate()
{

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