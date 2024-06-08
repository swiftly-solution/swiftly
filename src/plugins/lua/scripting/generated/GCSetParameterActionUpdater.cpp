#include "../../../core/scripting/generated/classes/GCSetParameterActionUpdater.h"
#include "../core.h"

void SetupLuaClassGCSetParameterActionUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSetParameterActionUpdater>("CSetParameterActionUpdater")
        .addProperty("Param", &GCSetParameterActionUpdater::GetParam, &GCSetParameterActionUpdater::SetParam)
        .endClass();
}