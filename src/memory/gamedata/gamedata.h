#ifndef _memory_gamedata_gamedata_h
#define _memory_gamedata_gamedata_h

#include <map>
#include <string>

class GameData {
private:
    std::map<std::string, void*> signatures;

    std::map<std::string, std::string> patches;
    std::map<std::string, std::string> patches_signatures;

    std::map<std::string, int> offsets;
public:
    void LoadGameData();

    void LoadSignatures(std::string game_folder);

    template <typename T>
    T FetchSignature(std::string name)
    {
        if (!ExistsSignature(name))
            return nullptr;

        return reinterpret_cast<T>(signatures[name]);
    }

    void* FetchRawSignature(std::string name);
    bool ExistsSignature(std::string name);

    void LoadPatches(std::string game_folder);
    void PerformPatch(std::string patch_name);
    void PerformPatches();

    void LoadOffsets(std::string game_folder);
    int GetOffset(std::string name);
};

extern GameData g_GameData;

#endif