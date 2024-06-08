class GCHandshakeAnimTagBase;

#ifndef _gcchandshakeanimtagbase_h
#define _gcchandshakeanimtagbase_h

#include "../../../scripting.h"




class GCHandshakeAnimTagBase
{
private:
    void *m_ptr;

public:
    GCHandshakeAnimTagBase() {}
    GCHandshakeAnimTagBase(void *ptr) : m_ptr(ptr) {}

    bool GetIsDisableTag() const { return GetSchemaValue<bool>(m_ptr, "CHandshakeAnimTagBase", "m_bIsDisableTag"); }
    void SetIsDisableTag(bool value) { SetSchemaValue(m_ptr, "CHandshakeAnimTagBase", "m_bIsDisableTag", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif