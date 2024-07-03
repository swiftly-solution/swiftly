#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimNodePath::GCAnimNodePath(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimNodePath::GCAnimNodePath(void *ptr) {
    m_ptr = ptr;
}
std::vector<GAnimNodeID> GCAnimNodePath::GetPath() const {
    GAnimNodeID* outValue = GetSchemaValue<GAnimNodeID*>(m_ptr, "CAnimNodePath", "m_path"); std::vector<GAnimNodeID> ret; for(int i = 0; i < 11; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCAnimNodePath::SetPath(std::vector<GAnimNodeID> value) {
    GAnimNodeID* outValue = GetSchemaValue<GAnimNodeID*>(m_ptr, "CAnimNodePath", "m_path"); for(int i = 0; i < 11; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CAnimNodePath", "m_path", false, outValue);
}
int32_t GCAnimNodePath::GetCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimNodePath", "m_nCount");
}
void GCAnimNodePath::SetCount(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimNodePath", "m_nCount", false, value);
}
std::string GCAnimNodePath::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimNodePath::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimNodePath(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimNodePath>("CAnimNodePath")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Path", &GCAnimNodePath::GetPath, &GCAnimNodePath::SetPath)
        .addProperty("Count", &GCAnimNodePath::GetCount, &GCAnimNodePath::SetCount)
        .addFunction("ToPtr", &GCAnimNodePath::ToPtr)
        .addFunction("IsValid", &GCAnimNodePath::IsValid)
        .endClass();
}