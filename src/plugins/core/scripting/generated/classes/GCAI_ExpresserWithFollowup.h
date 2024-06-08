class GCAI_ExpresserWithFollowup;

#ifndef _gccai_expresserwithfollowup_h
#define _gccai_expresserwithfollowup_h

#include "../../../scripting.h"


#include "GResponseFollowup.h"

class GCAI_ExpresserWithFollowup
{
private:
    void *m_ptr;

public:
    GCAI_ExpresserWithFollowup() {}
    GCAI_ExpresserWithFollowup(void *ptr) : m_ptr(ptr) {}

    GResponseFollowup* GetPostponedFollowup() const { return GetSchemaValue<GResponseFollowup*>(m_ptr, "CAI_ExpresserWithFollowup", "m_pPostponedFollowup"); }
    void SetPostponedFollowup(GResponseFollowup* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'PostponedFollowup' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif