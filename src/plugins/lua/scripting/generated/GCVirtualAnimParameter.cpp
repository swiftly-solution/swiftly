#include "../../../core/scripting/generated/classes/GCVirtualAnimParameter.h"
#include "../core.h"

void SetupLuaClassGCVirtualAnimParameter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVirtualAnimParameter>("CVirtualAnimParameter")
        .addProperty("ExpressionString", &GCVirtualAnimParameter::GetExpressionString, &GCVirtualAnimParameter::SetExpressionString)
        .addProperty("ParamType", &GCVirtualAnimParameter::GetParamType, &GCVirtualAnimParameter::SetParamType)
        .endClass();
}