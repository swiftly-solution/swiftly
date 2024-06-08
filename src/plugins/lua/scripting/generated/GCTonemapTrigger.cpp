#include "../../../core/scripting/generated/classes/GCTonemapTrigger.h"
#include "../core.h"

void SetupLuaClassGCTonemapTrigger(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTonemapTrigger>("CTonemapTrigger")
        .addProperty("TonemapControllerName", &GCTonemapTrigger::GetTonemapControllerName, &GCTonemapTrigger::SetTonemapControllerName)
        .addProperty("TonemapController", &GCTonemapTrigger::GetTonemapController, &GCTonemapTrigger::SetTonemapController)
        .endClass();
}