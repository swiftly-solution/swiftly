#include "../../../core/scripting/generated/classes/GCEconWearable.h"
#include "../core.h"

void SetupLuaClassGCEconWearable(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEconWearable>("CEconWearable")
        .addProperty("ForceSkin", &GCEconWearable::GetForceSkin, &GCEconWearable::SetForceSkin)
        .addProperty("AlwaysAllow", &GCEconWearable::GetAlwaysAllow, &GCEconWearable::SetAlwaysAllow)
        .endClass();
}