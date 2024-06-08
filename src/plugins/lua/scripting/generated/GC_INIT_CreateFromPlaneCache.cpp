#include "../../../core/scripting/generated/classes/GC_INIT_CreateFromPlaneCache.h"
#include "../core.h"

void SetupLuaClassGC_INIT_CreateFromPlaneCache(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_CreateFromPlaneCache>("C_INIT_CreateFromPlaneCache")
        .addProperty("OffsetMin", &GC_INIT_CreateFromPlaneCache::GetOffsetMin, &GC_INIT_CreateFromPlaneCache::SetOffsetMin)
        .addProperty("OffsetMax", &GC_INIT_CreateFromPlaneCache::GetOffsetMax, &GC_INIT_CreateFromPlaneCache::SetOffsetMax)
        .addProperty("UseNormal", &GC_INIT_CreateFromPlaneCache::GetUseNormal, &GC_INIT_CreateFromPlaneCache::SetUseNormal)
        .endClass();
}