class GCPointClientUIWorldPanel;

#ifndef _gccpointclientuiworldpanel_h
#define _gccpointclientuiworldpanel_h

#include "../../../scripting.h"




class GCPointClientUIWorldPanel
{
private:
    void *m_ptr;

public:
    GCPointClientUIWorldPanel() {}
    GCPointClientUIWorldPanel(void *ptr) : m_ptr(ptr) {}

    bool GetIgnoreInput() const { return GetSchemaValue<bool>(m_ptr, "CPointClientUIWorldPanel", "m_bIgnoreInput"); }
    void SetIgnoreInput(bool value) { SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_bIgnoreInput", false, value); }
    bool GetLit() const { return GetSchemaValue<bool>(m_ptr, "CPointClientUIWorldPanel", "m_bLit"); }
    void SetLit(bool value) { SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_bLit", false, value); }
    bool GetFollowPlayerAcrossTeleport() const { return GetSchemaValue<bool>(m_ptr, "CPointClientUIWorldPanel", "m_bFollowPlayerAcrossTeleport"); }
    void SetFollowPlayerAcrossTeleport(bool value) { SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_bFollowPlayerAcrossTeleport", false, value); }
    float GetWidth() const { return GetSchemaValue<float>(m_ptr, "CPointClientUIWorldPanel", "m_flWidth"); }
    void SetWidth(float value) { SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_flWidth", false, value); }
    float GetHeight() const { return GetSchemaValue<float>(m_ptr, "CPointClientUIWorldPanel", "m_flHeight"); }
    void SetHeight(float value) { SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_flHeight", false, value); }
    float GetDPI() const { return GetSchemaValue<float>(m_ptr, "CPointClientUIWorldPanel", "m_flDPI"); }
    void SetDPI(float value) { SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_flDPI", false, value); }
    float GetInteractDistance() const { return GetSchemaValue<float>(m_ptr, "CPointClientUIWorldPanel", "m_flInteractDistance"); }
    void SetInteractDistance(float value) { SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_flInteractDistance", false, value); }
    float GetDepthOffset() const { return GetSchemaValue<float>(m_ptr, "CPointClientUIWorldPanel", "m_flDepthOffset"); }
    void SetDepthOffset(float value) { SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_flDepthOffset", false, value); }
    uint32_t GetOwnerContext() const { return GetSchemaValue<uint32_t>(m_ptr, "CPointClientUIWorldPanel", "m_unOwnerContext"); }
    void SetOwnerContext(uint32_t value) { SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_unOwnerContext", false, value); }
    uint32_t GetHorizontalAlign() const { return GetSchemaValue<uint32_t>(m_ptr, "CPointClientUIWorldPanel", "m_unHorizontalAlign"); }
    void SetHorizontalAlign(uint32_t value) { SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_unHorizontalAlign", false, value); }
    uint32_t GetVerticalAlign() const { return GetSchemaValue<uint32_t>(m_ptr, "CPointClientUIWorldPanel", "m_unVerticalAlign"); }
    void SetVerticalAlign(uint32_t value) { SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_unVerticalAlign", false, value); }
    uint32_t GetOrientation() const { return GetSchemaValue<uint32_t>(m_ptr, "CPointClientUIWorldPanel", "m_unOrientation"); }
    void SetOrientation(uint32_t value) { SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_unOrientation", false, value); }
    bool GetAllowInteractionFromAllSceneWorlds() const { return GetSchemaValue<bool>(m_ptr, "CPointClientUIWorldPanel", "m_bAllowInteractionFromAllSceneWorlds"); }
    void SetAllowInteractionFromAllSceneWorlds(bool value) { SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_bAllowInteractionFromAllSceneWorlds", false, value); }
    std::vector<CUtlSymbolLarge> GetCSSClasses() const { CUtlVector<CUtlSymbolLarge>* vec = GetSchemaValue<CUtlVector<CUtlSymbolLarge>*>(m_ptr, "CPointClientUIWorldPanel", "m_vecCSSClasses"); std::vector<CUtlSymbolLarge> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetCSSClasses(std::vector<CUtlSymbolLarge> value) { SetSchemaValueCUtlVector<CUtlSymbolLarge>(m_ptr, "CPointClientUIWorldPanel", "m_vecCSSClasses", false, value); }
    bool GetOpaque() const { return GetSchemaValue<bool>(m_ptr, "CPointClientUIWorldPanel", "m_bOpaque"); }
    void SetOpaque(bool value) { SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_bOpaque", false, value); }
    bool GetNoDepth() const { return GetSchemaValue<bool>(m_ptr, "CPointClientUIWorldPanel", "m_bNoDepth"); }
    void SetNoDepth(bool value) { SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_bNoDepth", false, value); }
    bool GetRenderBackface() const { return GetSchemaValue<bool>(m_ptr, "CPointClientUIWorldPanel", "m_bRenderBackface"); }
    void SetRenderBackface(bool value) { SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_bRenderBackface", false, value); }
    bool GetUseOffScreenIndicator() const { return GetSchemaValue<bool>(m_ptr, "CPointClientUIWorldPanel", "m_bUseOffScreenIndicator"); }
    void SetUseOffScreenIndicator(bool value) { SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_bUseOffScreenIndicator", false, value); }
    bool GetExcludeFromSaveGames() const { return GetSchemaValue<bool>(m_ptr, "CPointClientUIWorldPanel", "m_bExcludeFromSaveGames"); }
    void SetExcludeFromSaveGames(bool value) { SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_bExcludeFromSaveGames", false, value); }
    bool GetGrabbable() const { return GetSchemaValue<bool>(m_ptr, "CPointClientUIWorldPanel", "m_bGrabbable"); }
    void SetGrabbable(bool value) { SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_bGrabbable", false, value); }
    bool GetOnlyRenderToTexture() const { return GetSchemaValue<bool>(m_ptr, "CPointClientUIWorldPanel", "m_bOnlyRenderToTexture"); }
    void SetOnlyRenderToTexture(bool value) { SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_bOnlyRenderToTexture", false, value); }
    bool GetDisableMipGen() const { return GetSchemaValue<bool>(m_ptr, "CPointClientUIWorldPanel", "m_bDisableMipGen"); }
    void SetDisableMipGen(bool value) { SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_bDisableMipGen", false, value); }
    int32_t GetExplicitImageLayout() const { return GetSchemaValue<int32_t>(m_ptr, "CPointClientUIWorldPanel", "m_nExplicitImageLayout"); }
    void SetExplicitImageLayout(int32_t value) { SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_nExplicitImageLayout", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif