class GCompMatPropertyMutator_t;

#ifndef _gccompmatpropertymutator_t_h
#define _gccompmatpropertymutator_t_h

#include "../../../scripting.h"

#include "../types/GCompMatPropertyMutatorType_t.h"
#include "GCompositeMaterialInputLooseVariable_t.h"
#include "GCompMatPropertyMutator_t.h"
#include "GCompMatMutatorCondition_t.h"

class GCompMatPropertyMutator_t
{
private:
    void *m_ptr;

public:
    GCompMatPropertyMutator_t() {}
    GCompMatPropertyMutator_t(void *ptr) : m_ptr(ptr) {}

    bool GetEnabled() const { return GetSchemaValue<bool>(m_ptr, "CompMatPropertyMutator_t", "m_bEnabled"); }
    void SetEnabled(bool value) { SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_bEnabled", true, value); }
    CompMatPropertyMutatorType_t GetMutatorCommandType() const { return GetSchemaValue<CompMatPropertyMutatorType_t>(m_ptr, "CompMatPropertyMutator_t", "m_nMutatorCommandType"); }
    void SetMutatorCommandType(CompMatPropertyMutatorType_t value) { SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_nMutatorCommandType", true, value); }
    CUtlString GetStrInitWith_Container() const { return GetSchemaValue<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_strInitWith_Container"); }
    void SetStrInitWith_Container(CUtlString value) { SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_strInitWith_Container", true, value); }
    CUtlString GetStrCopyProperty_InputContainerSrc() const { return GetSchemaValue<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_strCopyProperty_InputContainerSrc"); }
    void SetStrCopyProperty_InputContainerSrc(CUtlString value) { SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_strCopyProperty_InputContainerSrc", true, value); }
    CUtlString GetStrCopyProperty_InputContainerProperty() const { return GetSchemaValue<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_strCopyProperty_InputContainerProperty"); }
    void SetStrCopyProperty_InputContainerProperty(CUtlString value) { SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_strCopyProperty_InputContainerProperty", true, value); }
    CUtlString GetStrCopyProperty_TargetProperty() const { return GetSchemaValue<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_strCopyProperty_TargetProperty"); }
    void SetStrCopyProperty_TargetProperty(CUtlString value) { SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_strCopyProperty_TargetProperty", true, value); }
    CUtlString GetStrRandomRollInputVars_SeedInputVar() const { return GetSchemaValue<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_strRandomRollInputVars_SeedInputVar"); }
    void SetStrRandomRollInputVars_SeedInputVar(CUtlString value) { SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_strRandomRollInputVars_SeedInputVar", true, value); }
    std::vector<CUtlString> GetRandomRollInputVars_InputVarsToRoll() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "CompMatPropertyMutator_t", "m_vecRandomRollInputVars_InputVarsToRoll"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetRandomRollInputVars_InputVarsToRoll(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_vecRandomRollInputVars_InputVarsToRoll", true, value); }
    CUtlString GetStrCopyMatchingKeys_InputContainerSrc() const { return GetSchemaValue<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_strCopyMatchingKeys_InputContainerSrc"); }
    void SetStrCopyMatchingKeys_InputContainerSrc(CUtlString value) { SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_strCopyMatchingKeys_InputContainerSrc", true, value); }
    CUtlString GetStrCopyKeysWithSuffix_InputContainerSrc() const { return GetSchemaValue<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_strCopyKeysWithSuffix_InputContainerSrc"); }
    void SetStrCopyKeysWithSuffix_InputContainerSrc(CUtlString value) { SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_strCopyKeysWithSuffix_InputContainerSrc", true, value); }
    CUtlString GetStrCopyKeysWithSuffix_FindSuffix() const { return GetSchemaValue<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_strCopyKeysWithSuffix_FindSuffix"); }
    void SetStrCopyKeysWithSuffix_FindSuffix(CUtlString value) { SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_strCopyKeysWithSuffix_FindSuffix", true, value); }
    CUtlString GetStrCopyKeysWithSuffix_ReplaceSuffix() const { return GetSchemaValue<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_strCopyKeysWithSuffix_ReplaceSuffix"); }
    void SetStrCopyKeysWithSuffix_ReplaceSuffix(CUtlString value) { SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_strCopyKeysWithSuffix_ReplaceSuffix", true, value); }
    GCompositeMaterialInputLooseVariable_t GetSetValue_Value() const { return GetSchemaValue<GCompositeMaterialInputLooseVariable_t>(m_ptr, "CompMatPropertyMutator_t", "m_nSetValue_Value"); }
    void SetSetValue_Value(GCompositeMaterialInputLooseVariable_t value) { SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_nSetValue_Value", true, value); }
    CUtlString GetStrGenerateTexture_TargetParam() const { return GetSchemaValue<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_strGenerateTexture_TargetParam"); }
    void SetStrGenerateTexture_TargetParam(CUtlString value) { SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_strGenerateTexture_TargetParam", true, value); }
    CUtlString GetStrGenerateTexture_InitialContainer() const { return GetSchemaValue<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_strGenerateTexture_InitialContainer"); }
    void SetStrGenerateTexture_InitialContainer(CUtlString value) { SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_strGenerateTexture_InitialContainer", true, value); }
    int32_t GetResolution() const { return GetSchemaValue<int32_t>(m_ptr, "CompMatPropertyMutator_t", "m_nResolution"); }
    void SetResolution(int32_t value) { SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_nResolution", true, value); }
    bool GetIsScratchTarget() const { return GetSchemaValue<bool>(m_ptr, "CompMatPropertyMutator_t", "m_bIsScratchTarget"); }
    void SetIsScratchTarget(bool value) { SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_bIsScratchTarget", true, value); }
    bool GetSplatDebugInfo() const { return GetSchemaValue<bool>(m_ptr, "CompMatPropertyMutator_t", "m_bSplatDebugInfo"); }
    void SetSplatDebugInfo(bool value) { SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_bSplatDebugInfo", true, value); }
    bool GetCaptureInRenderDoc() const { return GetSchemaValue<bool>(m_ptr, "CompMatPropertyMutator_t", "m_bCaptureInRenderDoc"); }
    void SetCaptureInRenderDoc(bool value) { SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_bCaptureInRenderDoc", true, value); }
    std::vector<GCompMatPropertyMutator_t> GetTexGenInstructions() const { CUtlVector<GCompMatPropertyMutator_t>* vec = GetSchemaValue<CUtlVector<GCompMatPropertyMutator_t>*>(m_ptr, "CompMatPropertyMutator_t", "m_vecTexGenInstructions"); std::vector<GCompMatPropertyMutator_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTexGenInstructions(std::vector<GCompMatPropertyMutator_t> value) { SetSchemaValueCUtlVector<GCompMatPropertyMutator_t>(m_ptr, "CompMatPropertyMutator_t", "m_vecTexGenInstructions", true, value); }
    std::vector<GCompMatPropertyMutator_t> GetConditionalMutators() const { CUtlVector<GCompMatPropertyMutator_t>* vec = GetSchemaValue<CUtlVector<GCompMatPropertyMutator_t>*>(m_ptr, "CompMatPropertyMutator_t", "m_vecConditionalMutators"); std::vector<GCompMatPropertyMutator_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetConditionalMutators(std::vector<GCompMatPropertyMutator_t> value) { SetSchemaValueCUtlVector<GCompMatPropertyMutator_t>(m_ptr, "CompMatPropertyMutator_t", "m_vecConditionalMutators", true, value); }
    CUtlString GetStrPopInputQueue_Container() const { return GetSchemaValue<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_strPopInputQueue_Container"); }
    void SetStrPopInputQueue_Container(CUtlString value) { SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_strPopInputQueue_Container", true, value); }
    CUtlString GetStrDrawText_InputContainerSrc() const { return GetSchemaValue<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_strDrawText_InputContainerSrc"); }
    void SetStrDrawText_InputContainerSrc(CUtlString value) { SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_strDrawText_InputContainerSrc", true, value); }
    CUtlString GetStrDrawText_InputContainerProperty() const { return GetSchemaValue<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_strDrawText_InputContainerProperty"); }
    void SetStrDrawText_InputContainerProperty(CUtlString value) { SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_strDrawText_InputContainerProperty", true, value); }
    Vector2D GetDrawText_Position() const { return GetSchemaValue<Vector2D>(m_ptr, "CompMatPropertyMutator_t", "m_vecDrawText_Position"); }
    void SetDrawText_Position(Vector2D value) { SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_vecDrawText_Position", true, value); }
    Color GetColDrawText_Color() const { return GetSchemaValue<Color>(m_ptr, "CompMatPropertyMutator_t", "m_colDrawText_Color"); }
    void SetColDrawText_Color(Color value) { SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_colDrawText_Color", true, value); }
    CUtlString GetStrDrawText_Font() const { return GetSchemaValue<CUtlString>(m_ptr, "CompMatPropertyMutator_t", "m_strDrawText_Font"); }
    void SetStrDrawText_Font(CUtlString value) { SetSchemaValue(m_ptr, "CompMatPropertyMutator_t", "m_strDrawText_Font", true, value); }
    std::vector<GCompMatMutatorCondition_t> GetConditions() const { CUtlVector<GCompMatMutatorCondition_t>* vec = GetSchemaValue<CUtlVector<GCompMatMutatorCondition_t>*>(m_ptr, "CompMatPropertyMutator_t", "m_vecConditions"); std::vector<GCompMatMutatorCondition_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetConditions(std::vector<GCompMatMutatorCondition_t> value) { SetSchemaValueCUtlVector<GCompMatMutatorCondition_t>(m_ptr, "CompMatPropertyMutator_t", "m_vecConditions", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif