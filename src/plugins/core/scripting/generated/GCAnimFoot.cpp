#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimFoot::GCAnimFoot(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimFoot::GCAnimFoot(void *ptr) {
    m_ptr = ptr;
}
std::string GCAnimFoot::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CAnimFoot", "m_name").Get();
}
void GCAnimFoot::SetName(std::string value) {
    SetSchemaValue(m_ptr, "CAnimFoot", "m_name", false, CUtlString(value.c_str()));
}
Vector GCAnimFoot::GetBallOffset() const {
    return GetSchemaValue<Vector>(m_ptr, "CAnimFoot", "m_vBallOffset");
}
void GCAnimFoot::SetBallOffset(Vector value) {
    SetSchemaValue(m_ptr, "CAnimFoot", "m_vBallOffset", false, value);
}
Vector GCAnimFoot::GetHeelOffset() const {
    return GetSchemaValue<Vector>(m_ptr, "CAnimFoot", "m_vHeelOffset");
}
void GCAnimFoot::SetHeelOffset(Vector value) {
    SetSchemaValue(m_ptr, "CAnimFoot", "m_vHeelOffset", false, value);
}
int32_t GCAnimFoot::GetAnkleBoneIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimFoot", "m_ankleBoneIndex");
}
void GCAnimFoot::SetAnkleBoneIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimFoot", "m_ankleBoneIndex", false, value);
}
int32_t GCAnimFoot::GetToeBoneIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimFoot", "m_toeBoneIndex");
}
void GCAnimFoot::SetToeBoneIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimFoot", "m_toeBoneIndex", false, value);
}
std::string GCAnimFoot::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimFoot::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimFoot(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimFoot>("CAnimFoot")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCAnimFoot::GetName, &GCAnimFoot::SetName)
        .addProperty("BallOffset", &GCAnimFoot::GetBallOffset, &GCAnimFoot::SetBallOffset)
        .addProperty("HeelOffset", &GCAnimFoot::GetHeelOffset, &GCAnimFoot::SetHeelOffset)
        .addProperty("AnkleBoneIndex", &GCAnimFoot::GetAnkleBoneIndex, &GCAnimFoot::SetAnkleBoneIndex)
        .addProperty("ToeBoneIndex", &GCAnimFoot::GetToeBoneIndex, &GCAnimFoot::SetToeBoneIndex)
        .addFunction("ToPtr", &GCAnimFoot::ToPtr)
        .addFunction("IsValid", &GCAnimFoot::IsValid)
        .endClass();
}