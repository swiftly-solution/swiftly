class GCFuncElectrifiedVolume;

#ifndef _gccfuncelectrifiedvolume_h
#define _gccfuncelectrifiedvolume_h

#include "../../../scripting.h"




class GCFuncElectrifiedVolume
{
private:
    void *m_ptr;

public:
    GCFuncElectrifiedVolume() {}
    GCFuncElectrifiedVolume(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetEffectName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncElectrifiedVolume", "m_EffectName"); }
    void SetEffectName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFuncElectrifiedVolume", "m_EffectName", false, value); }
    CUtlSymbolLarge GetEffectInterpenetrateName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncElectrifiedVolume", "m_EffectInterpenetrateName"); }
    void SetEffectInterpenetrateName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFuncElectrifiedVolume", "m_EffectInterpenetrateName", false, value); }
    CUtlSymbolLarge GetEffectZapName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncElectrifiedVolume", "m_EffectZapName"); }
    void SetEffectZapName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFuncElectrifiedVolume", "m_EffectZapName", false, value); }
    CUtlSymbolLarge GetEffectSource() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncElectrifiedVolume", "m_iszEffectSource"); }
    void SetEffectSource(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFuncElectrifiedVolume", "m_iszEffectSource", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif