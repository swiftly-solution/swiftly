#include "../../../core/scripting/generated/classes/GC_OP_DecayOffscreen.h"
#include "../core.h"

void SetupLuaClassGC_OP_DecayOffscreen(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_DecayOffscreen>("C_OP_DecayOffscreen")
        .addProperty("OffscreenTime", &GC_OP_DecayOffscreen::GetOffscreenTime, &GC_OP_DecayOffscreen::SetOffscreenTime)
        .endClass();
}