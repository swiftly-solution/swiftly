#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLogicLineToEntity::GCLogicLineToEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLogicLineToEntity::GCLogicLineToEntity(void *ptr) {
    m_ptr = ptr;
}
std::string GCLogicLineToEntity::GetSourceName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicLineToEntity", "m_SourceName").String();
}
void GCLogicLineToEntity::SetSourceName(std::string value) {
    SetSchemaValue(m_ptr, "CLogicLineToEntity", "m_SourceName", false, CUtlSymbolLarge(value.c_str()));
}
GCBaseEntity GCLogicLineToEntity::GetStartEntity() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CLogicLineToEntity", "m_StartEntity"));
    return value;
}
void GCLogicLineToEntity::SetStartEntity(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'StartEntity' is not possible.\n");
}
GCBaseEntity GCLogicLineToEntity::GetEndEntity() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CLogicLineToEntity", "m_EndEntity"));
    return value;
}
void GCLogicLineToEntity::SetEndEntity(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'EndEntity' is not possible.\n");
}
std::string GCLogicLineToEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLogicLineToEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCLogicLineToEntity::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCLogicLineToEntity::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLogicLineToEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicLineToEntity>("CLogicLineToEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SourceName", &GCLogicLineToEntity::GetSourceName, &GCLogicLineToEntity::SetSourceName)
        .addProperty("StartEntity", &GCLogicLineToEntity::GetStartEntity, &GCLogicLineToEntity::SetStartEntity)
        .addProperty("EndEntity", &GCLogicLineToEntity::GetEndEntity, &GCLogicLineToEntity::SetEndEntity)
        .addProperty("Parent", &GCLogicLineToEntity::GetParent, &GCLogicLineToEntity::SetParent)
        .addFunction("ToPtr", &GCLogicLineToEntity::ToPtr)
        .addFunction("IsValid", &GCLogicLineToEntity::IsValid)
        .endClass();
}