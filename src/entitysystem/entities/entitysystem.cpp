#include "entitysystem.h"

CGameEntitySystem* GameEntitySystem()
{
    return g_pGameEntitySystem;
}

EXT_API void* swiftly_GameEntitySystem()
{
    return (void*)GameEntitySystem();
}