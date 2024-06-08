class Gsndopvarlatchdata_t;

#ifndef _gcsndopvarlatchdata_t_h
#define _gcsndopvarlatchdata_t_h

#include "../../../scripting.h"




class Gsndopvarlatchdata_t
{
private:
    void *m_ptr;

public:
    Gsndopvarlatchdata_t() {}
    Gsndopvarlatchdata_t(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetStack() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "sndopvarlatchdata_t", "m_iszStack"); }
    void SetStack(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "sndopvarlatchdata_t", "m_iszStack", true, value); }
    CUtlSymbolLarge GetOperator() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "sndopvarlatchdata_t", "m_iszOperator"); }
    void SetOperator(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "sndopvarlatchdata_t", "m_iszOperator", true, value); }
    CUtlSymbolLarge GetOpvar() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "sndopvarlatchdata_t", "m_iszOpvar"); }
    void SetOpvar(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "sndopvarlatchdata_t", "m_iszOpvar", true, value); }
    float GetVal() const { return GetSchemaValue<float>(m_ptr, "sndopvarlatchdata_t", "m_flVal"); }
    void SetVal(float value) { SetSchemaValue(m_ptr, "sndopvarlatchdata_t", "m_flVal", true, value); }
    Vector GetPos() const { return GetSchemaValue<Vector>(m_ptr, "sndopvarlatchdata_t", "m_vPos"); }
    void SetPos(Vector value) { SetSchemaValue(m_ptr, "sndopvarlatchdata_t", "m_vPos", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif