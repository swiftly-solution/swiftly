#include "../../../core/scripting/generated/classes/GCStateNodeTransitionData.h"
#include "../core.h"

void SetupLuaClassGCStateNodeTransitionData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCStateNodeTransitionData>("CStateNodeTransitionData")
        .addProperty("Curve", &GCStateNodeTransitionData::GetCurve, &GCStateNodeTransitionData::SetCurve)
        .endClass();
}