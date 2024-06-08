class GCInfoOffscreenPanoramaTexture;

#ifndef _gccinfooffscreenpanoramatexture_h
#define _gccinfooffscreenpanoramatexture_h

#include "../../../scripting.h"


#include "GCBaseModelEntity.h"

class GCInfoOffscreenPanoramaTexture
{
private:
    void *m_ptr;

public:
    GCInfoOffscreenPanoramaTexture() {}
    GCInfoOffscreenPanoramaTexture(void *ptr) : m_ptr(ptr) {}

    bool GetDisabled() const { return GetSchemaValue<bool>(m_ptr, "CInfoOffscreenPanoramaTexture", "m_bDisabled"); }
    void SetDisabled(bool value) { SetSchemaValue(m_ptr, "CInfoOffscreenPanoramaTexture", "m_bDisabled", false, value); }
    int32_t GetResolutionX() const { return GetSchemaValue<int32_t>(m_ptr, "CInfoOffscreenPanoramaTexture", "m_nResolutionX"); }
    void SetResolutionX(int32_t value) { SetSchemaValue(m_ptr, "CInfoOffscreenPanoramaTexture", "m_nResolutionX", false, value); }
    int32_t GetResolutionY() const { return GetSchemaValue<int32_t>(m_ptr, "CInfoOffscreenPanoramaTexture", "m_nResolutionY"); }
    void SetResolutionY(int32_t value) { SetSchemaValue(m_ptr, "CInfoOffscreenPanoramaTexture", "m_nResolutionY", false, value); }
    CUtlSymbolLarge GetLayoutFileName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CInfoOffscreenPanoramaTexture", "m_szLayoutFileName"); }
    void SetLayoutFileName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CInfoOffscreenPanoramaTexture", "m_szLayoutFileName", false, value); }
    CUtlSymbolLarge GetRenderAttrName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CInfoOffscreenPanoramaTexture", "m_RenderAttrName"); }
    void SetRenderAttrName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CInfoOffscreenPanoramaTexture", "m_RenderAttrName", false, value); }
    GCBaseModelEntity* GetTargetEntities() const { return GetSchemaValue<GCBaseModelEntity*>(m_ptr, "CInfoOffscreenPanoramaTexture", "m_TargetEntities"); }
    void SetTargetEntities(GCBaseModelEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'TargetEntities' is not possible.\n"); }
    int32_t GetTargetChangeCount() const { return GetSchemaValue<int32_t>(m_ptr, "CInfoOffscreenPanoramaTexture", "m_nTargetChangeCount"); }
    void SetTargetChangeCount(int32_t value) { SetSchemaValue(m_ptr, "CInfoOffscreenPanoramaTexture", "m_nTargetChangeCount", false, value); }
    std::vector<CUtlSymbolLarge> GetCSSClasses() const { CUtlVector<CUtlSymbolLarge>* vec = GetSchemaValue<CUtlVector<CUtlSymbolLarge>*>(m_ptr, "CInfoOffscreenPanoramaTexture", "m_vecCSSClasses"); std::vector<CUtlSymbolLarge> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetCSSClasses(std::vector<CUtlSymbolLarge> value) { SetSchemaValueCUtlVector<CUtlSymbolLarge>(m_ptr, "CInfoOffscreenPanoramaTexture", "m_vecCSSClasses", false, value); }
    CUtlSymbolLarge GetTargetsName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CInfoOffscreenPanoramaTexture", "m_szTargetsName"); }
    void SetTargetsName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CInfoOffscreenPanoramaTexture", "m_szTargetsName", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif