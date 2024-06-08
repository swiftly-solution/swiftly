#include "../../../core/scripting/generated/classes/GCInfoInstructorHintBombTargetA.h"
#include "../core.h"

void SetupLuaClassGCInfoInstructorHintBombTargetA(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoInstructorHintBombTargetA>("CInfoInstructorHintBombTargetA")

        .endClass();
}