#include "../../../core/scripting/generated/classes/GCEnvBeverage.h"
#include "../core.h"

void SetupLuaClassGCEnvBeverage(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvBeverage>("CEnvBeverage")
        .addProperty("CanInDispenser", &GCEnvBeverage::GetCanInDispenser, &GCEnvBeverage::SetCanInDispenser)
        .addProperty("BeverageType", &GCEnvBeverage::GetBeverageType, &GCEnvBeverage::SetBeverageType)
        .endClass();
}