#ifndef _precacher_h
#define _precacher_h

#include <cstdint>
#include <vector>
#include <string>

class Precacher
{
private:
    int64_t precacheContext = 0;
    std::vector<std::string> cacheModels;

public:
    Precacher(){};

    void SetContext(int64_t context) { this->precacheContext = context; }
    int64_t GetContext() { return this->precacheContext; }

    void Reset() { this->precacheContext = 0; }

    void AddModel(std::string model);
    void CacheModels();

    void CacheModel(const char *model);
};

extern Precacher *g_precacher;

#endif