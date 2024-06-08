class GCDynamicProp;

#ifndef _gccdynamicprop_h
#define _gccdynamicprop_h

#include "../../../scripting.h"

#include "../types/GAnimLoopMode_t.h"
#include "GCEntityIOOutput.h"

class GCDynamicProp
{
private:
    void *m_ptr;

public:
    GCDynamicProp() {}
    GCDynamicProp(void *ptr) : m_ptr(ptr) {}

    bool GetCreateNavObstacle() const { return GetSchemaValue<bool>(m_ptr, "CDynamicProp", "m_bCreateNavObstacle"); }
    void SetCreateNavObstacle(bool value) { SetSchemaValue(m_ptr, "CDynamicProp", "m_bCreateNavObstacle", false, value); }
    bool GetUseHitboxesForRenderBox() const { return GetSchemaValue<bool>(m_ptr, "CDynamicProp", "m_bUseHitboxesForRenderBox"); }
    void SetUseHitboxesForRenderBox(bool value) { SetSchemaValue(m_ptr, "CDynamicProp", "m_bUseHitboxesForRenderBox", false, value); }
    bool GetUseAnimGraph() const { return GetSchemaValue<bool>(m_ptr, "CDynamicProp", "m_bUseAnimGraph"); }
    void SetUseAnimGraph(bool value) { SetSchemaValue(m_ptr, "CDynamicProp", "m_bUseAnimGraph", false, value); }
    GCEntityIOOutput GetOutputAnimBegun() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CDynamicProp", "m_pOutputAnimBegun"); }
    void SetOutputAnimBegun(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CDynamicProp", "m_pOutputAnimBegun", false, value); }
    GCEntityIOOutput GetOutputAnimOver() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CDynamicProp", "m_pOutputAnimOver"); }
    void SetOutputAnimOver(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CDynamicProp", "m_pOutputAnimOver", false, value); }
    GCEntityIOOutput GetOutputAnimLoopCycleOver() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CDynamicProp", "m_pOutputAnimLoopCycleOver"); }
    void SetOutputAnimLoopCycleOver(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CDynamicProp", "m_pOutputAnimLoopCycleOver", false, value); }
    GCEntityIOOutput GetOnAnimReachedStart() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CDynamicProp", "m_OnAnimReachedStart"); }
    void SetOnAnimReachedStart(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CDynamicProp", "m_OnAnimReachedStart", false, value); }
    GCEntityIOOutput GetOnAnimReachedEnd() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CDynamicProp", "m_OnAnimReachedEnd"); }
    void SetOnAnimReachedEnd(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CDynamicProp", "m_OnAnimReachedEnd", false, value); }
    CUtlSymbolLarge GetIdleAnim() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CDynamicProp", "m_iszIdleAnim"); }
    void SetIdleAnim(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CDynamicProp", "m_iszIdleAnim", false, value); }
    AnimLoopMode_t GetIdleAnimLoopMode() const { return GetSchemaValue<AnimLoopMode_t>(m_ptr, "CDynamicProp", "m_nIdleAnimLoopMode"); }
    void SetIdleAnimLoopMode(AnimLoopMode_t value) { SetSchemaValue(m_ptr, "CDynamicProp", "m_nIdleAnimLoopMode", false, value); }
    bool GetRandomizeCycle() const { return GetSchemaValue<bool>(m_ptr, "CDynamicProp", "m_bRandomizeCycle"); }
    void SetRandomizeCycle(bool value) { SetSchemaValue(m_ptr, "CDynamicProp", "m_bRandomizeCycle", false, value); }
    bool GetStartDisabled() const { return GetSchemaValue<bool>(m_ptr, "CDynamicProp", "m_bStartDisabled"); }
    void SetStartDisabled(bool value) { SetSchemaValue(m_ptr, "CDynamicProp", "m_bStartDisabled", false, value); }
    bool GetFiredStartEndOutput() const { return GetSchemaValue<bool>(m_ptr, "CDynamicProp", "m_bFiredStartEndOutput"); }
    void SetFiredStartEndOutput(bool value) { SetSchemaValue(m_ptr, "CDynamicProp", "m_bFiredStartEndOutput", false, value); }
    bool GetForceNpcExclude() const { return GetSchemaValue<bool>(m_ptr, "CDynamicProp", "m_bForceNpcExclude"); }
    void SetForceNpcExclude(bool value) { SetSchemaValue(m_ptr, "CDynamicProp", "m_bForceNpcExclude", false, value); }
    bool GetCreateNonSolid() const { return GetSchemaValue<bool>(m_ptr, "CDynamicProp", "m_bCreateNonSolid"); }
    void SetCreateNonSolid(bool value) { SetSchemaValue(m_ptr, "CDynamicProp", "m_bCreateNonSolid", false, value); }
    bool GetIsOverrideProp() const { return GetSchemaValue<bool>(m_ptr, "CDynamicProp", "m_bIsOverrideProp"); }
    void SetIsOverrideProp(bool value) { SetSchemaValue(m_ptr, "CDynamicProp", "m_bIsOverrideProp", false, value); }
    int32_t GetInitialGlowState() const { return GetSchemaValue<int32_t>(m_ptr, "CDynamicProp", "m_iInitialGlowState"); }
    void SetInitialGlowState(int32_t value) { SetSchemaValue(m_ptr, "CDynamicProp", "m_iInitialGlowState", false, value); }
    int32_t GetGlowRange() const { return GetSchemaValue<int32_t>(m_ptr, "CDynamicProp", "m_nGlowRange"); }
    void SetGlowRange(int32_t value) { SetSchemaValue(m_ptr, "CDynamicProp", "m_nGlowRange", false, value); }
    int32_t GetGlowRangeMin() const { return GetSchemaValue<int32_t>(m_ptr, "CDynamicProp", "m_nGlowRangeMin"); }
    void SetGlowRangeMin(int32_t value) { SetSchemaValue(m_ptr, "CDynamicProp", "m_nGlowRangeMin", false, value); }
    Color GetGlowColor() const { return GetSchemaValue<Color>(m_ptr, "CDynamicProp", "m_glowColor"); }
    void SetGlowColor(Color value) { SetSchemaValue(m_ptr, "CDynamicProp", "m_glowColor", false, value); }
    int32_t GetGlowTeam() const { return GetSchemaValue<int32_t>(m_ptr, "CDynamicProp", "m_nGlowTeam"); }
    void SetGlowTeam(int32_t value) { SetSchemaValue(m_ptr, "CDynamicProp", "m_nGlowTeam", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif