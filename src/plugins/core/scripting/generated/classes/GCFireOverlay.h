class GCFireOverlay;

#ifndef _gccfireoverlay_h
#define _gccfireoverlay_h

#include "../../../scripting.h"




class GCFireOverlay
{
private:
    void *m_ptr;

public:
    GCFireOverlay() {}
    GCFireOverlay(void *ptr) : m_ptr(ptr) {}

    std::vector<Vector> GetBaseColors() const { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CFireOverlay", "m_vBaseColors"); std::vector<Vector> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetBaseColors(std::vector<Vector> value) { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CFireOverlay", "m_vBaseColors"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CFireOverlay", "m_vBaseColors", false, outValue); }
    float GetScale() const { return GetSchemaValue<float>(m_ptr, "CFireOverlay", "m_flScale"); }
    void SetScale(float value) { SetSchemaValue(m_ptr, "CFireOverlay", "m_flScale", false, value); }
    int32_t GetGUID() const { return GetSchemaValue<int32_t>(m_ptr, "CFireOverlay", "m_nGUID"); }
    void SetGUID(int32_t value) { SetSchemaValue(m_ptr, "CFireOverlay", "m_nGUID", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif