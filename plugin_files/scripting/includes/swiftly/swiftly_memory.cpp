#include "swiftly_memory.h"

HINSTANCE mainProgram;
bool isSet = false;

std::map<const char *, void *> functions;

void *FetchFunctionPtr(const char *filePath, const char *function_name)
{
    if (!isSet)
    {
        isSet = true;
        mainProgram = dlmount(filePath);
    }

    if (functions.find(function_name) != functions.end())
        return functions.at(function_name);

    void *func = reinterpret_cast<void *>(dlsym(mainProgram, function_name));
    functions.insert(std::make_pair(function_name, func));

    return func;
}