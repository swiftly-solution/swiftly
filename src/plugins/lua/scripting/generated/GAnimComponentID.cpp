#include "../../../core/scripting/generated/classes/GAnimComponentID.h"
#include "../core.h"

void SetupLuaClassGAnimComponentID(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAnimComponentID>("AnimComponentID")
        .addProperty("Id", &GAnimComponentID::GetId, &GAnimComponentID::SetId)
        .endClass();
}