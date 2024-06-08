class GCFuncInteractionLayerClip;

#ifndef _gccfuncinteractionlayerclip_h
#define _gccfuncinteractionlayerclip_h

#include "../../../scripting.h"




class GCFuncInteractionLayerClip
{
private:
    void *m_ptr;

public:
    GCFuncInteractionLayerClip() {}
    GCFuncInteractionLayerClip(void *ptr) : m_ptr(ptr) {}

    bool GetDisabled() const { return GetSchemaValue<bool>(m_ptr, "CFuncInteractionLayerClip", "m_bDisabled"); }
    void SetDisabled(bool value) { SetSchemaValue(m_ptr, "CFuncInteractionLayerClip", "m_bDisabled", false, value); }
    CUtlSymbolLarge GetInteractsAs() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncInteractionLayerClip", "m_iszInteractsAs"); }
    void SetInteractsAs(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFuncInteractionLayerClip", "m_iszInteractsAs", false, value); }
    CUtlSymbolLarge GetInteractsWith() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncInteractionLayerClip", "m_iszInteractsWith"); }
    void SetInteractsWith(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFuncInteractionLayerClip", "m_iszInteractsWith", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif