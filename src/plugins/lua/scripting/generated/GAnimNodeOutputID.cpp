#include "../../../core/scripting/generated/classes/GAnimNodeOutputID.h"
#include "../core.h"

void SetupLuaClassGAnimNodeOutputID(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAnimNodeOutputID>("AnimNodeOutputID")
        .addProperty("Id", &GAnimNodeOutputID::GetId, &GAnimNodeOutputID::SetId)
        .endClass();
}