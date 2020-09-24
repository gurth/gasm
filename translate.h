//
// Created by gurth on 9/16/20.
//

#ifndef GASM_TRANSLATE_H
#define GASM_TRANSLATE_H

#define MACHIEE_CODE_LENGTH 32

#define OUTSIDE_PARSING

#include <string>
class Translate{
private:
    std::string raw_cmd;
    char* machine_code= nullptr;
    short length=0;
private:
    void Parsing();
    void AttachReturn();
public:
    Translate();
    Translate(std::string cmd);
    ~Translate();
    void CopyCode(char* exe_buff);
};

#endif //GASM_TRANSLATE_H
