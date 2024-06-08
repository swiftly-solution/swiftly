class GCNavLinkAreaEntity;

#ifndef _gccnavlinkareaentity_h
#define _gccnavlinkareaentity_h

#include "../../../scripting.h"


#include "GCBaseFilter.h"
#include "GCEntityIOOutput.h"

class GCNavLinkAreaEntity
{
private:
    void *m_ptr;

public:
    GCNavLinkAreaEntity() {}
    GCNavLinkAreaEntity(void *ptr) : m_ptr(ptr) {}

    float GetWidth() const { return GetSchemaValue<float>(m_ptr, "CNavLinkAreaEntity", "m_flWidth"); }
    void SetWidth(float value) { SetSchemaValue(m_ptr, "CNavLinkAreaEntity", "m_flWidth", false, value); }
    Vector GetLocatorOffset() const { return GetSchemaValue<Vector>(m_ptr, "CNavLinkAreaEntity", "m_vLocatorOffset"); }
    void SetLocatorOffset(Vector value) { SetSchemaValue(m_ptr, "CNavLinkAreaEntity", "m_vLocatorOffset", false, value); }
    QAngle GetLocatorAnglesOffset() const { return GetSchemaValue<QAngle>(m_ptr, "CNavLinkAreaEntity", "m_qLocatorAnglesOffset"); }
    void SetLocatorAnglesOffset(QAngle value) { SetSchemaValue(m_ptr, "CNavLinkAreaEntity", "m_qLocatorAnglesOffset", false, value); }
    CUtlSymbolLarge GetStrMovementForward() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CNavLinkAreaEntity", "m_strMovementForward"); }
    void SetStrMovementForward(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CNavLinkAreaEntity", "m_strMovementForward", false, value); }
    CUtlSymbolLarge GetStrMovementReverse() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CNavLinkAreaEntity", "m_strMovementReverse"); }
    void SetStrMovementReverse(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CNavLinkAreaEntity", "m_strMovementReverse", false, value); }
    int32_t GetNavLinkIdForward() const { return GetSchemaValue<int32_t>(m_ptr, "CNavLinkAreaEntity", "m_nNavLinkIdForward"); }
    void SetNavLinkIdForward(int32_t value) { SetSchemaValue(m_ptr, "CNavLinkAreaEntity", "m_nNavLinkIdForward", false, value); }
    int32_t GetNavLinkIdReverse() const { return GetSchemaValue<int32_t>(m_ptr, "CNavLinkAreaEntity", "m_nNavLinkIdReverse"); }
    void SetNavLinkIdReverse(int32_t value) { SetSchemaValue(m_ptr, "CNavLinkAreaEntity", "m_nNavLinkIdReverse", false, value); }
    bool GetEnabled() const { return GetSchemaValue<bool>(m_ptr, "CNavLinkAreaEntity", "m_bEnabled"); }
    void SetEnabled(bool value) { SetSchemaValue(m_ptr, "CNavLinkAreaEntity", "m_bEnabled", false, value); }
    CUtlSymbolLarge GetStrFilterName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CNavLinkAreaEntity", "m_strFilterName"); }
    void SetStrFilterName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CNavLinkAreaEntity", "m_strFilterName", false, value); }
    GCBaseFilter* GetFilter() const { return GetSchemaValue<GCBaseFilter*>(m_ptr, "CNavLinkAreaEntity", "m_hFilter"); }
    void SetFilter(GCBaseFilter* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Filter' is not possible.\n"); }
    GCEntityIOOutput GetOnNavLinkStart() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CNavLinkAreaEntity", "m_OnNavLinkStart"); }
    void SetOnNavLinkStart(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CNavLinkAreaEntity", "m_OnNavLinkStart", false, value); }
    GCEntityIOOutput GetOnNavLinkFinish() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CNavLinkAreaEntity", "m_OnNavLinkFinish"); }
    void SetOnNavLinkFinish(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CNavLinkAreaEntity", "m_OnNavLinkFinish", false, value); }
    bool GetIsTerminus() const { return GetSchemaValue<bool>(m_ptr, "CNavLinkAreaEntity", "m_bIsTerminus"); }
    void SetIsTerminus(bool value) { SetSchemaValue(m_ptr, "CNavLinkAreaEntity", "m_bIsTerminus", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif