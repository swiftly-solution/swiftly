#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFeIndexedJiggleBone::GCFeIndexedJiggleBone(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFeIndexedJiggleBone::GCFeIndexedJiggleBone(void *ptr) {
    m_ptr = ptr;
}
uint32_t GCFeIndexedJiggleBone::GetNode() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CFeIndexedJiggleBone", "m_nNode");
}
void GCFeIndexedJiggleBone::SetNode(uint32_t value) {
    SetSchemaValue(m_ptr, "CFeIndexedJiggleBone", "m_nNode", false, value);
}
uint32_t GCFeIndexedJiggleBone::GetJiggleParent() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CFeIndexedJiggleBone", "m_nJiggleParent");
}
void GCFeIndexedJiggleBone::SetJiggleParent(uint32_t value) {
    SetSchemaValue(m_ptr, "CFeIndexedJiggleBone", "m_nJiggleParent", false, value);
}
GCFeJiggleBone GCFeIndexedJiggleBone::GetJiggleBone() const {
    GCFeJiggleBone value(GetSchemaPtr(m_ptr, "CFeIndexedJiggleBone", "m_jiggleBone"));
    return value;
}
void GCFeIndexedJiggleBone::SetJiggleBone(GCFeJiggleBone value) {
    SetSchemaValue(m_ptr, "CFeIndexedJiggleBone", "m_jiggleBone", false, value);
}
std::string GCFeIndexedJiggleBone::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFeIndexedJiggleBone::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCFeIndexedJiggleBone(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFeIndexedJiggleBone>("CFeIndexedJiggleBone")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Node", &GCFeIndexedJiggleBone::GetNode, &GCFeIndexedJiggleBone::SetNode)
        .addProperty("JiggleParent", &GCFeIndexedJiggleBone::GetJiggleParent, &GCFeIndexedJiggleBone::SetJiggleParent)
        .addProperty("JiggleBone", &GCFeIndexedJiggleBone::GetJiggleBone, &GCFeIndexedJiggleBone::SetJiggleBone)
        .addFunction("ToPtr", &GCFeIndexedJiggleBone::ToPtr)
        .addFunction("IsValid", &GCFeIndexedJiggleBone::IsValid)
        .endClass();
}