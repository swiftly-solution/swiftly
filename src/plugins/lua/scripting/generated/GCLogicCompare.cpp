#include "../../../core/scripting/generated/classes/GCLogicCompare.h"
#include "../core.h"

void SetupLuaClassGCLogicCompare(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicCompare>("CLogicCompare")
        .addProperty("InValue", &GCLogicCompare::GetInValue, &GCLogicCompare::SetInValue)
        .addProperty("CompareValue", &GCLogicCompare::GetCompareValue, &GCLogicCompare::SetCompareValue)
        .endClass();
}