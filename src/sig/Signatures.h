#ifndef _signatures_h
#define _signatures_h

#include <map>
#include <string>

class CBasePlayerController;
class CCSPlayerController;
class Z_CBaseEntity;
class CBaseModelEntity;
class CEntityInstance;

typedef void (*ClientPrint)(CBasePlayerController *, int, const char *, const char *, const char *, const char *, const char *);
typedef void (*NetworkStateChanged)(uintptr_t, int, int);
typedef void (*StateChanged)(void *, Z_CBaseEntity *, int, int, int);
typedef void (*CCSPlayerController_SwitchTeam)(CCSPlayerController *pController, unsigned int team);
typedef void *(*UTIL_CreateEntityByName)(const char *, int);
typedef void (*CBaseModelEntity_SetModel)(CBaseModelEntity *, const char *);
typedef void (*CBaseEntity_DispatchSpawn)(Z_CBaseEntity *, void *);
typedef void (*PrecacheResource)(const char *, int64_t);
typedef void (*UTIL_Remove)(CEntityInstance *);

class Signatures
{
private:
    std::map<std::string, void *> signatures;

public:
    void LoadSignatures();

    template <typename T>
    T FetchSignature(std::string name)
    {
        if (!this->Exists(name))
            return nullptr;

        return reinterpret_cast<T>(this->signatures.at(name));
    }

    void *FetchRawSignature(std::string name)
    {
        if (!this->Exists(name))
            return nullptr;

        return this->signatures.at(name);
    }

    bool Exists(std::string name);
};

extern Signatures *g_Signatures;

#endif