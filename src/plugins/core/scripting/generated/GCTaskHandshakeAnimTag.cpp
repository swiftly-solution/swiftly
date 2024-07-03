#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTaskHandshakeAnimTag::GCTaskHandshakeAnimTag(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTaskHandshakeAnimTag::GCTaskHandshakeAnimTag(void *ptr) {
    m_ptr = ptr;
}
std::string GCTaskHandshakeAnimTag::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTaskHandshakeAnimTag::IsValid() {
    return (m_ptr != nullptr);
}
GCHandshakeAnimTagBase GCTaskHandshakeAnimTag::GetParent() const {
    GCHandshakeAnimTagBase value(m_ptr);
    return value;
}
void GCTaskHandshakeAnimTag::SetParent(GCHandshakeAnimTagBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTaskHandshakeAnimTag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTaskHandshakeAnimTag>("CTaskHandshakeAnimTag")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCTaskHandshakeAnimTag::GetParent, &GCTaskHandshakeAnimTag::SetParent)
        .addFunction("ToPtr", &GCTaskHandshakeAnimTag::ToPtr)
        .addFunction("IsValid", &GCTaskHandshakeAnimTag::IsValid)
        .endClass();
}