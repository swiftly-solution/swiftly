#include "../../../core/scripting/generated/classes/GCDSPPresetMixgroupModifierTable.h"
#include "../core.h"

void SetupLuaClassGCDSPPresetMixgroupModifierTable(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDSPPresetMixgroupModifierTable>("CDSPPresetMixgroupModifierTable")
        .addProperty("Table", &GCDSPPresetMixgroupModifierTable::GetTable, &GCDSPPresetMixgroupModifierTable::SetTable)
        .endClass();
}