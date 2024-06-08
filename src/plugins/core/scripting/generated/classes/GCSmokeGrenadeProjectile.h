class GCSmokeGrenadeProjectile;

#ifndef _gccsmokegrenadeprojectile_h
#define _gccsmokegrenadeprojectile_h

#include "../../../scripting.h"




class GCSmokeGrenadeProjectile
{
private:
    void *m_ptr;

public:
    GCSmokeGrenadeProjectile() {}
    GCSmokeGrenadeProjectile(void *ptr) : m_ptr(ptr) {}

    int32_t GetSmokeEffectTickBegin() const { return GetSchemaValue<int32_t>(m_ptr, "CSmokeGrenadeProjectile", "m_nSmokeEffectTickBegin"); }
    void SetSmokeEffectTickBegin(int32_t value) { SetSchemaValue(m_ptr, "CSmokeGrenadeProjectile", "m_nSmokeEffectTickBegin", false, value); }
    bool GetDidSmokeEffect() const { return GetSchemaValue<bool>(m_ptr, "CSmokeGrenadeProjectile", "m_bDidSmokeEffect"); }
    void SetDidSmokeEffect(bool value) { SetSchemaValue(m_ptr, "CSmokeGrenadeProjectile", "m_bDidSmokeEffect", false, value); }
    int32_t GetRandomSeed() const { return GetSchemaValue<int32_t>(m_ptr, "CSmokeGrenadeProjectile", "m_nRandomSeed"); }
    void SetRandomSeed(int32_t value) { SetSchemaValue(m_ptr, "CSmokeGrenadeProjectile", "m_nRandomSeed", false, value); }
    Vector GetSmokeColor() const { return GetSchemaValue<Vector>(m_ptr, "CSmokeGrenadeProjectile", "m_vSmokeColor"); }
    void SetSmokeColor(Vector value) { SetSchemaValue(m_ptr, "CSmokeGrenadeProjectile", "m_vSmokeColor", false, value); }
    Vector GetSmokeDetonationPos() const { return GetSchemaValue<Vector>(m_ptr, "CSmokeGrenadeProjectile", "m_vSmokeDetonationPos"); }
    void SetSmokeDetonationPos(Vector value) { SetSchemaValue(m_ptr, "CSmokeGrenadeProjectile", "m_vSmokeDetonationPos", false, value); }
    std::vector<uint8> GetVoxelFrameData() const { CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "CSmokeGrenadeProjectile", "m_VoxelFrameData"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetVoxelFrameData(std::vector<uint8> value) { SetSchemaValueCUtlVector<uint8>(m_ptr, "CSmokeGrenadeProjectile", "m_VoxelFrameData", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif