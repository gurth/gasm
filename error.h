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

class FileCannotOpen : public std::exception
{
public:
    const char * what () const throw ()
    {
        return "Cannot open file.";
    }
};

class PipeCannotOpen : public std::exception
{
public:
    const char * what () const throw ()
    {
        return "Cannot open pipe.";
    }
};

#endif //GASM_ERROR_H
