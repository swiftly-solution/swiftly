class GCTriggerSndSosOpvar;

#ifndef _gcctriggersndsosopvar_h
#define _gcctriggersndsosopvar_h

#include "../../../scripting.h"




class GCTriggerSndSosOpvar
{
private:
    void *m_ptr;

public:
    GCTriggerSndSosOpvar() {}
    GCTriggerSndSosOpvar(void *ptr) : m_ptr(ptr) {}

    Vector GetPosition() const { return GetSchemaValue<Vector>(m_ptr, "CTriggerSndSosOpvar", "m_flPosition"); }
    void SetPosition(Vector value) { SetSchemaValue(m_ptr, "CTriggerSndSosOpvar", "m_flPosition", false, value); }
    float GetCenterSize() const { return GetSchemaValue<float>(m_ptr, "CTriggerSndSosOpvar", "m_flCenterSize"); }
    void SetCenterSize(float value) { SetSchemaValue(m_ptr, "CTriggerSndSosOpvar", "m_flCenterSize", false, value); }
    float GetMinVal() const { return GetSchemaValue<float>(m_ptr, "CTriggerSndSosOpvar", "m_flMinVal"); }
    void SetMinVal(float value) { SetSchemaValue(m_ptr, "CTriggerSndSosOpvar", "m_flMinVal", false, value); }
    float GetMaxVal() const { return GetSchemaValue<float>(m_ptr, "CTriggerSndSosOpvar", "m_flMaxVal"); }
    void SetMaxVal(float value) { SetSchemaValue(m_ptr, "CTriggerSndSosOpvar", "m_flMaxVal", false, value); }
    CUtlSymbolLarge GetOpvarName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTriggerSndSosOpvar", "m_opvarName"); }
    void SetOpvarName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CTriggerSndSosOpvar", "m_opvarName", false, value); }
    CUtlSymbolLarge GetStackName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTriggerSndSosOpvar", "m_stackName"); }
    void SetStackName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CTriggerSndSosOpvar", "m_stackName", false, value); }
    CUtlSymbolLarge GetOperatorName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTriggerSndSosOpvar", "m_operatorName"); }
    void SetOperatorName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CTriggerSndSosOpvar", "m_operatorName", false, value); }
    bool GetVolIs2D() const { return GetSchemaValue<bool>(m_ptr, "CTriggerSndSosOpvar", "m_bVolIs2D"); }
    void SetVolIs2D(bool value) { SetSchemaValue(m_ptr, "CTriggerSndSosOpvar", "m_bVolIs2D", false, value); }
    std::string GetOpvarNameChar() const { return GetSchemaValue<char*>(m_ptr, "CTriggerSndSosOpvar", "m_opvarNameChar"); }
    void SetOpvarNameChar(std::string value) { SetSchemaValue(m_ptr, "CTriggerSndSosOpvar", "m_opvarNameChar", false, value); }
    std::string GetStackNameChar() const { return GetSchemaValue<char*>(m_ptr, "CTriggerSndSosOpvar", "m_stackNameChar"); }
    void SetStackNameChar(std::string value) { SetSchemaValue(m_ptr, "CTriggerSndSosOpvar", "m_stackNameChar", false, value); }
    std::string GetOperatorNameChar() const { return GetSchemaValue<char*>(m_ptr, "CTriggerSndSosOpvar", "m_operatorNameChar"); }
    void SetOperatorNameChar(std::string value) { SetSchemaValue(m_ptr, "CTriggerSndSosOpvar", "m_operatorNameChar", false, value); }
    Vector GetVecNormPos() const { return GetSchemaValue<Vector>(m_ptr, "CTriggerSndSosOpvar", "m_VecNormPos"); }
    void SetVecNormPos(Vector value) { SetSchemaValue(m_ptr, "CTriggerSndSosOpvar", "m_VecNormPos", false, value); }
    float GetNormCenterSize() const { return GetSchemaValue<float>(m_ptr, "CTriggerSndSosOpvar", "m_flNormCenterSize"); }
    void SetNormCenterSize(float value) { SetSchemaValue(m_ptr, "CTriggerSndSosOpvar", "m_flNormCenterSize", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif