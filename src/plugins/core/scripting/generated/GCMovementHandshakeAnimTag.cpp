#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMovementHandshakeAnimTag::GCMovementHandshakeAnimTag(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMovementHandshakeAnimTag::GCMovementHandshakeAnimTag(void *ptr) {
    m_ptr = ptr;
}
std::string GCMovementHandshakeAnimTag::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMovementHandshakeAnimTag::IsValid() {
    return (m_ptr != nullptr);
}
GCHandshakeAnimTagBase GCMovementHandshakeAnimTag::GetParent() const {
    GCHandshakeAnimTagBase value(m_ptr);
    return value;
}
void GCMovementHandshakeAnimTag::SetParent(GCHandshakeAnimTagBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCMovementHandshakeAnimTag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMovementHandshakeAnimTag>("CMovementHandshakeAnimTag")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCMovementHandshakeAnimTag::GetParent, &GCMovementHandshakeAnimTag::SetParent)
        .addFunction("ToPtr", &GCMovementHandshakeAnimTag::ToPtr)
        .addFunction("IsValid", &GCMovementHandshakeAnimTag::IsValid)
        .endClass();
}