#include "../../../core/scripting/generated/classes/GCFogController.h"
#include "../core.h"

void SetupLuaClassGCFogController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFogController>("CFogController")
        .addProperty("Fog", &GCFogController::GetFog, &GCFogController::SetFog)
        .addProperty("UseAngles", &GCFogController::GetUseAngles, &GCFogController::SetUseAngles)
        .addProperty("ChangedVariables", &GCFogController::GetChangedVariables, &GCFogController::SetChangedVariables)
        .endClass();
}