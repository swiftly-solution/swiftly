#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GAnimationSnapshot_t::GAnimationSnapshot_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GAnimationSnapshot_t::GAnimationSnapshot_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GAnimationSnapshot_t::GetEntIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "AnimationSnapshot_t", "m_nEntIndex");
}
void GAnimationSnapshot_t::SetEntIndex(int32_t value) {
    SetSchemaValue(m_ptr, "AnimationSnapshot_t", "m_nEntIndex", true, value);
}
std::string GAnimationSnapshot_t::GetModelName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "AnimationSnapshot_t", "m_modelName").Get();
}
void GAnimationSnapshot_t::SetModelName(std::string value) {
    SetSchemaValue(m_ptr, "AnimationSnapshot_t", "m_modelName", true, CUtlString(value.c_str()));
}
std::string GAnimationSnapshot_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GAnimationSnapshot_t::IsValid() {
    return (m_ptr != nullptr);
}
GAnimationSnapshotBase_t GAnimationSnapshot_t::GetParent() const {
    GAnimationSnapshotBase_t value(m_ptr);
    return value;
}
void GAnimationSnapshot_t::SetParent(GAnimationSnapshotBase_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassAnimationSnapshot_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAnimationSnapshot_t>("AnimationSnapshot_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("EntIndex", &GAnimationSnapshot_t::GetEntIndex, &GAnimationSnapshot_t::SetEntIndex)
        .addProperty("ModelName", &GAnimationSnapshot_t::GetModelName, &GAnimationSnapshot_t::SetModelName)
        .addProperty("Parent", &GAnimationSnapshot_t::GetParent, &GAnimationSnapshot_t::SetParent)
        .addFunction("ToPtr", &GAnimationSnapshot_t::ToPtr)
        .addFunction("IsValid", &GAnimationSnapshot_t::IsValid)
        .endClass();
}