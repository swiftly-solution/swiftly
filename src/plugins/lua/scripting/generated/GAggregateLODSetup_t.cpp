#include "../../../core/scripting/generated/classes/GAggregateLODSetup_t.h"
#include "../core.h"

void SetupLuaClassGAggregateLODSetup_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAggregateLODSetup_t>("AggregateLODSetup_t")
        .addProperty("LODOrigin", &GAggregateLODSetup_t::GetLODOrigin, &GAggregateLODSetup_t::SetLODOrigin)
        .addProperty("MaxObjectScale", &GAggregateLODSetup_t::GetMaxObjectScale, &GAggregateLODSetup_t::SetMaxObjectScale)
        .addProperty("SwitchDistances", &GAggregateLODSetup_t::GetSwitchDistances, &GAggregateLODSetup_t::SetSwitchDistances)
        .endClass();
}