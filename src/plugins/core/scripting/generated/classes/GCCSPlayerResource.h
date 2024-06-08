class GCCSPlayerResource;

#ifndef _gcccsplayerresource_h
#define _gcccsplayerresource_h

#include "../../../scripting.h"




class GCCSPlayerResource
{
private:
    void *m_ptr;

public:
    GCCSPlayerResource() {}
    GCCSPlayerResource(void *ptr) : m_ptr(ptr) {}

    std::vector<bool> GetHostageAlive() const { bool* outValue = GetSchemaValue<bool*>(m_ptr, "CCSPlayerResource", "m_bHostageAlive"); std::vector<bool> ret; for(int i = 0; i < 12; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetHostageAlive(std::vector<bool> value) { bool* outValue = GetSchemaValue<bool*>(m_ptr, "CCSPlayerResource", "m_bHostageAlive"); for(int i = 0; i < 12; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSPlayerResource", "m_bHostageAlive", false, outValue); }
    std::vector<bool> GetIsHostageFollowingSomeone() const { bool* outValue = GetSchemaValue<bool*>(m_ptr, "CCSPlayerResource", "m_isHostageFollowingSomeone"); std::vector<bool> ret; for(int i = 0; i < 12; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetIsHostageFollowingSomeone(std::vector<bool> value) { bool* outValue = GetSchemaValue<bool*>(m_ptr, "CCSPlayerResource", "m_isHostageFollowingSomeone"); for(int i = 0; i < 12; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSPlayerResource", "m_isHostageFollowingSomeone", false, outValue); }
    std::vector<CEntityIndex> GetHostageEntityIDs() const { CEntityIndex* outValue = GetSchemaValue<CEntityIndex*>(m_ptr, "CCSPlayerResource", "m_iHostageEntityIDs"); std::vector<CEntityIndex> ret; for(int i = 0; i < 12; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetHostageEntityIDs(std::vector<CEntityIndex> value) { CEntityIndex* outValue = GetSchemaValue<CEntityIndex*>(m_ptr, "CCSPlayerResource", "m_iHostageEntityIDs"); for(int i = 0; i < 12; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSPlayerResource", "m_iHostageEntityIDs", false, outValue); }
    Vector GetBombsiteCenterA() const { return GetSchemaValue<Vector>(m_ptr, "CCSPlayerResource", "m_bombsiteCenterA"); }
    void SetBombsiteCenterA(Vector value) { SetSchemaValue(m_ptr, "CCSPlayerResource", "m_bombsiteCenterA", false, value); }
    Vector GetBombsiteCenterB() const { return GetSchemaValue<Vector>(m_ptr, "CCSPlayerResource", "m_bombsiteCenterB"); }
    void SetBombsiteCenterB(Vector value) { SetSchemaValue(m_ptr, "CCSPlayerResource", "m_bombsiteCenterB", false, value); }
    std::vector<int32_t> GetHostageRescueX() const { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSPlayerResource", "m_hostageRescueX"); std::vector<int32_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetHostageRescueX(std::vector<int32_t> value) { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSPlayerResource", "m_hostageRescueX"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSPlayerResource", "m_hostageRescueX", false, outValue); }
    std::vector<int32_t> GetHostageRescueY() const { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSPlayerResource", "m_hostageRescueY"); std::vector<int32_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetHostageRescueY(std::vector<int32_t> value) { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSPlayerResource", "m_hostageRescueY"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSPlayerResource", "m_hostageRescueY", false, outValue); }
    std::vector<int32_t> GetHostageRescueZ() const { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSPlayerResource", "m_hostageRescueZ"); std::vector<int32_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetHostageRescueZ(std::vector<int32_t> value) { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSPlayerResource", "m_hostageRescueZ"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSPlayerResource", "m_hostageRescueZ", false, outValue); }
    bool GetEndMatchNextMapAllVoted() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerResource", "m_bEndMatchNextMapAllVoted"); }
    void SetEndMatchNextMapAllVoted(bool value) { SetSchemaValue(m_ptr, "CCSPlayerResource", "m_bEndMatchNextMapAllVoted", false, value); }
    bool GetFoundGoalPositions() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerResource", "m_foundGoalPositions"); }
    void SetFoundGoalPositions(bool value) { SetSchemaValue(m_ptr, "CCSPlayerResource", "m_foundGoalPositions", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif