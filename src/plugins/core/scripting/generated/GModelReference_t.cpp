#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GModelReference_t::GModelReference_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GModelReference_t::GModelReference_t(void *ptr) {
    m_ptr = ptr;
}
float GModelReference_t::GetRelativeProbabilityOfSpawn() const {
    return GetSchemaValue<float>(m_ptr, "ModelReference_t", "m_flRelativeProbabilityOfSpawn");
}
void GModelReference_t::SetRelativeProbabilityOfSpawn(float value) {
    SetSchemaValue(m_ptr, "ModelReference_t", "m_flRelativeProbabilityOfSpawn", true, value);
}
std::string GModelReference_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GModelReference_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassModelReference_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GModelReference_t>("ModelReference_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("RelativeProbabilityOfSpawn", &GModelReference_t::GetRelativeProbabilityOfSpawn, &GModelReference_t::SetRelativeProbabilityOfSpawn)
        .addFunction("ToPtr", &GModelReference_t::ToPtr)
        .addFunction("IsValid", &GModelReference_t::IsValid)
        .endClass();
}