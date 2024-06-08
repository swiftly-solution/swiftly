class GC_INIT_CreateOnGrid;

#ifndef _gcc_init_createongrid_h
#define _gcc_init_createongrid_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"

class GC_INIT_CreateOnGrid
{
private:
    void *m_ptr;

public:
    GC_INIT_CreateOnGrid() {}
    GC_INIT_CreateOnGrid(void *ptr) : m_ptr(ptr) {}

    GCParticleCollectionFloatInput GetXCount() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_INIT_CreateOnGrid", "m_nXCount"); }
    void SetXCount(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnGrid", "m_nXCount", false, value); }
    GCParticleCollectionFloatInput GetYCount() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_INIT_CreateOnGrid", "m_nYCount"); }
    void SetYCount(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnGrid", "m_nYCount", false, value); }
    GCParticleCollectionFloatInput GetZCount() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_INIT_CreateOnGrid", "m_nZCount"); }
    void SetZCount(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnGrid", "m_nZCount", false, value); }
    GCParticleCollectionFloatInput GetXSpacing() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_INIT_CreateOnGrid", "m_nXSpacing"); }
    void SetXSpacing(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnGrid", "m_nXSpacing", false, value); }
    GCParticleCollectionFloatInput GetYSpacing() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_INIT_CreateOnGrid", "m_nYSpacing"); }
    void SetYSpacing(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnGrid", "m_nYSpacing", false, value); }
    GCParticleCollectionFloatInput GetZSpacing() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_INIT_CreateOnGrid", "m_nZSpacing"); }
    void SetZSpacing(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnGrid", "m_nZSpacing", false, value); }
    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_CreateOnGrid", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnGrid", "m_nControlPointNumber", false, value); }
    bool GetLocalSpace() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreateOnGrid", "m_bLocalSpace"); }
    void SetLocalSpace(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnGrid", "m_bLocalSpace", false, value); }
    bool GetCenter() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreateOnGrid", "m_bCenter"); }
    void SetCenter(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnGrid", "m_bCenter", false, value); }
    bool GetHollow() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreateOnGrid", "m_bHollow"); }
    void SetHollow(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnGrid", "m_bHollow", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif