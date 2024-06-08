class GCCSPlayerController_InventoryServices;

#ifndef _gcccsplayercontroller_inventoryservices_h
#define _gcccsplayercontroller_inventoryservices_h

#include "../../../scripting.h"

#include "../types/GMedalRank_t.h"
#include "GServerAuthoritativeWeaponSlot_t.h"

class GCCSPlayerController_InventoryServices
{
private:
    void *m_ptr;

public:
    GCCSPlayerController_InventoryServices() {}
    GCCSPlayerController_InventoryServices(void *ptr) : m_ptr(ptr) {}

    uint16_t GetMusicID() const { return GetSchemaValue<uint16_t>(m_ptr, "CCSPlayerController_InventoryServices", "m_unMusicID"); }
    void SetMusicID(uint16_t value) { SetSchemaValue(m_ptr, "CCSPlayerController_InventoryServices", "m_unMusicID", false, value); }
    std::vector<MedalRank_t> GetRank() const { MedalRank_t* outValue = GetSchemaValue<MedalRank_t*>(m_ptr, "CCSPlayerController_InventoryServices", "m_rank"); std::vector<MedalRank_t> ret; for(int i = 0; i < 6; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetRank(std::vector<MedalRank_t> value) { MedalRank_t* outValue = GetSchemaValue<MedalRank_t*>(m_ptr, "CCSPlayerController_InventoryServices", "m_rank"); for(int i = 0; i < 6; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSPlayerController_InventoryServices", "m_rank", false, outValue); }
    int32_t GetPersonaDataPublicLevel() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController_InventoryServices", "m_nPersonaDataPublicLevel"); }
    void SetPersonaDataPublicLevel(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController_InventoryServices", "m_nPersonaDataPublicLevel", false, value); }
    int32_t GetPersonaDataPublicCommendsLeader() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController_InventoryServices", "m_nPersonaDataPublicCommendsLeader"); }
    void SetPersonaDataPublicCommendsLeader(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController_InventoryServices", "m_nPersonaDataPublicCommendsLeader", false, value); }
    int32_t GetPersonaDataPublicCommendsTeacher() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController_InventoryServices", "m_nPersonaDataPublicCommendsTeacher"); }
    void SetPersonaDataPublicCommendsTeacher(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController_InventoryServices", "m_nPersonaDataPublicCommendsTeacher", false, value); }
    int32_t GetPersonaDataPublicCommendsFriendly() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController_InventoryServices", "m_nPersonaDataPublicCommendsFriendly"); }
    void SetPersonaDataPublicCommendsFriendly(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController_InventoryServices", "m_nPersonaDataPublicCommendsFriendly", false, value); }
    int32_t GetPersonaDataXpTrailLevel() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController_InventoryServices", "m_nPersonaDataXpTrailLevel"); }
    void SetPersonaDataXpTrailLevel(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController_InventoryServices", "m_nPersonaDataXpTrailLevel", false, value); }
    std::vector<uint32_t> GetEquippedPlayerSprayIDs() const { uint32_t* outValue = GetSchemaValue<uint32_t*>(m_ptr, "CCSPlayerController_InventoryServices", "m_unEquippedPlayerSprayIDs"); std::vector<uint32_t> ret; for(int i = 0; i < 1; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetEquippedPlayerSprayIDs(std::vector<uint32_t> value) { uint32_t* outValue = GetSchemaValue<uint32_t*>(m_ptr, "CCSPlayerController_InventoryServices", "m_unEquippedPlayerSprayIDs"); for(int i = 0; i < 1; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSPlayerController_InventoryServices", "m_unEquippedPlayerSprayIDs", false, outValue); }
    std::vector<GServerAuthoritativeWeaponSlot_t> GetServerAuthoritativeWeaponSlots() const { CUtlVector<GServerAuthoritativeWeaponSlot_t>* vec = GetSchemaValue<CUtlVector<GServerAuthoritativeWeaponSlot_t>*>(m_ptr, "CCSPlayerController_InventoryServices", "m_vecServerAuthoritativeWeaponSlots"); std::vector<GServerAuthoritativeWeaponSlot_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetServerAuthoritativeWeaponSlots(std::vector<GServerAuthoritativeWeaponSlot_t> value) { SetSchemaValueCUtlVector<GServerAuthoritativeWeaponSlot_t>(m_ptr, "CCSPlayerController_InventoryServices", "m_vecServerAuthoritativeWeaponSlots", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif