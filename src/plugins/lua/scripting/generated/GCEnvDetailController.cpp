#include "../../../core/scripting/generated/classes/GCEnvDetailController.h"
#include "../core.h"

void SetupLuaClassGCEnvDetailController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvDetailController>("CEnvDetailController")
        .addProperty("FadeStartDist", &GCEnvDetailController::GetFadeStartDist, &GCEnvDetailController::SetFadeStartDist)
        .addProperty("FadeEndDist", &GCEnvDetailController::GetFadeEndDist, &GCEnvDetailController::SetFadeEndDist)
        .endClass();
}