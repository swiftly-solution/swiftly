#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSequenceFinishedAnimTag::GCSequenceFinishedAnimTag(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSequenceFinishedAnimTag::GCSequenceFinishedAnimTag(void *ptr) {
    m_ptr = ptr;
}
std::string GCSequenceFinishedAnimTag::GetSequenceName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CSequenceFinishedAnimTag", "m_sequenceName").Get();
}
void GCSequenceFinishedAnimTag::SetSequenceName(std::string value) {
    SetSchemaValue(m_ptr, "CSequenceFinishedAnimTag", "m_sequenceName", false, CUtlString(value.c_str()));
}
std::string GCSequenceFinishedAnimTag::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSequenceFinishedAnimTag::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimTagBase GCSequenceFinishedAnimTag::GetParent() const {
    GCAnimTagBase value(m_ptr);
    return value;
}
void GCSequenceFinishedAnimTag::SetParent(GCAnimTagBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSequenceFinishedAnimTag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSequenceFinishedAnimTag>("CSequenceFinishedAnimTag")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SequenceName", &GCSequenceFinishedAnimTag::GetSequenceName, &GCSequenceFinishedAnimTag::SetSequenceName)
        .addProperty("Parent", &GCSequenceFinishedAnimTag::GetParent, &GCSequenceFinishedAnimTag::SetParent)
        .addFunction("ToPtr", &GCSequenceFinishedAnimTag::ToPtr)
        .addFunction("IsValid", &GCSequenceFinishedAnimTag::IsValid)
        .endClass();
}