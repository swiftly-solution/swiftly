class GCSosGroupActionSoundeventClusterSchema;

#ifndef _gccsosgroupactionsoundeventclusterschema_h
#define _gccsosgroupactionsoundeventclusterschema_h

#include "../../../scripting.h"




class GCSosGroupActionSoundeventClusterSchema
{
private:
    void *m_ptr;

public:
    GCSosGroupActionSoundeventClusterSchema() {}
    GCSosGroupActionSoundeventClusterSchema(void *ptr) : m_ptr(ptr) {}

    int32_t GetMinNearby() const { return GetSchemaValue<int32_t>(m_ptr, "CSosGroupActionSoundeventClusterSchema", "m_nMinNearby"); }
    void SetMinNearby(int32_t value) { SetSchemaValue(m_ptr, "CSosGroupActionSoundeventClusterSchema", "m_nMinNearby", false, value); }
    float GetClusterEpsilon() const { return GetSchemaValue<float>(m_ptr, "CSosGroupActionSoundeventClusterSchema", "m_flClusterEpsilon"); }
    void SetClusterEpsilon(float value) { SetSchemaValue(m_ptr, "CSosGroupActionSoundeventClusterSchema", "m_flClusterEpsilon", false, value); }
    CUtlString GetShouldPlayOpvar() const { return GetSchemaValue<CUtlString>(m_ptr, "CSosGroupActionSoundeventClusterSchema", "m_shouldPlayOpvar"); }
    void SetShouldPlayOpvar(CUtlString value) { SetSchemaValue(m_ptr, "CSosGroupActionSoundeventClusterSchema", "m_shouldPlayOpvar", false, value); }
    CUtlString GetShouldPlayClusterChild() const { return GetSchemaValue<CUtlString>(m_ptr, "CSosGroupActionSoundeventClusterSchema", "m_shouldPlayClusterChild"); }
    void SetShouldPlayClusterChild(CUtlString value) { SetSchemaValue(m_ptr, "CSosGroupActionSoundeventClusterSchema", "m_shouldPlayClusterChild", false, value); }
    CUtlString GetClusterSizeOpvar() const { return GetSchemaValue<CUtlString>(m_ptr, "CSosGroupActionSoundeventClusterSchema", "m_clusterSizeOpvar"); }
    void SetClusterSizeOpvar(CUtlString value) { SetSchemaValue(m_ptr, "CSosGroupActionSoundeventClusterSchema", "m_clusterSizeOpvar", false, value); }
    CUtlString GetGroupBoundingBoxMinsOpvar() const { return GetSchemaValue<CUtlString>(m_ptr, "CSosGroupActionSoundeventClusterSchema", "m_groupBoundingBoxMinsOpvar"); }
    void SetGroupBoundingBoxMinsOpvar(CUtlString value) { SetSchemaValue(m_ptr, "CSosGroupActionSoundeventClusterSchema", "m_groupBoundingBoxMinsOpvar", false, value); }
    CUtlString GetGroupBoundingBoxMaxsOpvar() const { return GetSchemaValue<CUtlString>(m_ptr, "CSosGroupActionSoundeventClusterSchema", "m_groupBoundingBoxMaxsOpvar"); }
    void SetGroupBoundingBoxMaxsOpvar(CUtlString value) { SetSchemaValue(m_ptr, "CSosGroupActionSoundeventClusterSchema", "m_groupBoundingBoxMaxsOpvar", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif