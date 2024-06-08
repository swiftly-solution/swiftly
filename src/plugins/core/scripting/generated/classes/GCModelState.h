class GCModelState;

#ifndef _gccmodelstate_h
#define _gccmodelstate_h

#include "../../../scripting.h"




class GCModelState
{
private:
    void *m_ptr;

public:
    GCModelState() {}
    GCModelState(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetModelName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CModelState", "m_ModelName"); }
    void SetModelName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CModelState", "m_ModelName", false, value); }
    bool GetClientClothCreationSuppressed() const { return GetSchemaValue<bool>(m_ptr, "CModelState", "m_bClientClothCreationSuppressed"); }
    void SetClientClothCreationSuppressed(bool value) { SetSchemaValue(m_ptr, "CModelState", "m_bClientClothCreationSuppressed", false, value); }
    uint64_t GetMeshGroupMask() const { return GetSchemaValue<uint64_t>(m_ptr, "CModelState", "m_MeshGroupMask"); }
    void SetMeshGroupMask(uint64_t value) { SetSchemaValue(m_ptr, "CModelState", "m_MeshGroupMask", false, value); }
    int8_t GetIdealMotionType() const { return GetSchemaValue<int8_t>(m_ptr, "CModelState", "m_nIdealMotionType"); }
    void SetIdealMotionType(int8_t value) { SetSchemaValue(m_ptr, "CModelState", "m_nIdealMotionType", false, value); }
    int8_t GetForceLOD() const { return GetSchemaValue<int8_t>(m_ptr, "CModelState", "m_nForceLOD"); }
    void SetForceLOD(int8_t value) { SetSchemaValue(m_ptr, "CModelState", "m_nForceLOD", false, value); }
    int8_t GetClothUpdateFlags() const { return GetSchemaValue<int8_t>(m_ptr, "CModelState", "m_nClothUpdateFlags"); }
    void SetClothUpdateFlags(int8_t value) { SetSchemaValue(m_ptr, "CModelState", "m_nClothUpdateFlags", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif