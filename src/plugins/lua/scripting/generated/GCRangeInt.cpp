#include "../../../core/scripting/generated/classes/GCRangeInt.h"
#include "../core.h"

void SetupLuaClassGCRangeInt(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRangeInt>("CRangeInt")
        .addProperty("Value", &GCRangeInt::GetValue, &GCRangeInt::SetValue)
        .endClass();
}