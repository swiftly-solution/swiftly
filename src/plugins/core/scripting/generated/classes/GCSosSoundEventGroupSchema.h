class GCSosSoundEventGroupSchema;

#ifndef _gccsossoundeventgroupschema_h
#define _gccsossoundeventgroupschema_h

#include "../../../scripting.h"

#include "../types/GSosGroupType_t.h"
#include "GCSosGroupMatchPattern.h"
#include "GCSosGroupBranchPattern.h"
#include "GCSosGroupActionSchema.h"

class GCSosSoundEventGroupSchema
{
private:
    void *m_ptr;

public:
    GCSosSoundEventGroupSchema() {}
    GCSosSoundEventGroupSchema(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "CSosSoundEventGroupSchema", "m_name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "CSosSoundEventGroupSchema", "m_name", false, value); }
    SosGroupType_t GetType() const { return GetSchemaValue<SosGroupType_t>(m_ptr, "CSosSoundEventGroupSchema", "m_nType"); }
    void SetType(SosGroupType_t value) { SetSchemaValue(m_ptr, "CSosSoundEventGroupSchema", "m_nType", false, value); }
    bool GetIsBlocking() const { return GetSchemaValue<bool>(m_ptr, "CSosSoundEventGroupSchema", "m_bIsBlocking"); }
    void SetIsBlocking(bool value) { SetSchemaValue(m_ptr, "CSosSoundEventGroupSchema", "m_bIsBlocking", false, value); }
    int32_t GetBlockMaxCount() const { return GetSchemaValue<int32_t>(m_ptr, "CSosSoundEventGroupSchema", "m_nBlockMaxCount"); }
    void SetBlockMaxCount(int32_t value) { SetSchemaValue(m_ptr, "CSosSoundEventGroupSchema", "m_nBlockMaxCount", false, value); }
    bool GetInvertMatch() const { return GetSchemaValue<bool>(m_ptr, "CSosSoundEventGroupSchema", "m_bInvertMatch"); }
    void SetInvertMatch(bool value) { SetSchemaValue(m_ptr, "CSosSoundEventGroupSchema", "m_bInvertMatch", false, value); }
    GCSosGroupMatchPattern GetMatchPattern() const { return GetSchemaValue<GCSosGroupMatchPattern>(m_ptr, "CSosSoundEventGroupSchema", "m_matchPattern"); }
    void SetMatchPattern(GCSosGroupMatchPattern value) { SetSchemaValue(m_ptr, "CSosSoundEventGroupSchema", "m_matchPattern", false, value); }
    GCSosGroupBranchPattern GetBranchPattern() const { return GetSchemaValue<GCSosGroupBranchPattern>(m_ptr, "CSosSoundEventGroupSchema", "m_branchPattern"); }
    void SetBranchPattern(GCSosGroupBranchPattern value) { SetSchemaValue(m_ptr, "CSosSoundEventGroupSchema", "m_branchPattern", false, value); }
    float GetLifeSpanTime() const { return GetSchemaValue<float>(m_ptr, "CSosSoundEventGroupSchema", "m_flLifeSpanTime"); }
    void SetLifeSpanTime(float value) { SetSchemaValue(m_ptr, "CSosSoundEventGroupSchema", "m_flLifeSpanTime", false, value); }
    std::vector<GCSosGroupActionSchema*> GetActions() const { GCSosGroupActionSchema** outValue = GetSchemaValue<GCSosGroupActionSchema**>(m_ptr, "CSosSoundEventGroupSchema", "m_vActions"); std::vector<GCSosGroupActionSchema*> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetActions(std::vector<GCSosGroupActionSchema*> value) { GCSosGroupActionSchema** outValue = GetSchemaValue<GCSosGroupActionSchema**>(m_ptr, "CSosSoundEventGroupSchema", "m_vActions"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CSosSoundEventGroupSchema", "m_vActions", false, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif