#include "../../../core/scripting/generated/classes/GCInfoInstructorHintBombTargetB.h"
#include "../core.h"

void SetupLuaClassGCInfoInstructorHintBombTargetB(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoInstructorHintBombTargetB>("CInfoInstructorHintBombTargetB")

        .endClass();
}