#include "../../../core/scripting/generated/classes/GCMaterialDrawDescriptor.h"
#include "../core.h"

void SetupLuaClassGCMaterialDrawDescriptor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMaterialDrawDescriptor>("CMaterialDrawDescriptor")
        .addProperty("UvDensity", &GCMaterialDrawDescriptor::GetUvDensity, &GCMaterialDrawDescriptor::SetUvDensity)
        .addProperty("TintColor", &GCMaterialDrawDescriptor::GetTintColor, &GCMaterialDrawDescriptor::SetTintColor)
        .addProperty("Alpha", &GCMaterialDrawDescriptor::GetAlpha, &GCMaterialDrawDescriptor::SetAlpha)
        .addProperty("FirstMeshlet", &GCMaterialDrawDescriptor::GetFirstMeshlet, &GCMaterialDrawDescriptor::SetFirstMeshlet)
        .addProperty("NumMeshlets", &GCMaterialDrawDescriptor::GetNumMeshlets, &GCMaterialDrawDescriptor::SetNumMeshlets)
        .addProperty("PrimitiveType", &GCMaterialDrawDescriptor::GetPrimitiveType, &GCMaterialDrawDescriptor::SetPrimitiveType)
        .addProperty("BaseVertex", &GCMaterialDrawDescriptor::GetBaseVertex, &GCMaterialDrawDescriptor::SetBaseVertex)
        .addProperty("VertexCount", &GCMaterialDrawDescriptor::GetVertexCount, &GCMaterialDrawDescriptor::SetVertexCount)
        .addProperty("StartIndex", &GCMaterialDrawDescriptor::GetStartIndex, &GCMaterialDrawDescriptor::SetStartIndex)
        .addProperty("IndexCount", &GCMaterialDrawDescriptor::GetIndexCount, &GCMaterialDrawDescriptor::SetIndexCount)
        .addProperty("IndexBuffer", &GCMaterialDrawDescriptor::GetIndexBuffer, &GCMaterialDrawDescriptor::SetIndexBuffer)
        .endClass();
}