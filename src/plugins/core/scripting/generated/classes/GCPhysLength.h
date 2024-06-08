class GCPhysLength;

#ifndef _gccphyslength_h
#define _gccphyslength_h

#include "../../../scripting.h"




class GCPhysLength
{
private:
    void *m_ptr;

public:
    GCPhysLength() {}
    GCPhysLength(void *ptr) : m_ptr(ptr) {}

    std::vector<Vector> GetOffset() const { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CPhysLength", "m_offset"); std::vector<Vector> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetOffset(std::vector<Vector> value) { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CPhysLength", "m_offset"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CPhysLength", "m_offset", false, outValue); }
    Vector GetAttach() const { return GetSchemaValue<Vector>(m_ptr, "CPhysLength", "m_vecAttach"); }
    void SetAttach(Vector value) { SetSchemaValue(m_ptr, "CPhysLength", "m_vecAttach", false, value); }
    float GetAddLength() const { return GetSchemaValue<float>(m_ptr, "CPhysLength", "m_addLength"); }
    void SetAddLength(float value) { SetSchemaValue(m_ptr, "CPhysLength", "m_addLength", false, value); }
    float GetMinLength() const { return GetSchemaValue<float>(m_ptr, "CPhysLength", "m_minLength"); }
    void SetMinLength(float value) { SetSchemaValue(m_ptr, "CPhysLength", "m_minLength", false, value); }
    float GetTotalLength() const { return GetSchemaValue<float>(m_ptr, "CPhysLength", "m_totalLength"); }
    void SetTotalLength(float value) { SetSchemaValue(m_ptr, "CPhysLength", "m_totalLength", false, value); }
    bool GetEnableCollision() const { return GetSchemaValue<bool>(m_ptr, "CPhysLength", "m_bEnableCollision"); }
    void SetEnableCollision(bool value) { SetSchemaValue(m_ptr, "CPhysLength", "m_bEnableCollision", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif