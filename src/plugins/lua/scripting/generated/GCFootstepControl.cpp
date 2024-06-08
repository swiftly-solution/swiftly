#include "../../../core/scripting/generated/classes/GCFootstepControl.h"
#include "../core.h"

void SetupLuaClassGCFootstepControl(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootstepControl>("CFootstepControl")
        .addProperty("Source", &GCFootstepControl::GetSource, &GCFootstepControl::SetSource)
        .addProperty("Destination", &GCFootstepControl::GetDestination, &GCFootstepControl::SetDestination)
        .endClass();
}