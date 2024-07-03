#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBaseProp::GCBaseProp(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBaseProp::GCBaseProp(void *ptr) {
    m_ptr = ptr;
}
bool GCBaseProp::GetModelOverrodeBlockLOS() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseProp", "m_bModelOverrodeBlockLOS");
}
void GCBaseProp::SetModelOverrodeBlockLOS(bool value) {
    SetSchemaValue(m_ptr, "CBaseProp", "m_bModelOverrodeBlockLOS", false, value);
}
int32_t GCBaseProp::GetShapeType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBaseProp", "m_iShapeType");
}
void GCBaseProp::SetShapeType(int32_t value) {
    SetSchemaValue(m_ptr, "CBaseProp", "m_iShapeType", false, value);
}
bool GCBaseProp::GetConformToCollisionBounds() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseProp", "m_bConformToCollisionBounds");
}
void GCBaseProp::SetConformToCollisionBounds(bool value) {
    SetSchemaValue(m_ptr, "CBaseProp", "m_bConformToCollisionBounds", false, value);
}
matrix3x4_t GCBaseProp::GetMPreferredCatchTransform() const {
    return GetSchemaValue<matrix3x4_t>(m_ptr, "CBaseProp", "m_mPreferredCatchTransform");
}
void GCBaseProp::SetMPreferredCatchTransform(matrix3x4_t value) {
    SetSchemaValue(m_ptr, "CBaseProp", "m_mPreferredCatchTransform", false, value);
}
std::string GCBaseProp::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBaseProp::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseAnimGraph GCBaseProp::GetParent() const {
    GCBaseAnimGraph value(m_ptr);
    return value;
}
void GCBaseProp::SetParent(GCBaseAnimGraph value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBaseProp(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseProp>("CBaseProp")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ModelOverrodeBlockLOS", &GCBaseProp::GetModelOverrodeBlockLOS, &GCBaseProp::SetModelOverrodeBlockLOS)
        .addProperty("ShapeType", &GCBaseProp::GetShapeType, &GCBaseProp::SetShapeType)
        .addProperty("ConformToCollisionBounds", &GCBaseProp::GetConformToCollisionBounds, &GCBaseProp::SetConformToCollisionBounds)
        .addProperty("MPreferredCatchTransform", &GCBaseProp::GetMPreferredCatchTransform, &GCBaseProp::SetMPreferredCatchTransform)
        .addProperty("Parent", &GCBaseProp::GetParent, &GCBaseProp::SetParent)
        .addFunction("ToPtr", &GCBaseProp::ToPtr)
        .addFunction("IsValid", &GCBaseProp::IsValid)
        .endClass();
}