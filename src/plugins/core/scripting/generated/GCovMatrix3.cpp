#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCovMatrix3::GCovMatrix3(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCovMatrix3::GCovMatrix3(void *ptr) {
    m_ptr = ptr;
}
Vector GCovMatrix3::GetDiag() const {
    return GetSchemaValue<Vector>(m_ptr, "CovMatrix3", "m_vDiag");
}
void GCovMatrix3::SetDiag(Vector value) {
    SetSchemaValue(m_ptr, "CovMatrix3", "m_vDiag", false, value);
}
float GCovMatrix3::GetXY() const {
    return GetSchemaValue<float>(m_ptr, "CovMatrix3", "m_flXY");
}
void GCovMatrix3::SetXY(float value) {
    SetSchemaValue(m_ptr, "CovMatrix3", "m_flXY", false, value);
}
float GCovMatrix3::GetXZ() const {
    return GetSchemaValue<float>(m_ptr, "CovMatrix3", "m_flXZ");
}
void GCovMatrix3::SetXZ(float value) {
    SetSchemaValue(m_ptr, "CovMatrix3", "m_flXZ", false, value);
}
float GCovMatrix3::GetYZ() const {
    return GetSchemaValue<float>(m_ptr, "CovMatrix3", "m_flYZ");
}
void GCovMatrix3::SetYZ(float value) {
    SetSchemaValue(m_ptr, "CovMatrix3", "m_flYZ", false, value);
}
std::string GCovMatrix3::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCovMatrix3::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCovMatrix3(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCovMatrix3>("CovMatrix3")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Diag", &GCovMatrix3::GetDiag, &GCovMatrix3::SetDiag)
        .addProperty("XY", &GCovMatrix3::GetXY, &GCovMatrix3::SetXY)
        .addProperty("XZ", &GCovMatrix3::GetXZ, &GCovMatrix3::SetXZ)
        .addProperty("YZ", &GCovMatrix3::GetYZ, &GCovMatrix3::SetYZ)
        .addFunction("ToPtr", &GCovMatrix3::ToPtr)
        .addFunction("IsValid", &GCovMatrix3::IsValid)
        .endClass();
}