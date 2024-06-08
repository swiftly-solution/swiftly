#include "../../../core/scripting/generated/classes/GCInfoInstructorHintHostageRescueZone.h"
#include "../core.h"

void SetupLuaClassGCInfoInstructorHintHostageRescueZone(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoInstructorHintHostageRescueZone>("CInfoInstructorHintHostageRescueZone")

        .endClass();
}