#include "../../../core/scripting/generated/classes/GTestResource_t.h"
#include "../core.h"

void SetupLuaClassGTestResource_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GTestResource_t>("TestResource_t")
        .addProperty("Name", &GTestResource_t::GetName, &GTestResource_t::SetName)
        .endClass();
}