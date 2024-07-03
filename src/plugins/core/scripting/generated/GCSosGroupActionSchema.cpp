#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSosGroupActionSchema::GCSosGroupActionSchema(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSosGroupActionSchema::GCSosGroupActionSchema(void *ptr) {
    m_ptr = ptr;
}
std::string GCSosGroupActionSchema::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CSosGroupActionSchema", "m_name").Get();
}
void GCSosGroupActionSchema::SetName(std::string value) {
    SetSchemaValue(m_ptr, "CSosGroupActionSchema", "m_name", false, CUtlString(value.c_str()));
}
uint64_t GCSosGroupActionSchema::GetActionType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CSosGroupActionSchema", "m_actionType");
}
void GCSosGroupActionSchema::SetActionType(uint64_t value) {
    SetSchemaValue(m_ptr, "CSosGroupActionSchema", "m_actionType", false, value);
}
uint64_t GCSosGroupActionSchema::GetActionInstanceType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CSosGroupActionSchema", "m_actionInstanceType");
}
void GCSosGroupActionSchema::SetActionInstanceType(uint64_t value) {
    SetSchemaValue(m_ptr, "CSosGroupActionSchema", "m_actionInstanceType", false, value);
}
std::string GCSosGroupActionSchema::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSosGroupActionSchema::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSosGroupActionSchema(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSosGroupActionSchema>("CSosGroupActionSchema")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCSosGroupActionSchema::GetName, &GCSosGroupActionSchema::SetName)
        .addProperty("ActionType", &GCSosGroupActionSchema::GetActionType, &GCSosGroupActionSchema::SetActionType)
        .addProperty("ActionInstanceType", &GCSosGroupActionSchema::GetActionInstanceType, &GCSosGroupActionSchema::SetActionInstanceType)
        .addFunction("ToPtr", &GCSosGroupActionSchema::ToPtr)
        .addFunction("IsValid", &GCSosGroupActionSchema::IsValid)
        .endClass();
}