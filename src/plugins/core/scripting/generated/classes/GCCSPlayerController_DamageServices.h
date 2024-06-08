class GCCSPlayerController_DamageServices;

#ifndef _gcccsplayercontroller_damageservices_h
#define _gcccsplayercontroller_damageservices_h

#include "../../../scripting.h"


#include "GCDamageRecord.h"

class GCCSPlayerController_DamageServices
{
private:
    void *m_ptr;

public:
    GCCSPlayerController_DamageServices() {}
    GCCSPlayerController_DamageServices(void *ptr) : m_ptr(ptr) {}

    int32_t GetSendUpdate() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController_DamageServices", "m_nSendUpdate"); }
    void SetSendUpdate(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerController_DamageServices", "m_nSendUpdate", false, value); }
    std::vector<GCDamageRecord> GetDamageList() const { CUtlVector<GCDamageRecord>* vec = GetSchemaValue<CUtlVector<GCDamageRecord>*>(m_ptr, "CCSPlayerController_DamageServices", "m_DamageList"); std::vector<GCDamageRecord> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetDamageList(std::vector<GCDamageRecord> value) { SetSchemaValueCUtlVector<GCDamageRecord>(m_ptr, "CCSPlayerController_DamageServices", "m_DamageList", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif