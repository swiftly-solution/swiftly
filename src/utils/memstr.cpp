#include "../common.h"
#include "memstr.h"

#include <cstring>
#include <thread>

std::map<std::string, char *> memstrCache;

MemStr::MemStr(std::string str)
{
    this->getStr = str;
    if (memstrCache.find(str) == memstrCache.end())
    {
        char *strPtr = new char[str.size() + 1];
        strcpy(strPtr, str.c_str());
        memstrCache.insert({
            str,
            strPtr,
        });
    }
}

char *MemStr::Get()
{
    if (memstrCache.find(this->getStr) == memstrCache.end())
    {
        std::string str = this->getStr;
        char *strPtr = new char[str.size() + 1];
        strcpy(strPtr, str.c_str());
        memstrCache.insert({
            str,
            strPtr,
        });
    }
    return memstrCache.at(this->getStr);
}

void MemStr::DeleteAfter(uint64_t ms)
{
    std::string deleteString = this->getStr;

    std::thread([deleteString, ms]() -> void
                {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
        if(memstrCache.find(deleteString) != memstrCache.end()) {
            char* ptr = memstrCache.at(deleteString);
            delete[] ptr;
            memstrCache.erase(deleteString);
        } })
        .detach();
}