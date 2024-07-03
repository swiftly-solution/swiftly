#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnableMotionFixup::GCEnableMotionFixup(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnableMotionFixup::GCEnableMotionFixup(void *ptr) {
    m_ptr = ptr;
}
std::string GCEnableMotionFixup::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnableMotionFixup::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCEnableMotionFixup::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCEnableMotionFixup::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnableMotionFixup(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnableMotionFixup>("CEnableMotionFixup")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCEnableMotionFixup::GetParent, &GCEnableMotionFixup::SetParent)
        .addFunction("ToPtr", &GCEnableMotionFixup::ToPtr)
        .addFunction("IsValid", &GCEnableMotionFixup::IsValid)
        .endClass();
}