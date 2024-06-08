#include "../../../core/scripting/generated/classes/GVoxelVisBlockOffset_t.h"
#include "../core.h"

void SetupLuaClassGVoxelVisBlockOffset_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVoxelVisBlockOffset_t>("VoxelVisBlockOffset_t")
        .addProperty("Offset", &GVoxelVisBlockOffset_t::GetOffset, &GVoxelVisBlockOffset_t::SetOffset)
        .addProperty("ElementCount", &GVoxelVisBlockOffset_t::GetElementCount, &GVoxelVisBlockOffset_t::SetElementCount)
        .endClass();
}