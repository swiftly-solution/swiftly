#include "../../../core/scripting/generated/classes/GCRangeFloat.h"
#include "../core.h"

void SetupLuaClassGCRangeFloat(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRangeFloat>("CRangeFloat")
        .addProperty("Value", &GCRangeFloat::GetValue, &GCRangeFloat::SetValue)
        .endClass();
}