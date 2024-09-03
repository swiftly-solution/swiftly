#pragma once

#include <map>
#include <string>

#include <variant.h>

class CBasePlayerController;
class CCSPlayerController;
class CBaseEntity;
class CBaseModelEntity;
class CEntityInstance;
class CCSPlayer_ItemServices;
class CCSPlayerPawn;
class CCSPlayerPawnBase;
class CTakeDamageInfo;
class IRecipientFilter;
class CEntityIndex;
class CCSPlayer_MovementServices;

struct EmitSound_t;
struct SndOpEventGuid_t;

typedef void (*ClientPrint)(CBasePlayerController*, int, const char*, const char*, const char*, const char*, const char*);
typedef void (*CCSPlayerController_SwitchTeam)(CCSPlayerController* pController, unsigned int team);
typedef void* (*UTIL_CreateEntityByName)(const char*, int);
typedef void (*CBaseModelEntity_SetModel_t)(CBaseModelEntity*, const char*);
typedef void (*CBaseEntity_DispatchSpawn)(CBaseEntity*, void*);
typedef void (*UTIL_Remove)(CEntityInstance*);
typedef void (*CEntityInstance_AcceptInput)(CEntityInstance*, const char*, CEntityInstance*, CEntityInstance*, variant_t*, int);
typedef void (*CAttributeList_SetOrAddAttributeValueByName_t)(void*, const char*, float);
typedef void (*CBaseModelEntity_SetBodygroup_t)(void*, const char*, ...);
typedef void (*GiveNamedItem_t)(CCSPlayer_ItemServices*, const char*, int, int, int, int);
typedef void (*CBasePlayerController_SetPawn)(CBasePlayerController*, CCSPlayerPawn*, bool, bool);
typedef void (*CCSPlayerPawnBase_PostThink)(CCSPlayerPawnBase*);
typedef void (*CCSPlayer_MovementServices_CheckJumpPre)(CCSPlayer_MovementServices*, void*);
typedef SndOpEventGuid_t(*CBaseEntity_EmitSoundFilter)(IRecipientFilter& filter, CEntityIndex ent, const EmitSound_t& params);

class Signatures
{
private:
    std::map<std::string, void*> signatures;

public:
    void LoadSignatures();

    template <typename T>
    T FetchSignature(std::string name)
    {
        if (!this->Exists(name))
            return nullptr;

        return reinterpret_cast<T>(this->signatures.at(name));
    }

    void* FetchRawSignature(std::string name)
    {
        if (!this->Exists(name))
            return nullptr;

        return this->signatures.at(name);
    }

    bool Exists(std::string name);
};

extern Signatures* g_Signatures;