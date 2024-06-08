class GCNavHullVData;

#ifndef _gccnavhullvdata_h
#define _gccnavhullvdata_h

#include "../../../scripting.h"




class GCNavHullVData
{
private:
    void *m_ptr;

public:
    GCNavHullVData() {}
    GCNavHullVData(void *ptr) : m_ptr(ptr) {}

    bool GetAgentEnabled() const { return GetSchemaValue<bool>(m_ptr, "CNavHullVData", "m_bAgentEnabled"); }
    void SetAgentEnabled(bool value) { SetSchemaValue(m_ptr, "CNavHullVData", "m_bAgentEnabled", false, value); }
    float GetAgentRadius() const { return GetSchemaValue<float>(m_ptr, "CNavHullVData", "m_agentRadius"); }
    void SetAgentRadius(float value) { SetSchemaValue(m_ptr, "CNavHullVData", "m_agentRadius", false, value); }
    float GetAgentHeight() const { return GetSchemaValue<float>(m_ptr, "CNavHullVData", "m_agentHeight"); }
    void SetAgentHeight(float value) { SetSchemaValue(m_ptr, "CNavHullVData", "m_agentHeight", false, value); }
    bool GetAgentShortHeightEnabled() const { return GetSchemaValue<bool>(m_ptr, "CNavHullVData", "m_agentShortHeightEnabled"); }
    void SetAgentShortHeightEnabled(bool value) { SetSchemaValue(m_ptr, "CNavHullVData", "m_agentShortHeightEnabled", false, value); }
    float GetAgentShortHeight() const { return GetSchemaValue<float>(m_ptr, "CNavHullVData", "m_agentShortHeight"); }
    void SetAgentShortHeight(float value) { SetSchemaValue(m_ptr, "CNavHullVData", "m_agentShortHeight", false, value); }
    float GetAgentMaxClimb() const { return GetSchemaValue<float>(m_ptr, "CNavHullVData", "m_agentMaxClimb"); }
    void SetAgentMaxClimb(float value) { SetSchemaValue(m_ptr, "CNavHullVData", "m_agentMaxClimb", false, value); }
    int32_t GetAgentMaxSlope() const { return GetSchemaValue<int32_t>(m_ptr, "CNavHullVData", "m_agentMaxSlope"); }
    void SetAgentMaxSlope(int32_t value) { SetSchemaValue(m_ptr, "CNavHullVData", "m_agentMaxSlope", false, value); }
    float GetAgentMaxJumpDownDist() const { return GetSchemaValue<float>(m_ptr, "CNavHullVData", "m_agentMaxJumpDownDist"); }
    void SetAgentMaxJumpDownDist(float value) { SetSchemaValue(m_ptr, "CNavHullVData", "m_agentMaxJumpDownDist", false, value); }
    float GetAgentMaxJumpHorizDistBase() const { return GetSchemaValue<float>(m_ptr, "CNavHullVData", "m_agentMaxJumpHorizDistBase"); }
    void SetAgentMaxJumpHorizDistBase(float value) { SetSchemaValue(m_ptr, "CNavHullVData", "m_agentMaxJumpHorizDistBase", false, value); }
    float GetAgentMaxJumpUpDist() const { return GetSchemaValue<float>(m_ptr, "CNavHullVData", "m_agentMaxJumpUpDist"); }
    void SetAgentMaxJumpUpDist(float value) { SetSchemaValue(m_ptr, "CNavHullVData", "m_agentMaxJumpUpDist", false, value); }
    int32_t GetAgentBorderErosion() const { return GetSchemaValue<int32_t>(m_ptr, "CNavHullVData", "m_agentBorderErosion"); }
    void SetAgentBorderErosion(int32_t value) { SetSchemaValue(m_ptr, "CNavHullVData", "m_agentBorderErosion", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif