#include "../../../core/scripting/generated/classes/GCRemapFloat.h"
#include "../core.h"

void SetupLuaClassGCRemapFloat(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRemapFloat>("CRemapFloat")
        .addProperty("Value", &GCRemapFloat::GetValue, &GCRemapFloat::SetValue)
        .endClass();
}