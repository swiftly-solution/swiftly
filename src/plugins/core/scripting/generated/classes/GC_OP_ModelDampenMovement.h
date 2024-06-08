class GC_OP_ModelDampenMovement;

#ifndef _gcc_op_modeldampenmovement_h
#define _gcc_op_modeldampenmovement_h

#include "../../../scripting.h"


#include "GCPerParticleVecInput.h"

class GC_OP_ModelDampenMovement
{
private:
    void *m_ptr;

public:
    GC_OP_ModelDampenMovement() {}
    GC_OP_ModelDampenMovement(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_ModelDampenMovement", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_ModelDampenMovement", "m_nControlPointNumber", false, value); }
    bool GetBoundBox() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ModelDampenMovement", "m_bBoundBox"); }
    void SetBoundBox(bool value) { SetSchemaValue(m_ptr, "C_OP_ModelDampenMovement", "m_bBoundBox", false, value); }
    bool GetOutside() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ModelDampenMovement", "m_bOutside"); }
    void SetOutside(bool value) { SetSchemaValue(m_ptr, "C_OP_ModelDampenMovement", "m_bOutside", false, value); }
    bool GetUseBones() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ModelDampenMovement", "m_bUseBones"); }
    void SetUseBones(bool value) { SetSchemaValue(m_ptr, "C_OP_ModelDampenMovement", "m_bUseBones", false, value); }
    std::string GetHitboxSetName() const { return GetSchemaValue<char*>(m_ptr, "C_OP_ModelDampenMovement", "m_HitboxSetName"); }
    void SetHitboxSetName(std::string value) { SetSchemaValue(m_ptr, "C_OP_ModelDampenMovement", "m_HitboxSetName", false, value); }
    GCPerParticleVecInput GetPosOffset() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_ModelDampenMovement", "m_vecPosOffset"); }
    void SetPosOffset(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_ModelDampenMovement", "m_vecPosOffset", false, value); }
    float GetDrag() const { return GetSchemaValue<float>(m_ptr, "C_OP_ModelDampenMovement", "m_fDrag"); }
    void SetDrag(float value) { SetSchemaValue(m_ptr, "C_OP_ModelDampenMovement", "m_fDrag", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif