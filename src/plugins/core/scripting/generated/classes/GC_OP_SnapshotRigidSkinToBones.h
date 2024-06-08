class GC_OP_SnapshotRigidSkinToBones;

#ifndef _gcc_op_snapshotrigidskintobones_h
#define _gcc_op_snapshotrigidskintobones_h

#include "../../../scripting.h"




class GC_OP_SnapshotRigidSkinToBones
{
private:
    void *m_ptr;

public:
    GC_OP_SnapshotRigidSkinToBones() {}
    GC_OP_SnapshotRigidSkinToBones(void *ptr) : m_ptr(ptr) {}

    bool GetTransformNormals() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SnapshotRigidSkinToBones", "m_bTransformNormals"); }
    void SetTransformNormals(bool value) { SetSchemaValue(m_ptr, "C_OP_SnapshotRigidSkinToBones", "m_bTransformNormals", false, value); }
    bool GetTransformRadii() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SnapshotRigidSkinToBones", "m_bTransformRadii"); }
    void SetTransformRadii(bool value) { SetSchemaValue(m_ptr, "C_OP_SnapshotRigidSkinToBones", "m_bTransformRadii", false, value); }
    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SnapshotRigidSkinToBones", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SnapshotRigidSkinToBones", "m_nControlPointNumber", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif