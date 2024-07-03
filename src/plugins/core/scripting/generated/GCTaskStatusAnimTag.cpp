#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTaskStatusAnimTag::GCTaskStatusAnimTag(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTaskStatusAnimTag::GCTaskStatusAnimTag(void *ptr) {
    m_ptr = ptr;
}
std::string GCTaskStatusAnimTag::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTaskStatusAnimTag::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimTagBase GCTaskStatusAnimTag::GetParent() const {
    GCAnimTagBase value(m_ptr);
    return value;
}
void GCTaskStatusAnimTag::SetParent(GCAnimTagBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTaskStatusAnimTag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTaskStatusAnimTag>("CTaskStatusAnimTag")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCTaskStatusAnimTag::GetParent, &GCTaskStatusAnimTag::SetParent)
        .addFunction("ToPtr", &GCTaskStatusAnimTag::ToPtr)
        .addFunction("IsValid", &GCTaskStatusAnimTag::IsValid)
        .endClass();
}