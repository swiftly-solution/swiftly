#include "../../scripting.h"
#include "../../../../sdk/access/sdkaccess.h"
#include "../../../../sdk/entity/CBasePlayerController.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"
#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CCSWeaponBase.h"
#include "../../../../player/playermanager/PlayerManager.h"

#include <set>

std::string FetchPluginName(lua_State* state);

std::set<std::string> BlockedCS2GuidelinesFields = {
    "m_bIsValveDS",
    "m_bIsQuestEligible",
    "m_iEntityLevel",
    "m_iItemIDHigh",
    "m_iItemIDLow",
    "m_iAccountID",
    "m_iEntityQuality",
    "m_bInitialized",
    "m_szCustomName",
    "m_iAttributeDefinitionIndex",
    "m_iRawValue32",
    "m_iRawInitialValue32",
    "m_flValue",
    "m_flInitialValue",
    "m_bSetBonus",
    "m_nRefundableCurrency",
    "m_OriginalOwnerXuidLow",
    "m_OriginalOwnerXuidHigh",
    "m_nFallbackPaintKit",
    "m_nFallbackSeed",
    "m_flFallbackWear",
    "m_nFallbackStatTrak",
    "m_iCompetitiveWins",
    "m_iCompetitiveRanking",
    "m_iCompetitiveRankType",
    "m_iCompetitiveRankingPredicted_Win",
    "m_iCompetitiveRankingPredicted_Loss",
    "m_iCompetitiveRankingPredicted_Tie",
    "m_nActiveCoinRank",
    "m_nMusicID",
};

bool followCS2Guidelines = true;

int SDKBaseClass::CBasePlayerController_EntityIndex() {
    return ((CBasePlayerController*)this->GetPtr())->GetEntityIndex().Get();
}

void SDKBaseClass::CAttributeList_SetOrAddAttributeValueByName(std::string str, float value) {
    ((CAttributeList*)this->GetPtr())->SetOrAddAttributeValueByName(str.c_str(), value);
}

void SDKBaseClass::CBaseModelEntity_SetModel(std::string model)
{
    ((CBaseModelEntity*)this->GetPtr())->SetModel(model.c_str());
}

void SDKBaseClass::CBaseModelEntity_SetSolidType(int64_t solidType)
{
    ((CBaseModelEntity*)this->GetPtr())->SetSolidType((SolidType_t)solidType);
}

void SDKBaseClass::CBaseModelEntity_SetBodygroup(std::string str, int64_t val)
{
    ((CBaseModelEntity*)this->GetPtr())->SetBodygroup(str.c_str(), (uint64_t)val);
}

SDKBaseClass SDKBaseClass::CPlayerPawnComponent_GetPawn()
{
    return SDKBaseClass(((CPlayerPawnComponent*)this->GetPtr())->m_pPawn, "CBasePlayerPawn");
}

SDKBaseClass SDKBaseClass::CGameSceneNode_GetSkeletonInstance() {
    return SDKBaseClass(((CGameSceneNode*)this->GetPtr())->GetSkeletonInstance(), "CSkeletonInstance");
}

SDKBaseClass SDKBaseClass::CBaseEntity_EHandle() {
    return SDKBaseClass(((CBaseEntity*)this->GetPtr())->m_pEntity->m_EHandle.Get(), "CBaseEntity");
}

void SDKBaseClass::CBaseEntity_Spawn(PluginCEntityKeyValues* kv) {
    ((CBaseEntity*)this->GetPtr())->DispatchSpawn(kv ? kv->GetKeyVals() : nullptr);
}

void SDKBaseClass::CBaseEntity_Despawn() {
    ((CBaseEntity*)this->GetPtr())->Despawn();
}

void SDKBaseClass::CBaseEntity_AcceptInput(std::string input, SDKBaseClass activator, SDKBaseClass caller, std::string value, int outputID) {
    ((CBaseEntity*)this->GetPtr())->AcceptInput(input.c_str(), (CEntityInstance*)activator.GetPtr(), (CEntityInstance*)caller.GetPtr(), value.c_str(), outputID);
}

std::string SDKBaseClass::CBaseEntity_GetClassname() {
    return ((CBaseEntity*)this->GetPtr())->GetClassname();
}

SDKBaseClass SDKBaseClass::CBaseEntity_GetVData() {
    return SDKBaseClass(((CBaseEntity*)this->GetPtr())->GetVData(), "CEntitySubclassVDataBase");
}

void SDKBaseClass::CBaseEntity_CollisionRulesChanged()
{
    ((CBaseEntity*)this->GetPtr())->CollisionRulesChanged();
}

void SDKBaseClass::CBaseEntity_Teleport(Vector value, QAngle angle) {
    ((CBaseEntity*)this->GetPtr())->Teleport(&value, &angle, nullptr);
}

void SDKBaseClass::CBaseEntity_EmitSound(std::string sound_name, float pitch, float volume) {
    for (int i = 0; i < g_playerManager->GetPlayerCap(); i++) {
        Player* player = g_playerManager->GetPlayer(i);
        if (!player) continue;
        if (player->IsFakeClient()) continue;
        if ((void*)player->GetPlayerController() == this->GetPtr()) {
            CSingleRecipientFilter filter(i);
            ((CBaseEntity*)this->GetPtr())->EmitSoundFilter(filter, sound_name, pitch, volume);
            break;
        }
    }
}

SDKBaseClass::SDKBaseClass(std::string ptr, lua_State* state)
{
    this->m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));

    lua_Debug ar;
    if (lua_getstack(state, 0, &ar)) {
        lua_getinfo(state, "n", &ar);
        this->m_className = ar.name;
    }
    else {
        this->m_className = "CBaseEntity";
    }
    this->classOffset = ((uint64_t) hash_32_fnv1a_const(this->m_className.c_str()) << 32);
}

SDKBaseClass::SDKBaseClass(std::string ptr, std::string className)
{
    this->m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
    this->m_className = className;
    this->classOffset = ((uint64_t) hash_32_fnv1a_const(this->m_className.c_str()) << 32);
}

SDKBaseClass::SDKBaseClass(void* ptr, std::string className)
{
    this->m_ptr = ptr;
    this->m_className = className;
    this->classOffset = ((uint64_t) hash_32_fnv1a_const(this->m_className.c_str()) << 32);
}

std::string SDKBaseClass::GetClassName()
{
    return this->m_className;
}

void* SDKBaseClass::GetPtr()
{
    return this->m_ptr;
}

std::string SDKBaseClass::ToPtr()
{
    return string_format("%p", this->m_ptr);
}

bool SDKBaseClass::IsValid()
{
    return (this->m_ptr != nullptr);
}