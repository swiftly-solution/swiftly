#include "../../../core/scripting/generated/classes/GCEnvDecal.h"
#include "../core.h"

void SetupLuaClassGCEnvDecal(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvDecal>("CEnvDecal")
        .addProperty("Width", &GCEnvDecal::GetWidth, &GCEnvDecal::SetWidth)
        .addProperty("Height", &GCEnvDecal::GetHeight, &GCEnvDecal::SetHeight)
        .addProperty("Depth", &GCEnvDecal::GetDepth, &GCEnvDecal::SetDepth)
        .addProperty("RenderOrder", &GCEnvDecal::GetRenderOrder, &GCEnvDecal::SetRenderOrder)
        .addProperty("ProjectOnWorld", &GCEnvDecal::GetProjectOnWorld, &GCEnvDecal::SetProjectOnWorld)
        .addProperty("ProjectOnCharacters", &GCEnvDecal::GetProjectOnCharacters, &GCEnvDecal::SetProjectOnCharacters)
        .addProperty("ProjectOnWater", &GCEnvDecal::GetProjectOnWater, &GCEnvDecal::SetProjectOnWater)
        .addProperty("DepthSortBias", &GCEnvDecal::GetDepthSortBias, &GCEnvDecal::SetDepthSortBias)
        .endClass();
}