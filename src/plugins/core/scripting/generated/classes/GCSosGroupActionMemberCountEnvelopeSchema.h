class GCSosGroupActionMemberCountEnvelopeSchema;

#ifndef _gccsosgroupactionmembercountenvelopeschema_h
#define _gccsosgroupactionmembercountenvelopeschema_h

#include "../../../scripting.h"




class GCSosGroupActionMemberCountEnvelopeSchema
{
private:
    void *m_ptr;

public:
    GCSosGroupActionMemberCountEnvelopeSchema() {}
    GCSosGroupActionMemberCountEnvelopeSchema(void *ptr) : m_ptr(ptr) {}

    int32_t GetBaseCount() const { return GetSchemaValue<int32_t>(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_nBaseCount"); }
    void SetBaseCount(int32_t value) { SetSchemaValue(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_nBaseCount", false, value); }
    int32_t GetTargetCount() const { return GetSchemaValue<int32_t>(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_nTargetCount"); }
    void SetTargetCount(int32_t value) { SetSchemaValue(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_nTargetCount", false, value); }
    float GetBaseValue() const { return GetSchemaValue<float>(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_flBaseValue"); }
    void SetBaseValue(float value) { SetSchemaValue(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_flBaseValue", false, value); }
    float GetTargetValue() const { return GetSchemaValue<float>(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_flTargetValue"); }
    void SetTargetValue(float value) { SetSchemaValue(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_flTargetValue", false, value); }
    float GetAttack() const { return GetSchemaValue<float>(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_flAttack"); }
    void SetAttack(float value) { SetSchemaValue(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_flAttack", false, value); }
    float GetDecay() const { return GetSchemaValue<float>(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_flDecay"); }
    void SetDecay(float value) { SetSchemaValue(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_flDecay", false, value); }
    CUtlString GetResultVarName() const { return GetSchemaValue<CUtlString>(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_resultVarName"); }
    void SetResultVarName(CUtlString value) { SetSchemaValue(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_resultVarName", false, value); }
    bool GetSaveToGroup() const { return GetSchemaValue<bool>(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_bSaveToGroup"); }
    void SetSaveToGroup(bool value) { SetSchemaValue(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_bSaveToGroup", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif