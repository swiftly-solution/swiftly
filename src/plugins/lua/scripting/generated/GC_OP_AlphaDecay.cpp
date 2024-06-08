#include "../../../core/scripting/generated/classes/GC_OP_AlphaDecay.h"
#include "../core.h"

void SetupLuaClassGC_OP_AlphaDecay(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_AlphaDecay>("C_OP_AlphaDecay")
        .addProperty("MinAlpha", &GC_OP_AlphaDecay::GetMinAlpha, &GC_OP_AlphaDecay::SetMinAlpha)
        .endClass();
}