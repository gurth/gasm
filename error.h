//
// Created by gurth on 9/16/20.
//

#ifndef GASM_ERROR_H
#define GASM_ERROR_H

#include <exception>

class ErrorCommand : public std::exception
{
public:
    const char * what () const throw ()
    {
        return "Command Error";
    }
};

class MemoryOverFlow : public std::exception
{
public:
    const char * what () const throw ()
    {
        return "Memory Overflow";
    }
};

class InitFailed : public std::exception
{
public:
    const char * what () const throw ()
    {
        return "Init Faild";
    }
};

#endif //GASM_ERROR_H
