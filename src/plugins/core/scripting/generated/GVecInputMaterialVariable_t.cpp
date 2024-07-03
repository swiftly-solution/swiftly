#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVecInputMaterialVariable_t::GVecInputMaterialVariable_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVecInputMaterialVariable_t::GVecInputMaterialVariable_t(void *ptr) {
    m_ptr = ptr;
}
std::string GVecInputMaterialVariable_t::GetStrVariable() const {
    return GetSchemaValue<CUtlString>(m_ptr, "VecInputMaterialVariable_t", "m_strVariable").Get();
}
void GVecInputMaterialVariable_t::SetStrVariable(std::string value) {
    SetSchemaValue(m_ptr, "VecInputMaterialVariable_t", "m_strVariable", true, CUtlString(value.c_str()));
}
std::string GVecInputMaterialVariable_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVecInputMaterialVariable_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVecInputMaterialVariable_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVecInputMaterialVariable_t>("VecInputMaterialVariable_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StrVariable", &GVecInputMaterialVariable_t::GetStrVariable, &GVecInputMaterialVariable_t::SetStrVariable)
        .addFunction("ToPtr", &GVecInputMaterialVariable_t::ToPtr)
        .addFunction("IsValid", &GVecInputMaterialVariable_t::IsValid)
        .endClass();
}