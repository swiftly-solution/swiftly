#ifndef _registercallstack_h
#define _registercallstack_h

#include <string>

class RegisterCallStack
{
private:
    std::string plugin_name;
    std::string id;

public:
    RegisterCallStack(std::string plugin_name, std::string stack_msg);
    ~RegisterCallStack();
};

#endif