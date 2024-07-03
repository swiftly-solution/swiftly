#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSosGroupActionTimeLimitSchema::GCSosGroupActionTimeLimitSchema(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSosGroupActionTimeLimitSchema::GCSosGroupActionTimeLimitSchema(void *ptr) {
    m_ptr = ptr;
}
float GCSosGroupActionTimeLimitSchema::GetMaxDuration() const {
    return GetSchemaValue<float>(m_ptr, "CSosGroupActionTimeLimitSchema", "m_flMaxDuration");
}
void GCSosGroupActionTimeLimitSchema::SetMaxDuration(float value) {
    SetSchemaValue(m_ptr, "CSosGroupActionTimeLimitSchema", "m_flMaxDuration", false, value);
}
std::string GCSosGroupActionTimeLimitSchema::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSosGroupActionTimeLimitSchema::IsValid() {
    return (m_ptr != nullptr);
}
GCSosGroupActionSchema GCSosGroupActionTimeLimitSchema::GetParent() const {
    GCSosGroupActionSchema value(m_ptr);
    return value;
}
void GCSosGroupActionTimeLimitSchema::SetParent(GCSosGroupActionSchema value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSosGroupActionTimeLimitSchema(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSosGroupActionTimeLimitSchema>("CSosGroupActionTimeLimitSchema")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MaxDuration", &GCSosGroupActionTimeLimitSchema::GetMaxDuration, &GCSosGroupActionTimeLimitSchema::SetMaxDuration)
        .addProperty("Parent", &GCSosGroupActionTimeLimitSchema::GetParent, &GCSosGroupActionTimeLimitSchema::SetParent)
        .addFunction("ToPtr", &GCSosGroupActionTimeLimitSchema::ToPtr)
        .addFunction("IsValid", &GCSosGroupActionTimeLimitSchema::IsValid)
        .endClass();
}