#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimUserDifference::GCAnimUserDifference(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimUserDifference::GCAnimUserDifference(void *ptr) {
    m_ptr = ptr;
}
CBufferString GCAnimUserDifference::GetName() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CAnimUserDifference", "m_name");
}
void GCAnimUserDifference::SetName(CBufferString value) {
    SetSchemaValue(m_ptr, "CAnimUserDifference", "m_name", false, value);
}
int32_t GCAnimUserDifference::GetType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimUserDifference", "m_nType");
}
void GCAnimUserDifference::SetType(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimUserDifference", "m_nType", false, value);
}
std::string GCAnimUserDifference::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimUserDifference::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimUserDifference(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimUserDifference>("CAnimUserDifference")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCAnimUserDifference::GetName, &GCAnimUserDifference::SetName)
        .addProperty("Type", &GCAnimUserDifference::GetType, &GCAnimUserDifference::SetType)
        .addFunction("ToPtr", &GCAnimUserDifference::ToPtr)
        .addFunction("IsValid", &GCAnimUserDifference::IsValid)
        .endClass();
}