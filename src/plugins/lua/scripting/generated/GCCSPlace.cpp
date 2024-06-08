#include "../../../core/scripting/generated/classes/GCCSPlace.h"
#include "../core.h"

void SetupLuaClassGCCSPlace(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlace>("CCSPlace")
        .addProperty("Name", &GCCSPlace::GetName, &GCCSPlace::SetName)
        .endClass();
}