#ifndef _precacher_h
#define _precacher_h

#include <cstdint>
#include <vector>
#include <string>
#include <algorithm>

class Precacher
{
private:
    int64_t precacheContext = 0;
    std::vector<std::string> cacheModels;
    std::vector<std::string> precachedModels;

public:
    Precacher(){};

    void SetContext(int64_t context) { this->precacheContext = context; }
    int64_t GetContext() { return this->precacheContext; }

    void Reset()
    {
        this->precacheContext = 0;
        this->precachedModels.clear();
    }

    void AddModel(std::string model);
    void CacheModels();

    bool HasModelInList(std::string model)
    {
        return (std::find(this->precachedModels.begin(), this->precachedModels.end(), model) != this->precachedModels.end());
    }

    void CacheModel(const char *model);
};

extern Precacher *g_precacher;

#endif