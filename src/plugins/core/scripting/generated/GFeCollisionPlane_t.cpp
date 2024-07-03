#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeCollisionPlane_t::GFeCollisionPlane_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeCollisionPlane_t::GFeCollisionPlane_t(void *ptr) {
    m_ptr = ptr;
}
uint16_t GFeCollisionPlane_t::GetCtrlParent() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeCollisionPlane_t", "nCtrlParent");
}
void GFeCollisionPlane_t::SetCtrlParent(uint16_t value) {
    SetSchemaValue(m_ptr, "FeCollisionPlane_t", "nCtrlParent", true, value);
}
uint16_t GFeCollisionPlane_t::GetChildNode() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeCollisionPlane_t", "nChildNode");
}
void GFeCollisionPlane_t::SetChildNode(uint16_t value) {
    SetSchemaValue(m_ptr, "FeCollisionPlane_t", "nChildNode", true, value);
}
GRnPlane_t GFeCollisionPlane_t::GetPlane() const {
    GRnPlane_t value(GetSchemaPtr(m_ptr, "FeCollisionPlane_t", "m_Plane"));
    return value;
}
void GFeCollisionPlane_t::SetPlane(GRnPlane_t value) {
    SetSchemaValue(m_ptr, "FeCollisionPlane_t", "m_Plane", true, value);
}
float GFeCollisionPlane_t::GetStrength() const {
    return GetSchemaValue<float>(m_ptr, "FeCollisionPlane_t", "flStrength");
}
void GFeCollisionPlane_t::SetStrength(float value) {
    SetSchemaValue(m_ptr, "FeCollisionPlane_t", "flStrength", true, value);
}
std::string GFeCollisionPlane_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeCollisionPlane_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeCollisionPlane_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeCollisionPlane_t>("FeCollisionPlane_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CtrlParent", &GFeCollisionPlane_t::GetCtrlParent, &GFeCollisionPlane_t::SetCtrlParent)
        .addProperty("ChildNode", &GFeCollisionPlane_t::GetChildNode, &GFeCollisionPlane_t::SetChildNode)
        .addProperty("Plane", &GFeCollisionPlane_t::GetPlane, &GFeCollisionPlane_t::SetPlane)
        .addProperty("Strength", &GFeCollisionPlane_t::GetStrength, &GFeCollisionPlane_t::SetStrength)
        .addFunction("ToPtr", &GFeCollisionPlane_t::ToPtr)
        .addFunction("IsValid", &GFeCollisionPlane_t::IsValid)
        .endClass();
}