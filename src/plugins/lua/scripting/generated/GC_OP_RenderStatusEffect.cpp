#include "../../../core/scripting/generated/classes/GC_OP_RenderStatusEffect.h"
#include "../core.h"

void SetupLuaClassGC_OP_RenderStatusEffect(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RenderStatusEffect>("C_OP_RenderStatusEffect")

        .endClass();
}