#include "../../../core/scripting/generated/classes/GCFilterProximity.h"
#include "../core.h"

void SetupLuaClassGCFilterProximity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFilterProximity>("CFilterProximity")
        .addProperty("Radius", &GCFilterProximity::GetRadius, &GCFilterProximity::SetRadius)
        .endClass();
}