class GCPhysMagnet;

#ifndef _gccphysmagnet_h
#define _gccphysmagnet_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"
#include "Gmagnetted_objects_t.h"

class GCPhysMagnet
{
private:
    void *m_ptr;

public:
    GCPhysMagnet() {}
    GCPhysMagnet(void *ptr) : m_ptr(ptr) {}

    GCEntityIOOutput GetOnMagnetAttach() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPhysMagnet", "m_OnMagnetAttach"); }
    void SetOnMagnetAttach(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPhysMagnet", "m_OnMagnetAttach", false, value); }
    GCEntityIOOutput GetOnMagnetDetach() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPhysMagnet", "m_OnMagnetDetach"); }
    void SetOnMagnetDetach(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPhysMagnet", "m_OnMagnetDetach", false, value); }
    float GetMassScale() const { return GetSchemaValue<float>(m_ptr, "CPhysMagnet", "m_massScale"); }
    void SetMassScale(float value) { SetSchemaValue(m_ptr, "CPhysMagnet", "m_massScale", false, value); }
    float GetForceLimit() const { return GetSchemaValue<float>(m_ptr, "CPhysMagnet", "m_forceLimit"); }
    void SetForceLimit(float value) { SetSchemaValue(m_ptr, "CPhysMagnet", "m_forceLimit", false, value); }
    float GetTorqueLimit() const { return GetSchemaValue<float>(m_ptr, "CPhysMagnet", "m_torqueLimit"); }
    void SetTorqueLimit(float value) { SetSchemaValue(m_ptr, "CPhysMagnet", "m_torqueLimit", false, value); }
    std::vector<Gmagnetted_objects_t> GetMagnettedEntities() const { CUtlVector<Gmagnetted_objects_t>* vec = GetSchemaValue<CUtlVector<Gmagnetted_objects_t>*>(m_ptr, "CPhysMagnet", "m_MagnettedEntities"); std::vector<Gmagnetted_objects_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetMagnettedEntities(std::vector<Gmagnetted_objects_t> value) { SetSchemaValueCUtlVector<Gmagnetted_objects_t>(m_ptr, "CPhysMagnet", "m_MagnettedEntities", false, value); }
    bool GetActive() const { return GetSchemaValue<bool>(m_ptr, "CPhysMagnet", "m_bActive"); }
    void SetActive(bool value) { SetSchemaValue(m_ptr, "CPhysMagnet", "m_bActive", false, value); }
    bool GetHasHitSomething() const { return GetSchemaValue<bool>(m_ptr, "CPhysMagnet", "m_bHasHitSomething"); }
    void SetHasHitSomething(bool value) { SetSchemaValue(m_ptr, "CPhysMagnet", "m_bHasHitSomething", false, value); }
    float GetTotalMass() const { return GetSchemaValue<float>(m_ptr, "CPhysMagnet", "m_flTotalMass"); }
    void SetTotalMass(float value) { SetSchemaValue(m_ptr, "CPhysMagnet", "m_flTotalMass", false, value); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "CPhysMagnet", "m_flRadius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "CPhysMagnet", "m_flRadius", false, value); }
    int32_t GetMaxObjectsAttached() const { return GetSchemaValue<int32_t>(m_ptr, "CPhysMagnet", "m_iMaxObjectsAttached"); }
    void SetMaxObjectsAttached(int32_t value) { SetSchemaValue(m_ptr, "CPhysMagnet", "m_iMaxObjectsAttached", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif