#include "../../../core/scripting/generated/classes/GFeFitWeight_t.h"
#include "../core.h"

void SetupLuaClassGFeFitWeight_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeFitWeight_t>("FeFitWeight_t")
        .addProperty("Weight", &GFeFitWeight_t::GetWeight, &GFeFitWeight_t::SetWeight)
        .addProperty("Node", &GFeFitWeight_t::GetNode, &GFeFitWeight_t::SetNode)
        .addProperty("Dummy", &GFeFitWeight_t::GetDummy, &GFeFitWeight_t::SetDummy)
        .endClass();
}