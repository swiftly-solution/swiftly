class Gfogplayerparams_t;

#ifndef _gcfogplayerparams_t_h
#define _gcfogplayerparams_t_h

#include "../../../scripting.h"


#include "GCFogController.h"

class Gfogplayerparams_t
{
private:
    void *m_ptr;

public:
    Gfogplayerparams_t() {}
    Gfogplayerparams_t(void *ptr) : m_ptr(ptr) {}

    GCFogController* GetCtrl() const { return GetSchemaValue<GCFogController*>(m_ptr, "fogplayerparams_t", "m_hCtrl"); }
    void SetCtrl(GCFogController* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Ctrl' is not possible.\n"); }
    float GetTransitionTime() const { return GetSchemaValue<float>(m_ptr, "fogplayerparams_t", "m_flTransitionTime"); }
    void SetTransitionTime(float value) { SetSchemaValue(m_ptr, "fogplayerparams_t", "m_flTransitionTime", true, value); }
    Color GetOldColor() const { return GetSchemaValue<Color>(m_ptr, "fogplayerparams_t", "m_OldColor"); }
    void SetOldColor(Color value) { SetSchemaValue(m_ptr, "fogplayerparams_t", "m_OldColor", true, value); }
    float GetOldStart() const { return GetSchemaValue<float>(m_ptr, "fogplayerparams_t", "m_flOldStart"); }
    void SetOldStart(float value) { SetSchemaValue(m_ptr, "fogplayerparams_t", "m_flOldStart", true, value); }
    float GetOldEnd() const { return GetSchemaValue<float>(m_ptr, "fogplayerparams_t", "m_flOldEnd"); }
    void SetOldEnd(float value) { SetSchemaValue(m_ptr, "fogplayerparams_t", "m_flOldEnd", true, value); }
    float GetOldMaxDensity() const { return GetSchemaValue<float>(m_ptr, "fogplayerparams_t", "m_flOldMaxDensity"); }
    void SetOldMaxDensity(float value) { SetSchemaValue(m_ptr, "fogplayerparams_t", "m_flOldMaxDensity", true, value); }
    float GetOldHDRColorScale() const { return GetSchemaValue<float>(m_ptr, "fogplayerparams_t", "m_flOldHDRColorScale"); }
    void SetOldHDRColorScale(float value) { SetSchemaValue(m_ptr, "fogplayerparams_t", "m_flOldHDRColorScale", true, value); }
    float GetOldFarZ() const { return GetSchemaValue<float>(m_ptr, "fogplayerparams_t", "m_flOldFarZ"); }
    void SetOldFarZ(float value) { SetSchemaValue(m_ptr, "fogplayerparams_t", "m_flOldFarZ", true, value); }
    Color GetNewColor() const { return GetSchemaValue<Color>(m_ptr, "fogplayerparams_t", "m_NewColor"); }
    void SetNewColor(Color value) { SetSchemaValue(m_ptr, "fogplayerparams_t", "m_NewColor", true, value); }
    float GetNewStart() const { return GetSchemaValue<float>(m_ptr, "fogplayerparams_t", "m_flNewStart"); }
    void SetNewStart(float value) { SetSchemaValue(m_ptr, "fogplayerparams_t", "m_flNewStart", true, value); }
    float GetNewEnd() const { return GetSchemaValue<float>(m_ptr, "fogplayerparams_t", "m_flNewEnd"); }
    void SetNewEnd(float value) { SetSchemaValue(m_ptr, "fogplayerparams_t", "m_flNewEnd", true, value); }
    float GetNewMaxDensity() const { return GetSchemaValue<float>(m_ptr, "fogplayerparams_t", "m_flNewMaxDensity"); }
    void SetNewMaxDensity(float value) { SetSchemaValue(m_ptr, "fogplayerparams_t", "m_flNewMaxDensity", true, value); }
    float GetNewHDRColorScale() const { return GetSchemaValue<float>(m_ptr, "fogplayerparams_t", "m_flNewHDRColorScale"); }
    void SetNewHDRColorScale(float value) { SetSchemaValue(m_ptr, "fogplayerparams_t", "m_flNewHDRColorScale", true, value); }
    float GetNewFarZ() const { return GetSchemaValue<float>(m_ptr, "fogplayerparams_t", "m_flNewFarZ"); }
    void SetNewFarZ(float value) { SetSchemaValue(m_ptr, "fogplayerparams_t", "m_flNewFarZ", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif