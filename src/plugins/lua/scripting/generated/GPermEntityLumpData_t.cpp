#include "../../../core/scripting/generated/classes/GPermEntityLumpData_t.h"
#include "../core.h"

void SetupLuaClassGPermEntityLumpData_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPermEntityLumpData_t>("PermEntityLumpData_t")
        .addProperty("Name", &GPermEntityLumpData_t::GetName, &GPermEntityLumpData_t::SetName)
        .endClass();
}