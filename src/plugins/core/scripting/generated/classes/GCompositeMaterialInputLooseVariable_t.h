class GCompositeMaterialInputLooseVariable_t;

#ifndef _gccompositematerialinputloosevariable_t_h
#define _gccompositematerialinputloosevariable_t_h

#include "../../../scripting.h"

#include "../types/GCompositeMaterialInputLooseVariableType_t.h"
#include "../types/GCompositeMaterialVarSystemVar_t.h"
#include "../types/GCompositeMaterialInputTextureType_t.h"


class GCompositeMaterialInputLooseVariable_t
{
private:
    void *m_ptr;

public:
    GCompositeMaterialInputLooseVariable_t() {}
    GCompositeMaterialInputLooseVariable_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetStrName() const { return GetSchemaValue<CUtlString>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strName"); }
    void SetStrName(CUtlString value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strName", true, value); }
    bool GetExposeExternally() const { return GetSchemaValue<bool>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_bExposeExternally"); }
    void SetExposeExternally(bool value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_bExposeExternally", true, value); }
    CUtlString GetStrExposedFriendlyName() const { return GetSchemaValue<CUtlString>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strExposedFriendlyName"); }
    void SetStrExposedFriendlyName(CUtlString value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strExposedFriendlyName", true, value); }
    CUtlString GetStrExposedFriendlyGroupName() const { return GetSchemaValue<CUtlString>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strExposedFriendlyGroupName"); }
    void SetStrExposedFriendlyGroupName(CUtlString value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strExposedFriendlyGroupName", true, value); }
    bool GetExposedVariableIsFixedRange() const { return GetSchemaValue<bool>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_bExposedVariableIsFixedRange"); }
    void SetExposedVariableIsFixedRange(bool value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_bExposedVariableIsFixedRange", true, value); }
    CUtlString GetStrExposedVisibleWhenTrue() const { return GetSchemaValue<CUtlString>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strExposedVisibleWhenTrue"); }
    void SetStrExposedVisibleWhenTrue(CUtlString value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strExposedVisibleWhenTrue", true, value); }
    CUtlString GetStrExposedHiddenWhenTrue() const { return GetSchemaValue<CUtlString>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strExposedHiddenWhenTrue"); }
    void SetStrExposedHiddenWhenTrue(CUtlString value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strExposedHiddenWhenTrue", true, value); }
    CompositeMaterialInputLooseVariableType_t GetVariableType() const { return GetSchemaValue<CompositeMaterialInputLooseVariableType_t>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nVariableType"); }
    void SetVariableType(CompositeMaterialInputLooseVariableType_t value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nVariableType", true, value); }
    bool GetValueBoolean() const { return GetSchemaValue<bool>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_bValueBoolean"); }
    void SetValueBoolean(bool value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_bValueBoolean", true, value); }
    int32_t GetValueIntX() const { return GetSchemaValue<int32_t>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nValueIntX"); }
    void SetValueIntX(int32_t value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nValueIntX", true, value); }
    int32_t GetValueIntY() const { return GetSchemaValue<int32_t>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nValueIntY"); }
    void SetValueIntY(int32_t value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nValueIntY", true, value); }
    int32_t GetValueIntZ() const { return GetSchemaValue<int32_t>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nValueIntZ"); }
    void SetValueIntZ(int32_t value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nValueIntZ", true, value); }
    int32_t GetValueIntW() const { return GetSchemaValue<int32_t>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nValueIntW"); }
    void SetValueIntW(int32_t value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nValueIntW", true, value); }
    bool GetHasFloatBounds() const { return GetSchemaValue<bool>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_bHasFloatBounds"); }
    void SetHasFloatBounds(bool value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_bHasFloatBounds", true, value); }
    float GetValueFloatX() const { return GetSchemaValue<float>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatX"); }
    void SetValueFloatX(float value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatX", true, value); }
    float GetValueFloatX_Min() const { return GetSchemaValue<float>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatX_Min"); }
    void SetValueFloatX_Min(float value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatX_Min", true, value); }
    float GetValueFloatX_Max() const { return GetSchemaValue<float>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatX_Max"); }
    void SetValueFloatX_Max(float value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatX_Max", true, value); }
    float GetValueFloatY() const { return GetSchemaValue<float>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatY"); }
    void SetValueFloatY(float value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatY", true, value); }
    float GetValueFloatY_Min() const { return GetSchemaValue<float>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatY_Min"); }
    void SetValueFloatY_Min(float value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatY_Min", true, value); }
    float GetValueFloatY_Max() const { return GetSchemaValue<float>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatY_Max"); }
    void SetValueFloatY_Max(float value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatY_Max", true, value); }
    float GetValueFloatZ() const { return GetSchemaValue<float>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatZ"); }
    void SetValueFloatZ(float value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatZ", true, value); }
    float GetValueFloatZ_Min() const { return GetSchemaValue<float>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatZ_Min"); }
    void SetValueFloatZ_Min(float value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatZ_Min", true, value); }
    float GetValueFloatZ_Max() const { return GetSchemaValue<float>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatZ_Max"); }
    void SetValueFloatZ_Max(float value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatZ_Max", true, value); }
    float GetValueFloatW() const { return GetSchemaValue<float>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatW"); }
    void SetValueFloatW(float value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatW", true, value); }
    float GetValueFloatW_Min() const { return GetSchemaValue<float>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatW_Min"); }
    void SetValueFloatW_Min(float value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatW_Min", true, value); }
    float GetValueFloatW_Max() const { return GetSchemaValue<float>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatW_Max"); }
    void SetValueFloatW_Max(float value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatW_Max", true, value); }
    Color GetCValueColor4() const { return GetSchemaValue<Color>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_cValueColor4"); }
    void SetCValueColor4(Color value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_cValueColor4", true, value); }
    CompositeMaterialVarSystemVar_t GetValueSystemVar() const { return GetSchemaValue<CompositeMaterialVarSystemVar_t>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nValueSystemVar"); }
    void SetValueSystemVar(CompositeMaterialVarSystemVar_t value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nValueSystemVar", true, value); }
    CUtlString GetStrTextureContentAssetPath() const { return GetSchemaValue<CUtlString>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strTextureContentAssetPath"); }
    void SetStrTextureContentAssetPath(CUtlString value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strTextureContentAssetPath", true, value); }
    CUtlString GetStrTextureCompilationVtexTemplate() const { return GetSchemaValue<CUtlString>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strTextureCompilationVtexTemplate"); }
    void SetStrTextureCompilationVtexTemplate(CUtlString value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strTextureCompilationVtexTemplate", true, value); }
    CompositeMaterialInputTextureType_t GetTextureType() const { return GetSchemaValue<CompositeMaterialInputTextureType_t>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nTextureType"); }
    void SetTextureType(CompositeMaterialInputTextureType_t value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nTextureType", true, value); }
    CUtlString GetStrString() const { return GetSchemaValue<CUtlString>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strString"); }
    void SetStrString(CUtlString value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strString", true, value); }
    CUtlString GetStrPanoramaPanelPath() const { return GetSchemaValue<CUtlString>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strPanoramaPanelPath"); }
    void SetStrPanoramaPanelPath(CUtlString value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strPanoramaPanelPath", true, value); }
    int32_t GetPanoramaRenderRes() const { return GetSchemaValue<int32_t>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nPanoramaRenderRes"); }
    void SetPanoramaRenderRes(int32_t value) { SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nPanoramaRenderRes", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif