#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimUpdateNodeRef::GCAnimUpdateNodeRef(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimUpdateNodeRef::GCAnimUpdateNodeRef(void *ptr) {
    m_ptr = ptr;
}
int32_t GCAnimUpdateNodeRef::GetNodeIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimUpdateNodeRef", "m_nodeIndex");
}
void GCAnimUpdateNodeRef::SetNodeIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimUpdateNodeRef", "m_nodeIndex", false, value);
}
std::string GCAnimUpdateNodeRef::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimUpdateNodeRef::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimUpdateNodeRef(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimUpdateNodeRef>("CAnimUpdateNodeRef")
        .addConstructor<void (*)(std::string)>()
        .addProperty("NodeIndex", &GCAnimUpdateNodeRef::GetNodeIndex, &GCAnimUpdateNodeRef::SetNodeIndex)
        .addFunction("ToPtr", &GCAnimUpdateNodeRef::ToPtr)
        .addFunction("IsValid", &GCAnimUpdateNodeRef::IsValid)
        .endClass();
}