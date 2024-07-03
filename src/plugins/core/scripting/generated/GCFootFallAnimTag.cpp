#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFootFallAnimTag::GCFootFallAnimTag(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFootFallAnimTag::GCFootFallAnimTag(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCFootFallAnimTag::GetFoot() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CFootFallAnimTag", "m_foot");
}
void GCFootFallAnimTag::SetFoot(uint64_t value) {
    SetSchemaValue(m_ptr, "CFootFallAnimTag", "m_foot", false, value);
}
std::string GCFootFallAnimTag::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFootFallAnimTag::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimTagBase GCFootFallAnimTag::GetParent() const {
    GCAnimTagBase value(m_ptr);
    return value;
}
void GCFootFallAnimTag::SetParent(GCAnimTagBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFootFallAnimTag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootFallAnimTag>("CFootFallAnimTag")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Foot", &GCFootFallAnimTag::GetFoot, &GCFootFallAnimTag::SetFoot)
        .addProperty("Parent", &GCFootFallAnimTag::GetParent, &GCFootFallAnimTag::SetParent)
        .addFunction("ToPtr", &GCFootFallAnimTag::ToPtr)
        .addFunction("IsValid", &GCFootFallAnimTag::IsValid)
        .endClass();
}