#include "../../../core/scripting/generated/classes/GCInfoPlayerStart.h"
#include "../core.h"

void SetupLuaClassGCInfoPlayerStart(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoPlayerStart>("CInfoPlayerStart")
        .addProperty("Disabled", &GCInfoPlayerStart::GetDisabled, &GCInfoPlayerStart::SetDisabled)
        .endClass();
}