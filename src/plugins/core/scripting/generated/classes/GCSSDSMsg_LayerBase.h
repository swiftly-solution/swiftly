class GCSSDSMsg_LayerBase;

#ifndef _gccssdsmsg_layerbase_h
#define _gccssdsmsg_layerbase_h

#include "../../../scripting.h"


#include "GSceneViewId_t.h"

class GCSSDSMsg_LayerBase
{
private:
    void *m_ptr;

public:
    GCSSDSMsg_LayerBase() {}
    GCSSDSMsg_LayerBase(void *ptr) : m_ptr(ptr) {}

    GSceneViewId_t GetViewId() const { return GetSchemaValue<GSceneViewId_t>(m_ptr, "CSSDSMsg_LayerBase", "m_viewId"); }
    void SetViewId(GSceneViewId_t value) { SetSchemaValue(m_ptr, "CSSDSMsg_LayerBase", "m_viewId", false, value); }
    CUtlString GetViewName() const { return GetSchemaValue<CUtlString>(m_ptr, "CSSDSMsg_LayerBase", "m_ViewName"); }
    void SetViewName(CUtlString value) { SetSchemaValue(m_ptr, "CSSDSMsg_LayerBase", "m_ViewName", false, value); }
    int32_t GetLayerIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CSSDSMsg_LayerBase", "m_nLayerIndex"); }
    void SetLayerIndex(int32_t value) { SetSchemaValue(m_ptr, "CSSDSMsg_LayerBase", "m_nLayerIndex", false, value); }
    uint64_t GetLayerId() const { return GetSchemaValue<uint64_t>(m_ptr, "CSSDSMsg_LayerBase", "m_nLayerId"); }
    void SetLayerId(uint64_t value) { SetSchemaValue(m_ptr, "CSSDSMsg_LayerBase", "m_nLayerId", false, value); }
    CUtlString GetLayerName() const { return GetSchemaValue<CUtlString>(m_ptr, "CSSDSMsg_LayerBase", "m_LayerName"); }
    void SetLayerName(CUtlString value) { SetSchemaValue(m_ptr, "CSSDSMsg_LayerBase", "m_LayerName", false, value); }
    CUtlString GetDisplayText() const { return GetSchemaValue<CUtlString>(m_ptr, "CSSDSMsg_LayerBase", "m_displayText"); }
    void SetDisplayText(CUtlString value) { SetSchemaValue(m_ptr, "CSSDSMsg_LayerBase", "m_displayText", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif