#include "../../../core/scripting/generated/classes/GCFuncPlatRot.h"
#include "../core.h"

void SetupLuaClassGCFuncPlatRot(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncPlatRot>("CFuncPlatRot")
        .addProperty("End", &GCFuncPlatRot::GetEnd, &GCFuncPlatRot::SetEnd)
        .addProperty("Start", &GCFuncPlatRot::GetStart, &GCFuncPlatRot::SetStart)
        .endClass();
}