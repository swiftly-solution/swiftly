#include "../../../core/scripting/generated/classes/GCFilterClass.h"
#include "../core.h"

void SetupLuaClassGCFilterClass(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFilterClass>("CFilterClass")
        .addProperty("FilterClass", &GCFilterClass::GetFilterClass, &GCFilterClass::SetFilterClass)
        .endClass();
}