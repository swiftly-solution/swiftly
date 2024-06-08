#include "../../../core/scripting/generated/classes/GC_OP_RadiusDecay.h"
#include "../core.h"

void SetupLuaClassGC_OP_RadiusDecay(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RadiusDecay>("C_OP_RadiusDecay")
        .addProperty("MinRadius", &GC_OP_RadiusDecay::GetMinRadius, &GC_OP_RadiusDecay::SetMinRadius)
        .endClass();
}