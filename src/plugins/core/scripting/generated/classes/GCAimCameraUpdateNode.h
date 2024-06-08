class GCAimCameraUpdateNode;

#ifndef _gccaimcameraupdatenode_h
#define _gccaimcameraupdatenode_h

#include "../../../scripting.h"


#include "GCAnimParamHandle.h"
#include "GAimCameraOpFixedSettings_t.h"

class GCAimCameraUpdateNode
{
private:
    void *m_ptr;

public:
    GCAimCameraUpdateNode() {}
    GCAimCameraUpdateNode(void *ptr) : m_ptr(ptr) {}

    GCAnimParamHandle GetParameterPosition() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CAimCameraUpdateNode", "m_hParameterPosition"); }
    void SetParameterPosition(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CAimCameraUpdateNode", "m_hParameterPosition", false, value); }
    GCAnimParamHandle GetParameterOrientation() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CAimCameraUpdateNode", "m_hParameterOrientation"); }
    void SetParameterOrientation(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CAimCameraUpdateNode", "m_hParameterOrientation", false, value); }
    GCAnimParamHandle GetParameterSpineRotationWeight() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CAimCameraUpdateNode", "m_hParameterSpineRotationWeight"); }
    void SetParameterSpineRotationWeight(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CAimCameraUpdateNode", "m_hParameterSpineRotationWeight", false, value); }
    GCAnimParamHandle GetParameterPelvisOffset() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CAimCameraUpdateNode", "m_hParameterPelvisOffset"); }
    void SetParameterPelvisOffset(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CAimCameraUpdateNode", "m_hParameterPelvisOffset", false, value); }
    GCAnimParamHandle GetParameterUseIK() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CAimCameraUpdateNode", "m_hParameterUseIK"); }
    void SetParameterUseIK(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CAimCameraUpdateNode", "m_hParameterUseIK", false, value); }
    GCAnimParamHandle GetParameterWeaponDepenetrationDistance() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CAimCameraUpdateNode", "m_hParameterWeaponDepenetrationDistance"); }
    void SetParameterWeaponDepenetrationDistance(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CAimCameraUpdateNode", "m_hParameterWeaponDepenetrationDistance", false, value); }
    GCAnimParamHandle GetParameterCameraClearanceDistance() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CAimCameraUpdateNode", "m_hParameterCameraClearanceDistance"); }
    void SetParameterCameraClearanceDistance(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CAimCameraUpdateNode", "m_hParameterCameraClearanceDistance", false, value); }
    GAimCameraOpFixedSettings_t GetOpFixedSettings() const { return GetSchemaValue<GAimCameraOpFixedSettings_t>(m_ptr, "CAimCameraUpdateNode", "m_opFixedSettings"); }
    void SetOpFixedSettings(GAimCameraOpFixedSettings_t value) { SetSchemaValue(m_ptr, "CAimCameraUpdateNode", "m_opFixedSettings", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif