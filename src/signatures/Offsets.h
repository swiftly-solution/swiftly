#ifndef _offsets_h
#define _offsets_h

#include <string>
#include <map>

class Offsets
{
private:
    std::map<std::string, int> offsets;

public:
    Offsets() {}

    void LoadOffsets();
    int GetOffset(std::string name);
};

extern Offsets *g_Offsets;

#endif