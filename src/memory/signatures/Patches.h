#ifndef _patches_h
#define _patches_h

#include <string>
#include <map>

class Patches
{
private:
    std::map<std::string, std::string> patches;
    std::map<std::string, std::string> signatures;

public:
    Patches() {}

    void LoadPatches();
    void PerformPatch(std::string patch_name);
    void PerformPatches();
};

extern Patches *g_Patches;

#endif