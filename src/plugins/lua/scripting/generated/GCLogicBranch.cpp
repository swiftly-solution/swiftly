#include "../../../core/scripting/generated/classes/GCLogicBranch.h"
#include "../core.h"

void SetupLuaClassGCLogicBranch(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicBranch>("CLogicBranch")
        .addProperty("InValue", &GCLogicBranch::GetInValue, &GCLogicBranch::SetInValue)
        .addProperty("OnTrue", &GCLogicBranch::GetOnTrue, &GCLogicBranch::SetOnTrue)
        .addProperty("OnFalse", &GCLogicBranch::GetOnFalse, &GCLogicBranch::SetOnFalse)
        .endClass();
}