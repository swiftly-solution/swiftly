class GCItemDogtags;

#ifndef _gccitemdogtags_h
#define _gccitemdogtags_h

#include "../../../scripting.h"


#include "GCCSPlayerPawn.h"

class GCItemDogtags
{
private:
    void *m_ptr;

public:
    GCItemDogtags() {}
    GCItemDogtags(void *ptr) : m_ptr(ptr) {}

    GCCSPlayerPawn* GetOwningPlayer() const { return GetSchemaValue<GCCSPlayerPawn*>(m_ptr, "CItemDogtags", "m_OwningPlayer"); }
    void SetOwningPlayer(GCCSPlayerPawn* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'OwningPlayer' is not possible.\n"); }
    GCCSPlayerPawn* GetKillingPlayer() const { return GetSchemaValue<GCCSPlayerPawn*>(m_ptr, "CItemDogtags", "m_KillingPlayer"); }
    void SetKillingPlayer(GCCSPlayerPawn* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'KillingPlayer' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif