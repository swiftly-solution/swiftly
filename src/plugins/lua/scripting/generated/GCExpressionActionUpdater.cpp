#include "../../../core/scripting/generated/classes/GCExpressionActionUpdater.h"
#include "../core.h"

void SetupLuaClassGCExpressionActionUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCExpressionActionUpdater>("CExpressionActionUpdater")
        .addProperty("Param", &GCExpressionActionUpdater::GetParam, &GCExpressionActionUpdater::SetParam)
        .addProperty("ParamType", &GCExpressionActionUpdater::GetParamType, &GCExpressionActionUpdater::SetParamType)
        .addProperty("Script", &GCExpressionActionUpdater::GetScript, &GCExpressionActionUpdater::SetScript)
        .endClass();
}