#include "../../../core/scripting/generated/classes/GC_INIT_CreateFromCPs.h"
#include "../core.h"

void SetupLuaClassGC_INIT_CreateFromCPs(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_CreateFromCPs>("C_INIT_CreateFromCPs")
        .addProperty("Increment", &GC_INIT_CreateFromCPs::GetIncrement, &GC_INIT_CreateFromCPs::SetIncrement)
        .addProperty("MinCP", &GC_INIT_CreateFromCPs::GetMinCP, &GC_INIT_CreateFromCPs::SetMinCP)
        .addProperty("MaxCP", &GC_INIT_CreateFromCPs::GetMaxCP, &GC_INIT_CreateFromCPs::SetMaxCP)
        .addProperty("DynamicCPCount", &GC_INIT_CreateFromCPs::GetDynamicCPCount, &GC_INIT_CreateFromCPs::SetDynamicCPCount)
        .endClass();
}