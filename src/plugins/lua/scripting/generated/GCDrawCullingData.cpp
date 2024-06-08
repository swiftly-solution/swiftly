#include "../../../core/scripting/generated/classes/GCDrawCullingData.h"
#include "../core.h"

void SetupLuaClassGCDrawCullingData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDrawCullingData>("CDrawCullingData")
        .addProperty("ConeApex", &GCDrawCullingData::GetConeApex, &GCDrawCullingData::SetConeApex)
        .addProperty("ConeAxis", &GCDrawCullingData::GetConeAxis, &GCDrawCullingData::SetConeAxis)
        .addProperty("ConeCutoff", &GCDrawCullingData::GetConeCutoff, &GCDrawCullingData::SetConeCutoff)
        .endClass();
}