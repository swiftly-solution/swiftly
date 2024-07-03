#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCStateNodeStateData::GCStateNodeStateData(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCStateNodeStateData::GCStateNodeStateData(void *ptr) {
    m_ptr = ptr;
}
GCAnimUpdateNodeRef GCStateNodeStateData::GetChild() const {
    GCAnimUpdateNodeRef value(GetSchemaPtr(m_ptr, "CStateNodeStateData", "m_pChild"));
    return value;
}
void GCStateNodeStateData::SetChild(GCAnimUpdateNodeRef value) {
    SetSchemaValue(m_ptr, "CStateNodeStateData", "m_pChild", false, value);
}
std::string GCStateNodeStateData::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCStateNodeStateData::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCStateNodeStateData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCStateNodeStateData>("CStateNodeStateData")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Child", &GCStateNodeStateData::GetChild, &GCStateNodeStateData::SetChild)
        .addFunction("ToPtr", &GCStateNodeStateData::ToPtr)
        .addFunction("IsValid", &GCStateNodeStateData::IsValid)
        .endClass();
}