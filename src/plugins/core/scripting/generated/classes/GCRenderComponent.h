class GCRenderComponent;

#ifndef _gccrendercomponent_h
#define _gccrendercomponent_h

#include "../../../scripting.h"


#include "GCNetworkVarChainer.h"

class GCRenderComponent
{
private:
    void *m_ptr;

public:
    GCRenderComponent() {}
    GCRenderComponent(void *ptr) : m_ptr(ptr) {}

    GCNetworkVarChainer Get__pChainEntity() const { return GetSchemaValue<GCNetworkVarChainer>(m_ptr, "CRenderComponent", "__m_pChainEntity"); }
    void Set__pChainEntity(GCNetworkVarChainer value) { SetSchemaValue(m_ptr, "CRenderComponent", "__m_pChainEntity", false, value); }
    bool GetIsRenderingWithViewModels() const { return GetSchemaValue<bool>(m_ptr, "CRenderComponent", "m_bIsRenderingWithViewModels"); }
    void SetIsRenderingWithViewModels(bool value) { SetSchemaValue(m_ptr, "CRenderComponent", "m_bIsRenderingWithViewModels", false, value); }
    uint32_t GetSplitscreenFlags() const { return GetSchemaValue<uint32_t>(m_ptr, "CRenderComponent", "m_nSplitscreenFlags"); }
    void SetSplitscreenFlags(uint32_t value) { SetSchemaValue(m_ptr, "CRenderComponent", "m_nSplitscreenFlags", false, value); }
    bool GetEnableRendering() const { return GetSchemaValue<bool>(m_ptr, "CRenderComponent", "m_bEnableRendering"); }
    void SetEnableRendering(bool value) { SetSchemaValue(m_ptr, "CRenderComponent", "m_bEnableRendering", false, value); }
    bool GetInterpolationReadyToDraw() const { return GetSchemaValue<bool>(m_ptr, "CRenderComponent", "m_bInterpolationReadyToDraw"); }
    void SetInterpolationReadyToDraw(bool value) { SetSchemaValue(m_ptr, "CRenderComponent", "m_bInterpolationReadyToDraw", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif