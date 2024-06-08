class GCFuncBrush;

#ifndef _gccfuncbrush_h
#define _gccfuncbrush_h

#include "../../../scripting.h"

#include "../types/GBrushSolidities_e.h"


class GCFuncBrush
{
private:
    void *m_ptr;

public:
    GCFuncBrush() {}
    GCFuncBrush(void *ptr) : m_ptr(ptr) {}

    BrushSolidities_e GetSolidity() const { return GetSchemaValue<BrushSolidities_e>(m_ptr, "CFuncBrush", "m_iSolidity"); }
    void SetSolidity(BrushSolidities_e value) { SetSchemaValue(m_ptr, "CFuncBrush", "m_iSolidity", false, value); }
    int32_t GetDisabled() const { return GetSchemaValue<int32_t>(m_ptr, "CFuncBrush", "m_iDisabled"); }
    void SetDisabled(int32_t value) { SetSchemaValue(m_ptr, "CFuncBrush", "m_iDisabled", false, value); }
    bool GetSolidBsp() const { return GetSchemaValue<bool>(m_ptr, "CFuncBrush", "m_bSolidBsp"); }
    void SetSolidBsp(bool value) { SetSchemaValue(m_ptr, "CFuncBrush", "m_bSolidBsp", false, value); }
    CUtlSymbolLarge GetExcludedClass() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncBrush", "m_iszExcludedClass"); }
    void SetExcludedClass(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFuncBrush", "m_iszExcludedClass", false, value); }
    bool GetInvertExclusion() const { return GetSchemaValue<bool>(m_ptr, "CFuncBrush", "m_bInvertExclusion"); }
    void SetInvertExclusion(bool value) { SetSchemaValue(m_ptr, "CFuncBrush", "m_bInvertExclusion", false, value); }
    bool GetScriptedMovement() const { return GetSchemaValue<bool>(m_ptr, "CFuncBrush", "m_bScriptedMovement"); }
    void SetScriptedMovement(bool value) { SetSchemaValue(m_ptr, "CFuncBrush", "m_bScriptedMovement", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif