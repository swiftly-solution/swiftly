#ifndef _memstr_h
#define _memstr_h

#include <map>
#include <string>

extern std::map<std::string, char *> memstrCache;

class MemStr
{
private:
    std::string getStr;

public:
    MemStr(std::string str);

    char *Get();
    void DeleteAfter(uint64_t ms);
};

#endif