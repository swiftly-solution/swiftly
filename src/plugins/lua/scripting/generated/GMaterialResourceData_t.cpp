#include "../../../core/scripting/generated/classes/GMaterialResourceData_t.h"
#include "../core.h"

void SetupLuaClassGMaterialResourceData_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GMaterialResourceData_t>("MaterialResourceData_t")
        .addProperty("MaterialName", &GMaterialResourceData_t::GetMaterialName, &GMaterialResourceData_t::SetMaterialName)
        .addProperty("ShaderName", &GMaterialResourceData_t::GetShaderName, &GMaterialResourceData_t::SetShaderName)
        .addProperty("IntParams", &GMaterialResourceData_t::GetIntParams, &GMaterialResourceData_t::SetIntParams)
        .addProperty("FloatParams", &GMaterialResourceData_t::GetFloatParams, &GMaterialResourceData_t::SetFloatParams)
        .addProperty("VectorParams", &GMaterialResourceData_t::GetVectorParams, &GMaterialResourceData_t::SetVectorParams)
        .addProperty("TextureParams", &GMaterialResourceData_t::GetTextureParams, &GMaterialResourceData_t::SetTextureParams)
        .addProperty("DynamicParams", &GMaterialResourceData_t::GetDynamicParams, &GMaterialResourceData_t::SetDynamicParams)
        .addProperty("DynamicTextureParams", &GMaterialResourceData_t::GetDynamicTextureParams, &GMaterialResourceData_t::SetDynamicTextureParams)
        .addProperty("IntAttributes", &GMaterialResourceData_t::GetIntAttributes, &GMaterialResourceData_t::SetIntAttributes)
        .addProperty("FloatAttributes", &GMaterialResourceData_t::GetFloatAttributes, &GMaterialResourceData_t::SetFloatAttributes)
        .addProperty("VectorAttributes", &GMaterialResourceData_t::GetVectorAttributes, &GMaterialResourceData_t::SetVectorAttributes)
        .addProperty("TextureAttributes", &GMaterialResourceData_t::GetTextureAttributes, &GMaterialResourceData_t::SetTextureAttributes)
        .addProperty("StringAttributes", &GMaterialResourceData_t::GetStringAttributes, &GMaterialResourceData_t::SetStringAttributes)
        .addProperty("RenderAttributesUsed", &GMaterialResourceData_t::GetRenderAttributesUsed, &GMaterialResourceData_t::SetRenderAttributesUsed)
        .endClass();
}