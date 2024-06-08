#include "../../../core/scripting/generated/classes/GCBtActionParachutePositioning.h"
#include "../core.h"

void SetupLuaClassGCBtActionParachutePositioning(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBtActionParachutePositioning>("CBtActionParachutePositioning")
        .addProperty("ActionTimer", &GCBtActionParachutePositioning::GetActionTimer, &GCBtActionParachutePositioning::SetActionTimer)
        .endClass();
}