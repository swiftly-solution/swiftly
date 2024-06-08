class GC_OP_TeleportBeam;

#ifndef _gcc_op_teleportbeam_h
#define _gcc_op_teleportbeam_h

#include "../../../scripting.h"




class GC_OP_TeleportBeam
{
private:
    void *m_ptr;

public:
    GC_OP_TeleportBeam() {}
    GC_OP_TeleportBeam(void *ptr) : m_ptr(ptr) {}

    int32_t GetCPPosition() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_TeleportBeam", "m_nCPPosition"); }
    void SetCPPosition(int32_t value) { SetSchemaValue(m_ptr, "C_OP_TeleportBeam", "m_nCPPosition", false, value); }
    int32_t GetCPVelocity() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_TeleportBeam", "m_nCPVelocity"); }
    void SetCPVelocity(int32_t value) { SetSchemaValue(m_ptr, "C_OP_TeleportBeam", "m_nCPVelocity", false, value); }
    int32_t GetCPMisc() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_TeleportBeam", "m_nCPMisc"); }
    void SetCPMisc(int32_t value) { SetSchemaValue(m_ptr, "C_OP_TeleportBeam", "m_nCPMisc", false, value); }
    int32_t GetCPColor() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_TeleportBeam", "m_nCPColor"); }
    void SetCPColor(int32_t value) { SetSchemaValue(m_ptr, "C_OP_TeleportBeam", "m_nCPColor", false, value); }
    int32_t GetCPInvalidColor() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_TeleportBeam", "m_nCPInvalidColor"); }
    void SetCPInvalidColor(int32_t value) { SetSchemaValue(m_ptr, "C_OP_TeleportBeam", "m_nCPInvalidColor", false, value); }
    int32_t GetCPExtraArcData() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_TeleportBeam", "m_nCPExtraArcData"); }
    void SetCPExtraArcData(int32_t value) { SetSchemaValue(m_ptr, "C_OP_TeleportBeam", "m_nCPExtraArcData", false, value); }
    Vector GetGravity() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_TeleportBeam", "m_vGravity"); }
    void SetGravity(Vector value) { SetSchemaValue(m_ptr, "C_OP_TeleportBeam", "m_vGravity", false, value); }
    float GetArcMaxDuration() const { return GetSchemaValue<float>(m_ptr, "C_OP_TeleportBeam", "m_flArcMaxDuration"); }
    void SetArcMaxDuration(float value) { SetSchemaValue(m_ptr, "C_OP_TeleportBeam", "m_flArcMaxDuration", false, value); }
    float GetSegmentBreak() const { return GetSchemaValue<float>(m_ptr, "C_OP_TeleportBeam", "m_flSegmentBreak"); }
    void SetSegmentBreak(float value) { SetSchemaValue(m_ptr, "C_OP_TeleportBeam", "m_flSegmentBreak", false, value); }
    float GetArcSpeed() const { return GetSchemaValue<float>(m_ptr, "C_OP_TeleportBeam", "m_flArcSpeed"); }
    void SetArcSpeed(float value) { SetSchemaValue(m_ptr, "C_OP_TeleportBeam", "m_flArcSpeed", false, value); }
    float GetAlpha() const { return GetSchemaValue<float>(m_ptr, "C_OP_TeleportBeam", "m_flAlpha"); }
    void SetAlpha(float value) { SetSchemaValue(m_ptr, "C_OP_TeleportBeam", "m_flAlpha", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif