class GEntitySpottedState_t;

#ifndef _gcentityspottedstate_t_h
#define _gcentityspottedstate_t_h

#include "../../../scripting.h"




class GEntitySpottedState_t
{
private:
    void *m_ptr;

public:
    GEntitySpottedState_t() {}
    GEntitySpottedState_t(void *ptr) : m_ptr(ptr) {}

    bool GetSpotted() const { return GetSchemaValue<bool>(m_ptr, "EntitySpottedState_t", "m_bSpotted"); }
    void SetSpotted(bool value) { SetSchemaValue(m_ptr, "EntitySpottedState_t", "m_bSpotted", true, value); }
    std::vector<uint32_t> GetSpottedByMask() const { uint32_t* outValue = GetSchemaValue<uint32_t*>(m_ptr, "EntitySpottedState_t", "m_bSpottedByMask"); std::vector<uint32_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetSpottedByMask(std::vector<uint32_t> value) { uint32_t* outValue = GetSchemaValue<uint32_t*>(m_ptr, "EntitySpottedState_t", "m_bSpottedByMask"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "EntitySpottedState_t", "m_bSpottedByMask", true, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif