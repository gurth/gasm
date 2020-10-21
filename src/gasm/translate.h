//
// Created by gurth on 9/16/20.
//

#ifndef GASM_TRANSLATE_H
#define GASM_TRANSLATE_H

#define MACHIEE_CODE_LENGTH 32

//#define OUTSIDE_PARSING
#define INSIDE_PARSING
#define ALLOW_REALLOC

#include <string>

class Translate{
private:
    std::string raw_cmd;                  // Original command
    char* machine_code= nullptr;          // Assembler result
    size_t length=0;                      // Machine code length
private:
    void Parsing();                       // Main parsing progress
public:
    static short max_length;              // Machine code max length
public:
    Translate();
    Translate(std::string cmd);           // Constructor, parsing raw command
    ~Translate();
    void CopyCode(char* exe_buff);        // Copy code to exe buffer
    void AttchSuffix(char*suffix,short suf_len);  // Attach suffix behind machine code
    void ShowMachineCode();               // Show machine code in hex
};

#endif //GASM_TRANSLATE_H
