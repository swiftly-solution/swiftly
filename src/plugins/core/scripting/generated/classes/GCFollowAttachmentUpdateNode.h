class GCFollowAttachmentUpdateNode;

#ifndef _gccfollowattachmentupdatenode_h
#define _gccfollowattachmentupdatenode_h

#include "../../../scripting.h"


#include "GFollowAttachmentSettings_t.h"

class GCFollowAttachmentUpdateNode
{
private:
    void *m_ptr;

public:
    GCFollowAttachmentUpdateNode() {}
    GCFollowAttachmentUpdateNode(void *ptr) : m_ptr(ptr) {}

    GFollowAttachmentSettings_t GetOpFixedData() const { return GetSchemaValue<GFollowAttachmentSettings_t>(m_ptr, "CFollowAttachmentUpdateNode", "m_opFixedData"); }
    void SetOpFixedData(GFollowAttachmentSettings_t value) { SetSchemaValue(m_ptr, "CFollowAttachmentUpdateNode", "m_opFixedData", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif