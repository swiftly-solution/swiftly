class GCollisionGroupContext_t;

#ifndef _gccollisiongroupcontext_t_h
#define _gccollisiongroupcontext_t_h

#include "../../../scripting.h"




class GCollisionGroupContext_t
{
private:
    void *m_ptr;

public:
    GCollisionGroupContext_t() {}
    GCollisionGroupContext_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetCollisionGroupNumber() const { return GetSchemaValue<int32_t>(m_ptr, "CollisionGroupContext_t", "m_nCollisionGroupNumber"); }
    void SetCollisionGroupNumber(int32_t value) { SetSchemaValue(m_ptr, "CollisionGroupContext_t", "m_nCollisionGroupNumber", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif