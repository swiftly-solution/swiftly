#include "../../../core/scripting/generated/classes/GCAnimGraphModelBinding.h"
#include "../core.h"

void SetupLuaClassGCAnimGraphModelBinding(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimGraphModelBinding>("CAnimGraphModelBinding")
        .addProperty("ModelName", &GCAnimGraphModelBinding::GetModelName, &GCAnimGraphModelBinding::SetModelName)
        .endClass();
}