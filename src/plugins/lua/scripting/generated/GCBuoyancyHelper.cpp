#include "../../../core/scripting/generated/classes/GCBuoyancyHelper.h"
#include "../core.h"

void SetupLuaClassGCBuoyancyHelper(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBuoyancyHelper>("CBuoyancyHelper")
        .addProperty("FluidDensity", &GCBuoyancyHelper::GetFluidDensity, &GCBuoyancyHelper::SetFluidDensity)
        .endClass();
}