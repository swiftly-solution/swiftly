class GCFuncVPhysicsClip;

#ifndef _gccfuncvphysicsclip_h
#define _gccfuncvphysicsclip_h

#include "../../../scripting.h"




class GCFuncVPhysicsClip
{
private:
    void *m_ptr;

public:
    GCFuncVPhysicsClip() {}
    GCFuncVPhysicsClip(void *ptr) : m_ptr(ptr) {}

    bool GetDisabled() const { return GetSchemaValue<bool>(m_ptr, "CFuncVPhysicsClip", "m_bDisabled"); }
    void SetDisabled(bool value) { SetSchemaValue(m_ptr, "CFuncVPhysicsClip", "m_bDisabled", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif