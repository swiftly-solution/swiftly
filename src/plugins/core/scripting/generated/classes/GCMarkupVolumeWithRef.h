class GCMarkupVolumeWithRef;

#ifndef _gccmarkupvolumewithref_h
#define _gccmarkupvolumewithref_h

#include "../../../scripting.h"




class GCMarkupVolumeWithRef
{
private:
    void *m_ptr;

public:
    GCMarkupVolumeWithRef() {}
    GCMarkupVolumeWithRef(void *ptr) : m_ptr(ptr) {}

    bool GetUseRef() const { return GetSchemaValue<bool>(m_ptr, "CMarkupVolumeWithRef", "m_bUseRef"); }
    void SetUseRef(bool value) { SetSchemaValue(m_ptr, "CMarkupVolumeWithRef", "m_bUseRef", false, value); }
    Vector GetRefPos() const { return GetSchemaValue<Vector>(m_ptr, "CMarkupVolumeWithRef", "m_vRefPos"); }
    void SetRefPos(Vector value) { SetSchemaValue(m_ptr, "CMarkupVolumeWithRef", "m_vRefPos", false, value); }
    float GetRefDot() const { return GetSchemaValue<float>(m_ptr, "CMarkupVolumeWithRef", "m_flRefDot"); }
    void SetRefDot(float value) { SetSchemaValue(m_ptr, "CMarkupVolumeWithRef", "m_flRefDot", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif