class GEntityRenderAttribute_t;

#ifndef _gcentityrenderattribute_t_h
#define _gcentityrenderattribute_t_h

#include "../../../scripting.h"




class GEntityRenderAttribute_t
{
private:
    void *m_ptr;

public:
    GEntityRenderAttribute_t() {}
    GEntityRenderAttribute_t(void *ptr) : m_ptr(ptr) {}

    CUtlStringToken GetID() const { return GetSchemaValue<CUtlStringToken>(m_ptr, "EntityRenderAttribute_t", "m_ID"); }
    void SetID(CUtlStringToken value) { SetSchemaValue(m_ptr, "EntityRenderAttribute_t", "m_ID", true, value); }
    Vector4D GetValues() const { return GetSchemaValue<Vector4D>(m_ptr, "EntityRenderAttribute_t", "m_Values"); }
    void SetValues(Vector4D value) { SetSchemaValue(m_ptr, "EntityRenderAttribute_t", "m_Values", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif