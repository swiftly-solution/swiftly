#include "../../../core/scripting/generated/classes/GCAnimUser.h"
#include "../core.h"

void SetupLuaClassGCAnimUser(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimUser>("CAnimUser")
        .addProperty("Name", &GCAnimUser::GetName, &GCAnimUser::SetName)
        .addProperty("Type", &GCAnimUser::GetType, &GCAnimUser::SetType)
        .endClass();
}