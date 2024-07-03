#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GLookAtBone_t::GLookAtBone_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GLookAtBone_t::GLookAtBone_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GLookAtBone_t::GetIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "LookAtBone_t", "m_index");
}
void GLookAtBone_t::SetIndex(int32_t value) {
    SetSchemaValue(m_ptr, "LookAtBone_t", "m_index", true, value);
}
float GLookAtBone_t::GetWeight() const {
    return GetSchemaValue<float>(m_ptr, "LookAtBone_t", "m_weight");
}
void GLookAtBone_t::SetWeight(float value) {
    SetSchemaValue(m_ptr, "LookAtBone_t", "m_weight", true, value);
}
std::string GLookAtBone_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GLookAtBone_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassLookAtBone_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GLookAtBone_t>("LookAtBone_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Index", &GLookAtBone_t::GetIndex, &GLookAtBone_t::SetIndex)
        .addProperty("Weight", &GLookAtBone_t::GetWeight, &GLookAtBone_t::SetWeight)
        .addFunction("ToPtr", &GLookAtBone_t::ToPtr)
        .addFunction("IsValid", &GLookAtBone_t::IsValid)
        .endClass();
}