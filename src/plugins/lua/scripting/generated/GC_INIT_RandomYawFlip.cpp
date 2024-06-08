#include "../../../core/scripting/generated/classes/GC_INIT_RandomYawFlip.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RandomYawFlip(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RandomYawFlip>("C_INIT_RandomYawFlip")
        .addProperty("Percent", &GC_INIT_RandomYawFlip::GetPercent, &GC_INIT_RandomYawFlip::SetPercent)
        .endClass();
}