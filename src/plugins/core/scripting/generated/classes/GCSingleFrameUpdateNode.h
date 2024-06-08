class GCSingleFrameUpdateNode;

#ifndef _gccsingleframeupdatenode_h
#define _gccsingleframeupdatenode_h

#include "../../../scripting.h"


#include "GCPoseHandle.h"

class GCSingleFrameUpdateNode
{
private:
    void *m_ptr;

public:
    GCSingleFrameUpdateNode() {}
    GCSingleFrameUpdateNode(void *ptr) : m_ptr(ptr) {}

    GCPoseHandle GetPoseCacheHandle() const { return GetSchemaValue<GCPoseHandle>(m_ptr, "CSingleFrameUpdateNode", "m_hPoseCacheHandle"); }
    void SetPoseCacheHandle(GCPoseHandle value) { SetSchemaValue(m_ptr, "CSingleFrameUpdateNode", "m_hPoseCacheHandle", false, value); }
    float GetCycle() const { return GetSchemaValue<float>(m_ptr, "CSingleFrameUpdateNode", "m_flCycle"); }
    void SetCycle(float value) { SetSchemaValue(m_ptr, "CSingleFrameUpdateNode", "m_flCycle", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif