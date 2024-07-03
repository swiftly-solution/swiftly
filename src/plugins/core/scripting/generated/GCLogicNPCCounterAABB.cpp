#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLogicNPCCounterAABB::GCLogicNPCCounterAABB(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLogicNPCCounterAABB::GCLogicNPCCounterAABB(void *ptr) {
    m_ptr = ptr;
}
Vector GCLogicNPCCounterAABB::GetDistanceOuterMins() const {
    return GetSchemaValue<Vector>(m_ptr, "CLogicNPCCounterAABB", "m_vDistanceOuterMins");
}
void GCLogicNPCCounterAABB::SetDistanceOuterMins(Vector value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounterAABB", "m_vDistanceOuterMins", false, value);
}
Vector GCLogicNPCCounterAABB::GetDistanceOuterMaxs() const {
    return GetSchemaValue<Vector>(m_ptr, "CLogicNPCCounterAABB", "m_vDistanceOuterMaxs");
}
void GCLogicNPCCounterAABB::SetDistanceOuterMaxs(Vector value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounterAABB", "m_vDistanceOuterMaxs", false, value);
}
Vector GCLogicNPCCounterAABB::GetOuterMins() const {
    return GetSchemaValue<Vector>(m_ptr, "CLogicNPCCounterAABB", "m_vOuterMins");
}
void GCLogicNPCCounterAABB::SetOuterMins(Vector value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounterAABB", "m_vOuterMins", false, value);
}
Vector GCLogicNPCCounterAABB::GetOuterMaxs() const {
    return GetSchemaValue<Vector>(m_ptr, "CLogicNPCCounterAABB", "m_vOuterMaxs");
}
void GCLogicNPCCounterAABB::SetOuterMaxs(Vector value) {
    SetSchemaValue(m_ptr, "CLogicNPCCounterAABB", "m_vOuterMaxs", false, value);
}
std::string GCLogicNPCCounterAABB::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLogicNPCCounterAABB::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicNPCCounter GCLogicNPCCounterAABB::GetParent() const {
    GCLogicNPCCounter value(m_ptr);
    return value;
}
void GCLogicNPCCounterAABB::SetParent(GCLogicNPCCounter value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLogicNPCCounterAABB(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicNPCCounterAABB>("CLogicNPCCounterAABB")
        .addConstructor<void (*)(std::string)>()
        .addProperty("DistanceOuterMins", &GCLogicNPCCounterAABB::GetDistanceOuterMins, &GCLogicNPCCounterAABB::SetDistanceOuterMins)
        .addProperty("DistanceOuterMaxs", &GCLogicNPCCounterAABB::GetDistanceOuterMaxs, &GCLogicNPCCounterAABB::SetDistanceOuterMaxs)
        .addProperty("OuterMins", &GCLogicNPCCounterAABB::GetOuterMins, &GCLogicNPCCounterAABB::SetOuterMins)
        .addProperty("OuterMaxs", &GCLogicNPCCounterAABB::GetOuterMaxs, &GCLogicNPCCounterAABB::SetOuterMaxs)
        .addProperty("Parent", &GCLogicNPCCounterAABB::GetParent, &GCLogicNPCCounterAABB::SetParent)
        .addFunction("ToPtr", &GCLogicNPCCounterAABB::ToPtr)
        .addFunction("IsValid", &GCLogicNPCCounterAABB::IsValid)
        .endClass();
}