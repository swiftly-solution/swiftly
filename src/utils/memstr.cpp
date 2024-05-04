#include "../common.h"
#include "memstr.h"

#include <cstring>
#include <thread>

std::map<std::string, StrCache> memstrCache;

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

    if (memstrCache.at(deleteString).hasDetachThreadActivated)
        return;

    StrCache str = memstrCache.at(deleteString);
    str.hasDetachThreadActivated = true;
    memstrCache[deleteString] = str;

    std::thread([deleteString, ms]() -> void
                {
        if(memstrCache.find(deleteString) != memstrCache.end()) {
            try {
                while(GetTime() - memstrCache.at(deleteString).lastUsed <= ms) { std::this_thread::sleep_for(std::chrono::milliseconds(ms)); }
                StrCache str = memstrCache.at(deleteString);
                memstrCache.erase(deleteString);
                delete[] str.stringptr;
            } catch(std::out_of_range &e) {
                PRINTF("EXCEPTION", "%s not in delete list: %s\n", deleteString.c_str(), e.what());
            }
        } })
        .detach();
}