class GCPlayerSprayDecal;

#ifndef _gccplayerspraydecal_h
#define _gccplayerspraydecal_h

#include "../../../scripting.h"




class GCPlayerSprayDecal
{
private:
    void *m_ptr;

public:
    GCPlayerSprayDecal() {}
    GCPlayerSprayDecal(void *ptr) : m_ptr(ptr) {}

    int32_t GetUniqueID() const { return GetSchemaValue<int32_t>(m_ptr, "CPlayerSprayDecal", "m_nUniqueID"); }
    void SetUniqueID(int32_t value) { SetSchemaValue(m_ptr, "CPlayerSprayDecal", "m_nUniqueID", false, value); }
    uint32_t GetAccountID() const { return GetSchemaValue<uint32_t>(m_ptr, "CPlayerSprayDecal", "m_unAccountID"); }
    void SetAccountID(uint32_t value) { SetSchemaValue(m_ptr, "CPlayerSprayDecal", "m_unAccountID", false, value); }
    uint32_t GetTraceID() const { return GetSchemaValue<uint32_t>(m_ptr, "CPlayerSprayDecal", "m_unTraceID"); }
    void SetTraceID(uint32_t value) { SetSchemaValue(m_ptr, "CPlayerSprayDecal", "m_unTraceID", false, value); }
    uint32_t GetRtGcTime() const { return GetSchemaValue<uint32_t>(m_ptr, "CPlayerSprayDecal", "m_rtGcTime"); }
    void SetRtGcTime(uint32_t value) { SetSchemaValue(m_ptr, "CPlayerSprayDecal", "m_rtGcTime", false, value); }
    Vector GetEndPos() const { return GetSchemaValue<Vector>(m_ptr, "CPlayerSprayDecal", "m_vecEndPos"); }
    void SetEndPos(Vector value) { SetSchemaValue(m_ptr, "CPlayerSprayDecal", "m_vecEndPos", false, value); }
    Vector GetStart() const { return GetSchemaValue<Vector>(m_ptr, "CPlayerSprayDecal", "m_vecStart"); }
    void SetStart(Vector value) { SetSchemaValue(m_ptr, "CPlayerSprayDecal", "m_vecStart", false, value); }
    Vector GetLeft() const { return GetSchemaValue<Vector>(m_ptr, "CPlayerSprayDecal", "m_vecLeft"); }
    void SetLeft(Vector value) { SetSchemaValue(m_ptr, "CPlayerSprayDecal", "m_vecLeft", false, value); }
    Vector GetNormal() const { return GetSchemaValue<Vector>(m_ptr, "CPlayerSprayDecal", "m_vecNormal"); }
    void SetNormal(Vector value) { SetSchemaValue(m_ptr, "CPlayerSprayDecal", "m_vecNormal", false, value); }
    int32_t GetPlayer() const { return GetSchemaValue<int32_t>(m_ptr, "CPlayerSprayDecal", "m_nPlayer"); }
    void SetPlayer(int32_t value) { SetSchemaValue(m_ptr, "CPlayerSprayDecal", "m_nPlayer", false, value); }
    int32_t GetEntity() const { return GetSchemaValue<int32_t>(m_ptr, "CPlayerSprayDecal", "m_nEntity"); }
    void SetEntity(int32_t value) { SetSchemaValue(m_ptr, "CPlayerSprayDecal", "m_nEntity", false, value); }
    int32_t GetHitbox() const { return GetSchemaValue<int32_t>(m_ptr, "CPlayerSprayDecal", "m_nHitbox"); }
    void SetHitbox(int32_t value) { SetSchemaValue(m_ptr, "CPlayerSprayDecal", "m_nHitbox", false, value); }
    float GetCreationTime() const { return GetSchemaValue<float>(m_ptr, "CPlayerSprayDecal", "m_flCreationTime"); }
    void SetCreationTime(float value) { SetSchemaValue(m_ptr, "CPlayerSprayDecal", "m_flCreationTime", false, value); }
    int32_t GetTintID() const { return GetSchemaValue<int32_t>(m_ptr, "CPlayerSprayDecal", "m_nTintID"); }
    void SetTintID(int32_t value) { SetSchemaValue(m_ptr, "CPlayerSprayDecal", "m_nTintID", false, value); }
    uint8_t GetVersion() const { return GetSchemaValue<uint8_t>(m_ptr, "CPlayerSprayDecal", "m_nVersion"); }
    void SetVersion(uint8_t value) { SetSchemaValue(m_ptr, "CPlayerSprayDecal", "m_nVersion", false, value); }
    std::vector<uint8_t> GetSignature() const { uint8_t* outValue = GetSchemaValue<uint8_t*>(m_ptr, "CPlayerSprayDecal", "m_ubSignature"); std::vector<uint8_t> ret; for(int i = 0; i < 128; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetSignature(std::vector<uint8_t> value) { uint8_t* outValue = GetSchemaValue<uint8_t*>(m_ptr, "CPlayerSprayDecal", "m_ubSignature"); for(int i = 0; i < 128; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CPlayerSprayDecal", "m_ubSignature", false, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif