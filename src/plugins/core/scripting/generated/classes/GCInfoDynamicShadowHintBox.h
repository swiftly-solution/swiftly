class GCInfoDynamicShadowHintBox;

#ifndef _gccinfodynamicshadowhintbox_h
#define _gccinfodynamicshadowhintbox_h

#include "../../../scripting.h"




class GCInfoDynamicShadowHintBox
{
private:
    void *m_ptr;

public:
    GCInfoDynamicShadowHintBox() {}
    GCInfoDynamicShadowHintBox(void *ptr) : m_ptr(ptr) {}

    Vector GetBoxMins() const { return GetSchemaValue<Vector>(m_ptr, "CInfoDynamicShadowHintBox", "m_vBoxMins"); }
    void SetBoxMins(Vector value) { SetSchemaValue(m_ptr, "CInfoDynamicShadowHintBox", "m_vBoxMins", false, value); }
    Vector GetBoxMaxs() const { return GetSchemaValue<Vector>(m_ptr, "CInfoDynamicShadowHintBox", "m_vBoxMaxs"); }
    void SetBoxMaxs(Vector value) { SetSchemaValue(m_ptr, "CInfoDynamicShadowHintBox", "m_vBoxMaxs", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif