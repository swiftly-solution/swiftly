#include "../../../core/scripting/generated/classes/GC_OP_RenderStatusEffectCitadel.h"
#include "../core.h"

void SetupLuaClassGC_OP_RenderStatusEffectCitadel(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RenderStatusEffectCitadel>("C_OP_RenderStatusEffectCitadel")

        .endClass();
}