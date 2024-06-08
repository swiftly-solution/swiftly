class GC_OP_SetControlPointsToModelParticles;

#ifndef _gcc_op_setcontrolpointstomodelparticles_h
#define _gcc_op_setcontrolpointstomodelparticles_h

#include "../../../scripting.h"




class GC_OP_SetControlPointsToModelParticles
{
private:
    void *m_ptr;

public:
    GC_OP_SetControlPointsToModelParticles() {}
    GC_OP_SetControlPointsToModelParticles(void *ptr) : m_ptr(ptr) {}

    std::string GetHitboxSetName() const { return GetSchemaValue<char*>(m_ptr, "C_OP_SetControlPointsToModelParticles", "m_HitboxSetName"); }
    void SetHitboxSetName(std::string value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointsToModelParticles", "m_HitboxSetName", false, value); }
    std::string GetAttachmentName() const { return GetSchemaValue<char*>(m_ptr, "C_OP_SetControlPointsToModelParticles", "m_AttachmentName"); }
    void SetAttachmentName(std::string value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointsToModelParticles", "m_AttachmentName", false, value); }
    int32_t GetFirstControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointsToModelParticles", "m_nFirstControlPoint"); }
    void SetFirstControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointsToModelParticles", "m_nFirstControlPoint", false, value); }
    int32_t GetNumControlPoints() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointsToModelParticles", "m_nNumControlPoints"); }
    void SetNumControlPoints(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointsToModelParticles", "m_nNumControlPoints", false, value); }
    int32_t GetFirstSourcePoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointsToModelParticles", "m_nFirstSourcePoint"); }
    void SetFirstSourcePoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointsToModelParticles", "m_nFirstSourcePoint", false, value); }
    bool GetSkin() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetControlPointsToModelParticles", "m_bSkin"); }
    void SetSkin(bool value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointsToModelParticles", "m_bSkin", false, value); }
    bool GetAttachment() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetControlPointsToModelParticles", "m_bAttachment"); }
    void SetAttachment(bool value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointsToModelParticles", "m_bAttachment", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif