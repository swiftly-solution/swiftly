#include "../../../core/scripting/generated/classes/GAnimParamID.h"
#include "../core.h"

void SetupLuaClassGAnimParamID(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAnimParamID>("AnimParamID")
        .addProperty("Id", &GAnimParamID::GetId, &GAnimParamID::SetId)
        .endClass();
}