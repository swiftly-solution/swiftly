#include "../../../core/scripting/generated/classes/GCAnimUserDifference.h"
#include "../core.h"

void SetupLuaClassGCAnimUserDifference(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimUserDifference>("CAnimUserDifference")
        .addProperty("Name", &GCAnimUserDifference::GetName, &GCAnimUserDifference::SetName)
        .addProperty("Type", &GCAnimUserDifference::GetType, &GCAnimUserDifference::SetType)
        .endClass();
}