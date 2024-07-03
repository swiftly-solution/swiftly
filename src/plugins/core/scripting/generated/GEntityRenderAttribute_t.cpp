#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEntityRenderAttribute_t::GEntityRenderAttribute_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEntityRenderAttribute_t::GEntityRenderAttribute_t(void *ptr) {
    m_ptr = ptr;
}
CUtlStringToken GEntityRenderAttribute_t::GetID() const {
    return GetSchemaValue<CUtlStringToken>(m_ptr, "EntityRenderAttribute_t", "m_ID");
}
void GEntityRenderAttribute_t::SetID(CUtlStringToken value) {
    SetSchemaValue(m_ptr, "EntityRenderAttribute_t", "m_ID", true, value);
}
Vector4D GEntityRenderAttribute_t::GetValues() const {
    return GetSchemaValue<Vector4D>(m_ptr, "EntityRenderAttribute_t", "m_Values");
}
void GEntityRenderAttribute_t::SetValues(Vector4D value) {
    SetSchemaValue(m_ptr, "EntityRenderAttribute_t", "m_Values", true, value);
}
std::string GEntityRenderAttribute_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEntityRenderAttribute_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassEntityRenderAttribute_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEntityRenderAttribute_t>("EntityRenderAttribute_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ID", &GEntityRenderAttribute_t::GetID, &GEntityRenderAttribute_t::SetID)
        .addProperty("Values", &GEntityRenderAttribute_t::GetValues, &GEntityRenderAttribute_t::SetValues)
        .addFunction("ToPtr", &GEntityRenderAttribute_t::ToPtr)
        .addFunction("IsValid", &GEntityRenderAttribute_t::IsValid)
        .endClass();
}