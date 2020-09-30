//
// Created by gurth on 9/16/20.
// Define some errors derive from std::exception
//
//

#ifndef GASM_ERROR_H
#define GASM_ERROR_H

#include <exception>

class ErrorCommand : public std::exception             // Command is invalid
{
public:
    const char * what () const throw ()
    {
        return "Command Error";
    }
};

class MemoryOverFlow : public std::exception          // Stack overflow
{
public:
    const char * what () const throw ()
    {
        return "Memory Overflow";
    }
};

class InitFailed : public std::exception              // Cannot init, especially memory
{
public:
    const char * what () const throw ()
    {
        return "Init Faild";
    }
};

class FileCannotOpen : public std::exception          // Cannot open file
{
public:
    const char * what () const throw ()
    {
        return "Cannot open file.";
    }
};

class PipeCannotOpen : public std::exception          // Cannot create a pipe
{
public:
    const char * what () const throw ()
    {
        return "Cannot open pipe.";
    }
};

#endif //GASM_ERROR_H
