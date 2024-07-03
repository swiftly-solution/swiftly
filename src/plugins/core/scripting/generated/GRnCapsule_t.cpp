#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GRnCapsule_t::GRnCapsule_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GRnCapsule_t::GRnCapsule_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<Vector> GRnCapsule_t::GetCenter() const {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "RnCapsule_t", "m_vCenter"); std::vector<Vector> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GRnCapsule_t::SetCenter(std::vector<Vector> value) {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "RnCapsule_t", "m_vCenter"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "RnCapsule_t", "m_vCenter", true, outValue);
}
float GRnCapsule_t::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "RnCapsule_t", "m_flRadius");
}
void GRnCapsule_t::SetRadius(float value) {
    SetSchemaValue(m_ptr, "RnCapsule_t", "m_flRadius", true, value);
}
std::string GRnCapsule_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GRnCapsule_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassRnCapsule_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnCapsule_t>("RnCapsule_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Center", &GRnCapsule_t::GetCenter, &GRnCapsule_t::SetCenter)
        .addProperty("Radius", &GRnCapsule_t::GetRadius, &GRnCapsule_t::SetRadius)
        .addFunction("ToPtr", &GRnCapsule_t::ToPtr)
        .addFunction("IsValid", &GRnCapsule_t::IsValid)
        .endClass();
}