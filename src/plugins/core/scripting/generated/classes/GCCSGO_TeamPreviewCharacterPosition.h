class GCCSGO_TeamPreviewCharacterPosition;

#ifndef _gcccsgo_teampreviewcharacterposition_h
#define _gcccsgo_teampreviewcharacterposition_h

#include "../../../scripting.h"


#include "GCEconItemView.h"

class GCCSGO_TeamPreviewCharacterPosition
{
private:
    void *m_ptr;

public:
    GCCSGO_TeamPreviewCharacterPosition() {}
    GCCSGO_TeamPreviewCharacterPosition(void *ptr) : m_ptr(ptr) {}

    int32_t GetVariant() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_nVariant"); }
    void SetVariant(int32_t value) { SetSchemaValue(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_nVariant", false, value); }
    int32_t GetRandom() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_nRandom"); }
    void SetRandom(int32_t value) { SetSchemaValue(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_nRandom", false, value); }
    int32_t GetOrdinal() const { return GetSchemaValue<int32_t>(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_nOrdinal"); }
    void SetOrdinal(int32_t value) { SetSchemaValue(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_nOrdinal", false, value); }
    CUtlString GetWeaponName() const { return GetSchemaValue<CUtlString>(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_sWeaponName"); }
    void SetWeaponName(CUtlString value) { SetSchemaValue(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_sWeaponName", false, value); }
    uint64_t GetXuid() const { return GetSchemaValue<uint64_t>(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_xuid"); }
    void SetXuid(uint64_t value) { SetSchemaValue(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_xuid", false, value); }
    GCEconItemView GetAgentItem() const { return GetSchemaValue<GCEconItemView>(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_agentItem"); }
    void SetAgentItem(GCEconItemView value) { SetSchemaValue(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_agentItem", false, value); }
    GCEconItemView GetGlovesItem() const { return GetSchemaValue<GCEconItemView>(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_glovesItem"); }
    void SetGlovesItem(GCEconItemView value) { SetSchemaValue(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_glovesItem", false, value); }
    GCEconItemView GetWeaponItem() const { return GetSchemaValue<GCEconItemView>(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_weaponItem"); }
    void SetWeaponItem(GCEconItemView value) { SetSchemaValue(m_ptr, "CCSGO_TeamPreviewCharacterPosition", "m_weaponItem", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif