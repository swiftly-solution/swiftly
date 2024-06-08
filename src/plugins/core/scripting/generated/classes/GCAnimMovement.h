class GCAnimMovement;

#ifndef _gccanimmovement_h
#define _gccanimmovement_h

#include "../../../scripting.h"




class GCAnimMovement
{
private:
    void *m_ptr;

public:
    GCAnimMovement() {}
    GCAnimMovement(void *ptr) : m_ptr(ptr) {}

    int32_t GetEndframe() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimMovement", "endframe"); }
    void SetEndframe(int32_t value) { SetSchemaValue(m_ptr, "CAnimMovement", "endframe", false, value); }
    int32_t GetMotionflags() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimMovement", "motionflags"); }
    void SetMotionflags(int32_t value) { SetSchemaValue(m_ptr, "CAnimMovement", "motionflags", false, value); }
    float Get0() const { return GetSchemaValue<float>(m_ptr, "CAnimMovement", "v0"); }
    void Set0(float value) { SetSchemaValue(m_ptr, "CAnimMovement", "v0", false, value); }
    float Get1() const { return GetSchemaValue<float>(m_ptr, "CAnimMovement", "v1"); }
    void Set1(float value) { SetSchemaValue(m_ptr, "CAnimMovement", "v1", false, value); }
    float GetAngle() const { return GetSchemaValue<float>(m_ptr, "CAnimMovement", "angle"); }
    void SetAngle(float value) { SetSchemaValue(m_ptr, "CAnimMovement", "angle", false, value); }
    Vector GetVector() const { return GetSchemaValue<Vector>(m_ptr, "CAnimMovement", "vector"); }
    void SetVector(Vector value) { SetSchemaValue(m_ptr, "CAnimMovement", "vector", false, value); }
    Vector GetPosition() const { return GetSchemaValue<Vector>(m_ptr, "CAnimMovement", "position"); }
    void SetPosition(Vector value) { SetSchemaValue(m_ptr, "CAnimMovement", "position", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif