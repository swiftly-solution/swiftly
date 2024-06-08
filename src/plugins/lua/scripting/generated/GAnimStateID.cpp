#include "../../../core/scripting/generated/classes/GAnimStateID.h"
#include "../core.h"

void SetupLuaClassGAnimStateID(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAnimStateID>("AnimStateID")
        .addProperty("Id", &GAnimStateID::GetId, &GAnimStateID::SetId)
        .endClass();
}