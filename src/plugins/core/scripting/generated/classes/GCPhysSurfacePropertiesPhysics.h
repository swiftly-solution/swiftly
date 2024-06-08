class GCPhysSurfacePropertiesPhysics;

#ifndef _gccphyssurfacepropertiesphysics_h
#define _gccphyssurfacepropertiesphysics_h

#include "../../../scripting.h"




class GCPhysSurfacePropertiesPhysics
{
private:
    void *m_ptr;

public:
    GCPhysSurfacePropertiesPhysics() {}
    GCPhysSurfacePropertiesPhysics(void *ptr) : m_ptr(ptr) {}

    float GetFriction() const { return GetSchemaValue<float>(m_ptr, "CPhysSurfacePropertiesPhysics", "m_friction"); }
    void SetFriction(float value) { SetSchemaValue(m_ptr, "CPhysSurfacePropertiesPhysics", "m_friction", false, value); }
    float GetElasticity() const { return GetSchemaValue<float>(m_ptr, "CPhysSurfacePropertiesPhysics", "m_elasticity"); }
    void SetElasticity(float value) { SetSchemaValue(m_ptr, "CPhysSurfacePropertiesPhysics", "m_elasticity", false, value); }
    float GetDensity() const { return GetSchemaValue<float>(m_ptr, "CPhysSurfacePropertiesPhysics", "m_density"); }
    void SetDensity(float value) { SetSchemaValue(m_ptr, "CPhysSurfacePropertiesPhysics", "m_density", false, value); }
    float GetThickness() const { return GetSchemaValue<float>(m_ptr, "CPhysSurfacePropertiesPhysics", "m_thickness"); }
    void SetThickness(float value) { SetSchemaValue(m_ptr, "CPhysSurfacePropertiesPhysics", "m_thickness", false, value); }
    float GetSoftContactFrequency() const { return GetSchemaValue<float>(m_ptr, "CPhysSurfacePropertiesPhysics", "m_softContactFrequency"); }
    void SetSoftContactFrequency(float value) { SetSchemaValue(m_ptr, "CPhysSurfacePropertiesPhysics", "m_softContactFrequency", false, value); }
    float GetSoftContactDampingRatio() const { return GetSchemaValue<float>(m_ptr, "CPhysSurfacePropertiesPhysics", "m_softContactDampingRatio"); }
    void SetSoftContactDampingRatio(float value) { SetSchemaValue(m_ptr, "CPhysSurfacePropertiesPhysics", "m_softContactDampingRatio", false, value); }
    float GetWheelDrag() const { return GetSchemaValue<float>(m_ptr, "CPhysSurfacePropertiesPhysics", "m_wheelDrag"); }
    void SetWheelDrag(float value) { SetSchemaValue(m_ptr, "CPhysSurfacePropertiesPhysics", "m_wheelDrag", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif