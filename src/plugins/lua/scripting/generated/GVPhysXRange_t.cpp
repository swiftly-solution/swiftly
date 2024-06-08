#include "../../../core/scripting/generated/classes/GVPhysXRange_t.h"
#include "../core.h"

void SetupLuaClassGVPhysXRange_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVPhysXRange_t>("VPhysXRange_t")
        .addProperty("Min", &GVPhysXRange_t::GetMin, &GVPhysXRange_t::SetMin)
        .addProperty("Max", &GVPhysXRange_t::GetMax, &GVPhysXRange_t::SetMax)
        .endClass();
}