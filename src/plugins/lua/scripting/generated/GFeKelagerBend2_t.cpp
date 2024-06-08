#include "../../../core/scripting/generated/classes/GFeKelagerBend2_t.h"
#include "../core.h"

void SetupLuaClassGFeKelagerBend2_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeKelagerBend2_t>("FeKelagerBend2_t")
        .addProperty("Weight", &GFeKelagerBend2_t::GetWeight, &GFeKelagerBend2_t::SetWeight)
        .addProperty("Height0", &GFeKelagerBend2_t::GetHeight0, &GFeKelagerBend2_t::SetHeight0)
        .addProperty("Node", &GFeKelagerBend2_t::GetNode, &GFeKelagerBend2_t::SetNode)
        .addProperty("Reserved", &GFeKelagerBend2_t::GetReserved, &GFeKelagerBend2_t::SetReserved)
        .endClass();
}