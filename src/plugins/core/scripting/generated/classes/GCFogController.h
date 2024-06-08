class GCFogController;

#ifndef _gccfogcontroller_h
#define _gccfogcontroller_h

#include "../../../scripting.h"


#include "Gfogparams_t.h"

class GCFogController
{
private:
    void *m_ptr;

public:
    GCFogController() {}
    GCFogController(void *ptr) : m_ptr(ptr) {}

    Gfogparams_t GetFog() const { return GetSchemaValue<Gfogparams_t>(m_ptr, "CFogController", "m_fog"); }
    void SetFog(Gfogparams_t value) { SetSchemaValue(m_ptr, "CFogController", "m_fog", false, value); }
    bool GetUseAngles() const { return GetSchemaValue<bool>(m_ptr, "CFogController", "m_bUseAngles"); }
    void SetUseAngles(bool value) { SetSchemaValue(m_ptr, "CFogController", "m_bUseAngles", false, value); }
    int32_t GetChangedVariables() const { return GetSchemaValue<int32_t>(m_ptr, "CFogController", "m_iChangedVariables"); }
    void SetChangedVariables(int32_t value) { SetSchemaValue(m_ptr, "CFogController", "m_iChangedVariables", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif