#include "../../../core/scripting/generated/classes/GFeNodeWindBase_t.h"
#include "../core.h"

void SetupLuaClassGFeNodeWindBase_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeNodeWindBase_t>("FeNodeWindBase_t")
        .addProperty("NodeX0", &GFeNodeWindBase_t::GetNodeX0, &GFeNodeWindBase_t::SetNodeX0)
        .addProperty("NodeX1", &GFeNodeWindBase_t::GetNodeX1, &GFeNodeWindBase_t::SetNodeX1)
        .addProperty("NodeY0", &GFeNodeWindBase_t::GetNodeY0, &GFeNodeWindBase_t::SetNodeY0)
        .addProperty("NodeY1", &GFeNodeWindBase_t::GetNodeY1, &GFeNodeWindBase_t::SetNodeY1)
        .endClass();
}