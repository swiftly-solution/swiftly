#include "../../../core/scripting/generated/classes/GCRotDoor.h"
#include "../core.h"

void SetupLuaClassGCRotDoor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRotDoor>("CRotDoor")
        .addProperty("SolidBsp", &GCRotDoor::GetSolidBsp, &GCRotDoor::SetSolidBsp)
        .endClass();
}