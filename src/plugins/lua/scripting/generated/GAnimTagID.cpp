#include "../../../core/scripting/generated/classes/GAnimTagID.h"
#include "../core.h"

void SetupLuaClassGAnimTagID(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAnimTagID>("AnimTagID")
        .addProperty("Id", &GAnimTagID::GetId, &GAnimTagID::SetId)
        .endClass();
}