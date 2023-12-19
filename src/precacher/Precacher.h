#ifndef _precacher_h
#define _precacher_h

#include <cstdint>

class Precacher
{
private:
    int64_t precacheContext;

public:
    Precacher(){};

    void SetContext(int64_t context) { this->precacheContext = context; }

    void CacheModel(const char *model);
};

extern Precacher *g_precacher;

#endif