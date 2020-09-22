//
// Created by gurth on 9/16/20.
//

#ifndef GASM_TRANSLATE_H
#define GASM_TRANSLATE_H

#include <string>
class Translate{
private:
    std::string raw_cmd;
    char* machine_code= nullptr;
    short length;
private:
    void Parsing();
public:
    Translate();
    Translate(std::string cmd);
    ~Translate();
};

#endif //GASM_TRANSLATE_H
