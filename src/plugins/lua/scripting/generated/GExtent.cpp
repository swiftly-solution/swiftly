#include "../../../core/scripting/generated/classes/GExtent.h"
#include "../core.h"

void SetupLuaClassGExtent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GExtent>("Extent")
        .addProperty("Lo", &GExtent::GetLo, &GExtent::SetLo)
        .addProperty("Hi", &GExtent::GetHi, &GExtent::SetHi)
        .endClass();
}