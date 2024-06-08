#include "../../../core/scripting/generated/classes/GNodeData_t.h"
#include "../core.h"

void SetupLuaClassGNodeData_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GNodeData_t>("NodeData_t")
        .addProperty("Parent", &GNodeData_t::GetParent, &GNodeData_t::SetParent)
        .addProperty("Origin", &GNodeData_t::GetOrigin, &GNodeData_t::SetOrigin)
        .addProperty("MinBounds", &GNodeData_t::GetMinBounds, &GNodeData_t::SetMinBounds)
        .addProperty("MaxBounds", &GNodeData_t::GetMaxBounds, &GNodeData_t::SetMaxBounds)
        .addProperty("MinimumDistance", &GNodeData_t::GetMinimumDistance, &GNodeData_t::SetMinimumDistance)
        .addProperty("ChildNodeIndices", &GNodeData_t::GetChildNodeIndices, &GNodeData_t::SetChildNodeIndices)
        .addProperty("WorldNodePrefix", &GNodeData_t::GetWorldNodePrefix, &GNodeData_t::SetWorldNodePrefix)
        .endClass();
}