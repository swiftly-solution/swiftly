#include "../../../core/scripting/generated/classes/GAnimNodeID.h"
#include "../core.h"

void SetupLuaClassGAnimNodeID(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAnimNodeID>("AnimNodeID")
        .addProperty("Id", &GAnimNodeID::GetId, &GAnimNodeID::SetId)
        .endClass();
}