class GC_OP_SnapshotSkinToBones;

#ifndef _gcc_op_snapshotskintobones_h
#define _gcc_op_snapshotskintobones_h

#include "../../../scripting.h"




class GC_OP_SnapshotSkinToBones
{
private:
    void *m_ptr;

public:
    GC_OP_SnapshotSkinToBones() {}
    GC_OP_SnapshotSkinToBones(void *ptr) : m_ptr(ptr) {}

    bool GetTransformNormals() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SnapshotSkinToBones", "m_bTransformNormals"); }
    void SetTransformNormals(bool value) { SetSchemaValue(m_ptr, "C_OP_SnapshotSkinToBones", "m_bTransformNormals", false, value); }
    bool GetTransformRadii() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SnapshotSkinToBones", "m_bTransformRadii"); }
    void SetTransformRadii(bool value) { SetSchemaValue(m_ptr, "C_OP_SnapshotSkinToBones", "m_bTransformRadii", false, value); }
    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SnapshotSkinToBones", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SnapshotSkinToBones", "m_nControlPointNumber", false, value); }
    float GetLifeTimeFadeStart() const { return GetSchemaValue<float>(m_ptr, "C_OP_SnapshotSkinToBones", "m_flLifeTimeFadeStart"); }
    void SetLifeTimeFadeStart(float value) { SetSchemaValue(m_ptr, "C_OP_SnapshotSkinToBones", "m_flLifeTimeFadeStart", false, value); }
    float GetLifeTimeFadeEnd() const { return GetSchemaValue<float>(m_ptr, "C_OP_SnapshotSkinToBones", "m_flLifeTimeFadeEnd"); }
    void SetLifeTimeFadeEnd(float value) { SetSchemaValue(m_ptr, "C_OP_SnapshotSkinToBones", "m_flLifeTimeFadeEnd", false, value); }
    float GetJumpThreshold() const { return GetSchemaValue<float>(m_ptr, "C_OP_SnapshotSkinToBones", "m_flJumpThreshold"); }
    void SetJumpThreshold(float value) { SetSchemaValue(m_ptr, "C_OP_SnapshotSkinToBones", "m_flJumpThreshold", false, value); }
    float GetPrevPosScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_SnapshotSkinToBones", "m_flPrevPosScale"); }
    void SetPrevPosScale(float value) { SetSchemaValue(m_ptr, "C_OP_SnapshotSkinToBones", "m_flPrevPosScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif