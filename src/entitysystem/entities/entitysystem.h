#ifndef _entity_system_h
#define _entity_system_h

#include "../../entrypoint.h"
#include "../../memory/signatures/Offsets.h"

class CGameResourceService
{
public:
    CGameEntitySystem* GetGameEntitySystem()
    {
        return *reinterpret_cast<CGameEntitySystem**>((uintptr_t)(this) + g_Offsets->GetOffset("GameEntitySystem"));
    }
};

#endif