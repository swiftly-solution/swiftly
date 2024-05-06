#include "../common.h"
#include "memstr.h"

#include <cstring>
#include <thread>
#include <vector>

struct DeleteStrCache
{
    std::string key;
    uint64_t ms;
};

std::map<std::string, StrCache> memstrCache;
std::vector<DeleteStrCache> memstrDelete;
uint64_t GetTime();

MemStr::MemStr(std::string str)
{
    this->getStr = str;
    if (memstrCache.find(str) == memstrCache.end())
    {
        char *strPtr = new char[str.size() + 1];
        strcpy(strPtr, str.c_str());
        StrCache strcache = {
            strPtr,
            GetTime(),
        };
        memstrCache.insert({
            str,
            strcache,
        });
    }
}

char *MemStr::Get()
{
    StrCache str = memstrCache.at(this->getStr);
    str.lastUsed = GetTime();
    memstrCache[this->getStr] = str;
    return str.stringptr;
}

void MemStr::DeleteAfter(uint64_t ms)
{
    std::string deleteString = this->getStr;

    if (memstrCache.find(deleteString) == memstrCache.end())
        return;

    for (auto it = memstrDelete.begin(); it != memstrDelete.end(); ++it)
        if ((*it).key == deleteString)
            return;

    DeleteStrCache value = {deleteString, ms};
    memstrDelete.push_back(value);
}

void MemStrCleanup()
{
    for (auto it = memstrDelete.begin(); it != memstrDelete.end(); ++it)
    {
        DeleteStrCache value = *it;

        if (memstrCache.find(value.key) == memstrCache.end())
        {
            memstrDelete.erase(it);
            continue;
        }

        if (GetTime() - memstrCache.at(value.key).lastUsed > value.ms)
        {
            StrCache cache = memstrCache.at(value.key);
            delete[] cache.stringptr;
            memstrCache.erase(value.key);
            memstrDelete.erase(it);
        }
    }
}