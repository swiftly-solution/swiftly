class GGeneratedTextureHandle_t;

#ifndef _gcgeneratedtexturehandle_t_h
#define _gcgeneratedtexturehandle_t_h

#include "../../../scripting.h"




class GGeneratedTextureHandle_t
{
private:
    void *m_ptr;

public:
    GGeneratedTextureHandle_t() {}
    GGeneratedTextureHandle_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetStrBitmapName() const { return GetSchemaValue<CUtlString>(m_ptr, "GeneratedTextureHandle_t", "m_strBitmapName"); }
    void SetStrBitmapName(CUtlString value) { SetSchemaValue(m_ptr, "GeneratedTextureHandle_t", "m_strBitmapName", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif