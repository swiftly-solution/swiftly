#include "../../../core/scripting/generated/classes/GFeVertexMapDesc_t.h"
#include "../core.h"

void SetupLuaClassGFeVertexMapDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeVertexMapDesc_t>("FeVertexMapDesc_t")
        .addProperty("Name", &GFeVertexMapDesc_t::GetName, &GFeVertexMapDesc_t::SetName)
        .addProperty("NameHash", &GFeVertexMapDesc_t::GetNameHash, &GFeVertexMapDesc_t::SetNameHash)
        .addProperty("Color", &GFeVertexMapDesc_t::GetColor, &GFeVertexMapDesc_t::SetColor)
        .addProperty("Flags", &GFeVertexMapDesc_t::GetFlags, &GFeVertexMapDesc_t::SetFlags)
        .addProperty("VertexBase", &GFeVertexMapDesc_t::GetVertexBase, &GFeVertexMapDesc_t::SetVertexBase)
        .addProperty("VertexCount", &GFeVertexMapDesc_t::GetVertexCount, &GFeVertexMapDesc_t::SetVertexCount)
        .addProperty("MapOffset", &GFeVertexMapDesc_t::GetMapOffset, &GFeVertexMapDesc_t::SetMapOffset)
        .addProperty("NodeListOffset", &GFeVertexMapDesc_t::GetNodeListOffset, &GFeVertexMapDesc_t::SetNodeListOffset)
        .addProperty("CenterOfMass", &GFeVertexMapDesc_t::GetCenterOfMass, &GFeVertexMapDesc_t::SetCenterOfMass)
        .addProperty("VolumetricSolveStrength", &GFeVertexMapDesc_t::GetVolumetricSolveStrength, &GFeVertexMapDesc_t::SetVolumetricSolveStrength)
        .addProperty("ScaleSourceNode", &GFeVertexMapDesc_t::GetScaleSourceNode, &GFeVertexMapDesc_t::SetScaleSourceNode)
        .addProperty("NodeListCount", &GFeVertexMapDesc_t::GetNodeListCount, &GFeVertexMapDesc_t::SetNodeListCount)
        .endClass();
}