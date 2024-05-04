#include "../common.h"
#include "memstr.h"

#include <cstring>
#include <thread>
#include <set>

struct DeleteCache
{
    std::string key;
    uint64_t ms;
};

std::map<std::string, StrCache> memstrCache;
std::set<DeleteCache> memstrDelete;

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

    DeleteCache value = {deleteString, ms};
    memstrDelete.insert(value);
}

void MemStrCleanup()
{
    std::thread([]() -> void
                {
        while(true) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            for(auto it = memstrDelete.begin(); it != memstrDelete.end(); ++it)
            {
                DeleteCache value = *it;
                if(memstrCache.find(value.key) == memstrCache.end()) {
                    memstrDelete.erase(it);
                    continue;
                }

                StrCache cache = memstrCache.at(value.key);
                if(GetTime() - cache.lastUsed <= value.ms) continue;

                delete[] cache.stringptr;
                memstrCache.erase(value.key);
                memstrDelete.erase(it);
            }
        } })
        .detach();
}