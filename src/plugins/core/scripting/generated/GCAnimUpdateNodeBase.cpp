#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimUpdateNodeBase::GCAnimUpdateNodeBase(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimUpdateNodeBase::GCAnimUpdateNodeBase(void *ptr) {
    m_ptr = ptr;
}
GCAnimNodePath GCAnimUpdateNodeBase::GetNodePath() const {
    GCAnimNodePath value(GetSchemaPtr(m_ptr, "CAnimUpdateNodeBase", "m_nodePath"));
    return value;
}
void GCAnimUpdateNodeBase::SetNodePath(GCAnimNodePath value) {
    SetSchemaValue(m_ptr, "CAnimUpdateNodeBase", "m_nodePath", false, value);
}
uint64_t GCAnimUpdateNodeBase::GetNetworkMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CAnimUpdateNodeBase", "m_networkMode");
}
void GCAnimUpdateNodeBase::SetNetworkMode(uint64_t value) {
    SetSchemaValue(m_ptr, "CAnimUpdateNodeBase", "m_networkMode", false, value);
}
std::string GCAnimUpdateNodeBase::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CAnimUpdateNodeBase", "m_name").Get();
}
void GCAnimUpdateNodeBase::SetName(std::string value) {
    SetSchemaValue(m_ptr, "CAnimUpdateNodeBase", "m_name", false, CUtlString(value.c_str()));
}
std::string GCAnimUpdateNodeBase::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimUpdateNodeBase::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimUpdateNodeBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimUpdateNodeBase>("CAnimUpdateNodeBase")
        .addConstructor<void (*)(std::string)>()
        .addProperty("NodePath", &GCAnimUpdateNodeBase::GetNodePath, &GCAnimUpdateNodeBase::SetNodePath)
        .addProperty("NetworkMode", &GCAnimUpdateNodeBase::GetNetworkMode, &GCAnimUpdateNodeBase::SetNetworkMode)
        .addProperty("Name", &GCAnimUpdateNodeBase::GetName, &GCAnimUpdateNodeBase::SetName)
        .addFunction("ToPtr", &GCAnimUpdateNodeBase::ToPtr)
        .addFunction("IsValid", &GCAnimUpdateNodeBase::IsValid)
        .endClass();
}