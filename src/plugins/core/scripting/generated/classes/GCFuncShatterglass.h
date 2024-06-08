class GCFuncShatterglass;

#ifndef _gccfuncshatterglass_h
#define _gccfuncshatterglass_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCFuncShatterglass
{
private:
    void *m_ptr;

public:
    GCFuncShatterglass() {}
    GCFuncShatterglass(void *ptr) : m_ptr(ptr) {}

    matrix3x4_t GetMatPanelTransform() const { return GetSchemaValue<matrix3x4_t>(m_ptr, "CFuncShatterglass", "m_matPanelTransform"); }
    void SetMatPanelTransform(matrix3x4_t value) { SetSchemaValue(m_ptr, "CFuncShatterglass", "m_matPanelTransform", false, value); }
    matrix3x4_t GetMatPanelTransformWsTemp() const { return GetSchemaValue<matrix3x4_t>(m_ptr, "CFuncShatterglass", "m_matPanelTransformWsTemp"); }
    void SetMatPanelTransformWsTemp(matrix3x4_t value) { SetSchemaValue(m_ptr, "CFuncShatterglass", "m_matPanelTransformWsTemp", false, value); }
    std::vector<uint32> GetShatterGlassShards() const { CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "CFuncShatterglass", "m_vecShatterGlassShards"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetShatterGlassShards(std::vector<uint32> value) { SetSchemaValueCUtlVector<uint32>(m_ptr, "CFuncShatterglass", "m_vecShatterGlassShards", false, value); }
    Vector2D GetPanelSize() const { return GetSchemaValue<Vector2D>(m_ptr, "CFuncShatterglass", "m_PanelSize"); }
    void SetPanelSize(Vector2D value) { SetSchemaValue(m_ptr, "CFuncShatterglass", "m_PanelSize", false, value); }
    Vector GetPanelNormalWs() const { return GetSchemaValue<Vector>(m_ptr, "CFuncShatterglass", "m_vecPanelNormalWs"); }
    void SetPanelNormalWs(Vector value) { SetSchemaValue(m_ptr, "CFuncShatterglass", "m_vecPanelNormalWs", false, value); }
    int32_t GetNumShardsEverCreated() const { return GetSchemaValue<int32_t>(m_ptr, "CFuncShatterglass", "m_nNumShardsEverCreated"); }
    void SetNumShardsEverCreated(int32_t value) { SetSchemaValue(m_ptr, "CFuncShatterglass", "m_nNumShardsEverCreated", false, value); }
    float GetGlassThickness() const { return GetSchemaValue<float>(m_ptr, "CFuncShatterglass", "m_flGlassThickness"); }
    void SetGlassThickness(float value) { SetSchemaValue(m_ptr, "CFuncShatterglass", "m_flGlassThickness", false, value); }
    float GetSpawnInvulnerability() const { return GetSchemaValue<float>(m_ptr, "CFuncShatterglass", "m_flSpawnInvulnerability"); }
    void SetSpawnInvulnerability(float value) { SetSchemaValue(m_ptr, "CFuncShatterglass", "m_flSpawnInvulnerability", false, value); }
    bool GetBreakSilent() const { return GetSchemaValue<bool>(m_ptr, "CFuncShatterglass", "m_bBreakSilent"); }
    void SetBreakSilent(bool value) { SetSchemaValue(m_ptr, "CFuncShatterglass", "m_bBreakSilent", false, value); }
    bool GetBreakShardless() const { return GetSchemaValue<bool>(m_ptr, "CFuncShatterglass", "m_bBreakShardless"); }
    void SetBreakShardless(bool value) { SetSchemaValue(m_ptr, "CFuncShatterglass", "m_bBreakShardless", false, value); }
    bool GetBroken() const { return GetSchemaValue<bool>(m_ptr, "CFuncShatterglass", "m_bBroken"); }
    void SetBroken(bool value) { SetSchemaValue(m_ptr, "CFuncShatterglass", "m_bBroken", false, value); }
    bool GetHasRateLimitedShards() const { return GetSchemaValue<bool>(m_ptr, "CFuncShatterglass", "m_bHasRateLimitedShards"); }
    void SetHasRateLimitedShards(bool value) { SetSchemaValue(m_ptr, "CFuncShatterglass", "m_bHasRateLimitedShards", false, value); }
    bool GetGlassNavIgnore() const { return GetSchemaValue<bool>(m_ptr, "CFuncShatterglass", "m_bGlassNavIgnore"); }
    void SetGlassNavIgnore(bool value) { SetSchemaValue(m_ptr, "CFuncShatterglass", "m_bGlassNavIgnore", false, value); }
    bool GetGlassInFrame() const { return GetSchemaValue<bool>(m_ptr, "CFuncShatterglass", "m_bGlassInFrame"); }
    void SetGlassInFrame(bool value) { SetSchemaValue(m_ptr, "CFuncShatterglass", "m_bGlassInFrame", false, value); }
    bool GetStartBroken() const { return GetSchemaValue<bool>(m_ptr, "CFuncShatterglass", "m_bStartBroken"); }
    void SetStartBroken(bool value) { SetSchemaValue(m_ptr, "CFuncShatterglass", "m_bStartBroken", false, value); }
    uint8_t GetInitialDamageType() const { return GetSchemaValue<uint8_t>(m_ptr, "CFuncShatterglass", "m_iInitialDamageType"); }
    void SetInitialDamageType(uint8_t value) { SetSchemaValue(m_ptr, "CFuncShatterglass", "m_iInitialDamageType", false, value); }
    CUtlSymbolLarge GetDamagePositioningEntityName01() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncShatterglass", "m_szDamagePositioningEntityName01"); }
    void SetDamagePositioningEntityName01(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFuncShatterglass", "m_szDamagePositioningEntityName01", false, value); }
    CUtlSymbolLarge GetDamagePositioningEntityName02() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncShatterglass", "m_szDamagePositioningEntityName02"); }
    void SetDamagePositioningEntityName02(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFuncShatterglass", "m_szDamagePositioningEntityName02", false, value); }
    CUtlSymbolLarge GetDamagePositioningEntityName03() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncShatterglass", "m_szDamagePositioningEntityName03"); }
    void SetDamagePositioningEntityName03(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFuncShatterglass", "m_szDamagePositioningEntityName03", false, value); }
    CUtlSymbolLarge GetDamagePositioningEntityName04() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncShatterglass", "m_szDamagePositioningEntityName04"); }
    void SetDamagePositioningEntityName04(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFuncShatterglass", "m_szDamagePositioningEntityName04", false, value); }
    std::vector<Vector> GetInitialDamagePositions() const { CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "CFuncShatterglass", "m_vInitialDamagePositions"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetInitialDamagePositions(std::vector<Vector> value) { SetSchemaValueCUtlVector<Vector>(m_ptr, "CFuncShatterglass", "m_vInitialDamagePositions", false, value); }
    std::vector<Vector> GetExtraDamagePositions() const { CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "CFuncShatterglass", "m_vExtraDamagePositions"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetExtraDamagePositions(std::vector<Vector> value) { SetSchemaValueCUtlVector<Vector>(m_ptr, "CFuncShatterglass", "m_vExtraDamagePositions", false, value); }
    GCEntityIOOutput GetOnBroken() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CFuncShatterglass", "m_OnBroken"); }
    void SetOnBroken(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CFuncShatterglass", "m_OnBroken", false, value); }
    uint8_t GetSurfaceType() const { return GetSchemaValue<uint8_t>(m_ptr, "CFuncShatterglass", "m_iSurfaceType"); }
    void SetSurfaceType(uint8_t value) { SetSchemaValue(m_ptr, "CFuncShatterglass", "m_iSurfaceType", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif