#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRenderComponent::GCRenderComponent(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRenderComponent::GCRenderComponent(void *ptr) {
    m_ptr = ptr;
}
GCNetworkVarChainer GCRenderComponent::Get__pChainEntity() const {
    GCNetworkVarChainer value(GetSchemaPtr(m_ptr, "CRenderComponent", "__m_pChainEntity"));
    return value;
}
void GCRenderComponent::Set__pChainEntity(GCNetworkVarChainer value) {
    SetSchemaValue(m_ptr, "CRenderComponent", "__m_pChainEntity", false, value);
}
bool GCRenderComponent::GetIsRenderingWithViewModels() const {
    return GetSchemaValue<bool>(m_ptr, "CRenderComponent", "m_bIsRenderingWithViewModels");
}
void GCRenderComponent::SetIsRenderingWithViewModels(bool value) {
    SetSchemaValue(m_ptr, "CRenderComponent", "m_bIsRenderingWithViewModels", false, value);
}
uint32_t GCRenderComponent::GetSplitscreenFlags() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CRenderComponent", "m_nSplitscreenFlags");
}
void GCRenderComponent::SetSplitscreenFlags(uint32_t value) {
    SetSchemaValue(m_ptr, "CRenderComponent", "m_nSplitscreenFlags", false, value);
}
bool GCRenderComponent::GetEnableRendering() const {
    return GetSchemaValue<bool>(m_ptr, "CRenderComponent", "m_bEnableRendering");
}
void GCRenderComponent::SetEnableRendering(bool value) {
    SetSchemaValue(m_ptr, "CRenderComponent", "m_bEnableRendering", false, value);
}
bool GCRenderComponent::GetInterpolationReadyToDraw() const {
    return GetSchemaValue<bool>(m_ptr, "CRenderComponent", "m_bInterpolationReadyToDraw");
}
void GCRenderComponent::SetInterpolationReadyToDraw(bool value) {
    SetSchemaValue(m_ptr, "CRenderComponent", "m_bInterpolationReadyToDraw", false, value);
}
std::string GCRenderComponent::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRenderComponent::IsValid() {
    return (m_ptr != nullptr);
}
GCEntityComponent GCRenderComponent::GetParent() const {
    GCEntityComponent value(m_ptr);
    return value;
}
void GCRenderComponent::SetParent(GCEntityComponent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCRenderComponent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRenderComponent>("CRenderComponent")
        .addConstructor<void (*)(std::string)>()
        .addProperty("__pChainEntity", &GCRenderComponent::Get__pChainEntity, &GCRenderComponent::Set__pChainEntity)
        .addProperty("IsRenderingWithViewModels", &GCRenderComponent::GetIsRenderingWithViewModels, &GCRenderComponent::SetIsRenderingWithViewModels)
        .addProperty("SplitscreenFlags", &GCRenderComponent::GetSplitscreenFlags, &GCRenderComponent::SetSplitscreenFlags)
        .addProperty("EnableRendering", &GCRenderComponent::GetEnableRendering, &GCRenderComponent::SetEnableRendering)
        .addProperty("InterpolationReadyToDraw", &GCRenderComponent::GetInterpolationReadyToDraw, &GCRenderComponent::SetInterpolationReadyToDraw)
        .addProperty("Parent", &GCRenderComponent::GetParent, &GCRenderComponent::SetParent)
        .addFunction("ToPtr", &GCRenderComponent::ToPtr)
        .addFunction("IsValid", &GCRenderComponent::IsValid)
        .endClass();
}