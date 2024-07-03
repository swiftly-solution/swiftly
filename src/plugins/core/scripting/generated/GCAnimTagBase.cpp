#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimTagBase::GCAnimTagBase(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimTagBase::GCAnimTagBase(void *ptr) {
    m_ptr = ptr;
}
std::string GCAnimTagBase::GetComment() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CAnimTagBase", "m_sComment").Get();
}
void GCAnimTagBase::SetComment(std::string value) {
    SetSchemaValue(m_ptr, "CAnimTagBase", "m_sComment", false, CUtlString(value.c_str()));
}
GAnimTagID GCAnimTagBase::GetTagID() const {
    GAnimTagID value(GetSchemaPtr(m_ptr, "CAnimTagBase", "m_tagID"));
    return value;
}
void GCAnimTagBase::SetTagID(GAnimTagID value) {
    SetSchemaValue(m_ptr, "CAnimTagBase", "m_tagID", false, value);
}
bool GCAnimTagBase::GetIsReferenced() const {
    return GetSchemaValue<bool>(m_ptr, "CAnimTagBase", "m_bIsReferenced");
}
void GCAnimTagBase::SetIsReferenced(bool value) {
    SetSchemaValue(m_ptr, "CAnimTagBase", "m_bIsReferenced", false, value);
}
std::string GCAnimTagBase::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimTagBase::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimTagBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimTagBase>("CAnimTagBase")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Comment", &GCAnimTagBase::GetComment, &GCAnimTagBase::SetComment)
        .addProperty("TagID", &GCAnimTagBase::GetTagID, &GCAnimTagBase::SetTagID)
        .addProperty("IsReferenced", &GCAnimTagBase::GetIsReferenced, &GCAnimTagBase::SetIsReferenced)
        .addFunction("ToPtr", &GCAnimTagBase::ToPtr)
        .addFunction("IsValid", &GCAnimTagBase::IsValid)
        .endClass();
}