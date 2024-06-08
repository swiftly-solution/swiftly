class GCKnife;

#ifndef _gccknife_h
#define _gccknife_h

#include "../../../scripting.h"




class GCKnife
{
private:
    void *m_ptr;

public:
    GCKnife() {}
    GCKnife(void *ptr) : m_ptr(ptr) {}

    bool GetFirstAttack() const { return GetSchemaValue<bool>(m_ptr, "CKnife", "m_bFirstAttack"); }
    void SetFirstAttack(bool value) { SetSchemaValue(m_ptr, "CKnife", "m_bFirstAttack", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif