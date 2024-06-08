class GSoundOpvarTraceResult_t;

#ifndef _gcsoundopvartraceresult_t_h
#define _gcsoundopvartraceresult_t_h

#include "../../../scripting.h"




class GSoundOpvarTraceResult_t
{
private:
    void *m_ptr;

public:
    GSoundOpvarTraceResult_t() {}
    GSoundOpvarTraceResult_t(void *ptr) : m_ptr(ptr) {}

    Vector GetPos() const { return GetSchemaValue<Vector>(m_ptr, "SoundOpvarTraceResult_t", "vPos"); }
    void SetPos(Vector value) { SetSchemaValue(m_ptr, "SoundOpvarTraceResult_t", "vPos", true, value); }
    bool GetDidHit() const { return GetSchemaValue<bool>(m_ptr, "SoundOpvarTraceResult_t", "bDidHit"); }
    void SetDidHit(bool value) { SetSchemaValue(m_ptr, "SoundOpvarTraceResult_t", "bDidHit", true, value); }
    float GetDistSqrToCenter() const { return GetSchemaValue<float>(m_ptr, "SoundOpvarTraceResult_t", "flDistSqrToCenter"); }
    void SetDistSqrToCenter(float value) { SetSchemaValue(m_ptr, "SoundOpvarTraceResult_t", "flDistSqrToCenter", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif