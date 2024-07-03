#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCHitboxComponent::GCHitboxComponent(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCHitboxComponent::GCHitboxComponent(void *ptr) {
    m_ptr = ptr;
}
std::vector<uint32_t> GCHitboxComponent::GetDisabledHitGroups() const {
    uint32_t* outValue = GetSchemaValue<uint32_t*>(m_ptr, "CHitboxComponent", "m_bvDisabledHitGroups"); std::vector<uint32_t> ret; for(int i = 0; i < 1; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCHitboxComponent::SetDisabledHitGroups(std::vector<uint32_t> value) {
    uint32_t* outValue = GetSchemaValue<uint32_t*>(m_ptr, "CHitboxComponent", "m_bvDisabledHitGroups"); for(int i = 0; i < 1; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CHitboxComponent", "m_bvDisabledHitGroups", false, outValue);
}
std::string GCHitboxComponent::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCHitboxComponent::IsValid() {
    return (m_ptr != nullptr);
}
GCEntityComponent GCHitboxComponent::GetParent() const {
    GCEntityComponent value(m_ptr);
    return value;
}
void GCHitboxComponent::SetParent(GCEntityComponent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCHitboxComponent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHitboxComponent>("CHitboxComponent")
        .addConstructor<void (*)(std::string)>()
        .addProperty("DisabledHitGroups", &GCHitboxComponent::GetDisabledHitGroups, &GCHitboxComponent::SetDisabledHitGroups)
        .addProperty("Parent", &GCHitboxComponent::GetParent, &GCHitboxComponent::SetParent)
        .addFunction("ToPtr", &GCHitboxComponent::ToPtr)
        .addFunction("IsValid", &GCHitboxComponent::IsValid)
        .endClass();
}