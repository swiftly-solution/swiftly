class GCHitboxComponent;

#ifndef _gcchitboxcomponent_h
#define _gcchitboxcomponent_h

#include "../../../scripting.h"




class GCHitboxComponent
{
private:
    void *m_ptr;

public:
    GCHitboxComponent() {}
    GCHitboxComponent(void *ptr) : m_ptr(ptr) {}

    std::vector<uint32_t> GetDisabledHitGroups() const { uint32_t* outValue = GetSchemaValue<uint32_t*>(m_ptr, "CHitboxComponent", "m_bvDisabledHitGroups"); std::vector<uint32_t> ret; for(int i = 0; i < 1; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetDisabledHitGroups(std::vector<uint32_t> value) { uint32_t* outValue = GetSchemaValue<uint32_t*>(m_ptr, "CHitboxComponent", "m_bvDisabledHitGroups"); for(int i = 0; i < 1; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CHitboxComponent", "m_bvDisabledHitGroups", false, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif