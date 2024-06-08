#include "../../../core/scripting/generated/classes/GCInfoInstructorHintTarget.h"
#include "../core.h"

void SetupLuaClassGCInfoInstructorHintTarget(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoInstructorHintTarget>("CInfoInstructorHintTarget")

        .endClass();
}