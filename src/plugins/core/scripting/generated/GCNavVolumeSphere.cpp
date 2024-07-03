#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNavVolumeSphere::GCNavVolumeSphere(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNavVolumeSphere::GCNavVolumeSphere(void *ptr) {
    m_ptr = ptr;
}
Vector GCNavVolumeSphere::GetCenter() const {
    return GetSchemaValue<Vector>(m_ptr, "CNavVolumeSphere", "m_vCenter");
}
void GCNavVolumeSphere::SetCenter(Vector value) {
    SetSchemaValue(m_ptr, "CNavVolumeSphere", "m_vCenter", false, value);
}
float GCNavVolumeSphere::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "CNavVolumeSphere", "m_flRadius");
}
void GCNavVolumeSphere::SetRadius(float value) {
    SetSchemaValue(m_ptr, "CNavVolumeSphere", "m_flRadius", false, value);
}
std::string GCNavVolumeSphere::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNavVolumeSphere::IsValid() {
    return (m_ptr != nullptr);
}
GCNavVolume GCNavVolumeSphere::GetParent() const {
    GCNavVolume value(m_ptr);
    return value;
}
void GCNavVolumeSphere::SetParent(GCNavVolume value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNavVolumeSphere(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNavVolumeSphere>("CNavVolumeSphere")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Center", &GCNavVolumeSphere::GetCenter, &GCNavVolumeSphere::SetCenter)
        .addProperty("Radius", &GCNavVolumeSphere::GetRadius, &GCNavVolumeSphere::SetRadius)
        .addProperty("Parent", &GCNavVolumeSphere::GetParent, &GCNavVolumeSphere::SetParent)
        .addFunction("ToPtr", &GCNavVolumeSphere::ToPtr)
        .addFunction("IsValid", &GCNavVolumeSphere::IsValid)
        .endClass();
}