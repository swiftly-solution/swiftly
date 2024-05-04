#ifndef _memstr_h
#define _memstr_h

#include <map>
#include <string>

struct StrCache
{
    char *stringptr;
    uint64_t lastUsed;
};

extern std::map<std::string, StrCache> memstrCache;

class MemStr
{
private:
    std::string getStr;

public:
    MemStr(std::string str);

    char *Get();
    void DeleteAfter(uint64_t ms);
};

void MemStrCleanup();

#endif