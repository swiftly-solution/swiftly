#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCInfoTargetServerOnly::GCInfoTargetServerOnly(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCInfoTargetServerOnly::GCInfoTargetServerOnly(void *ptr) {
    m_ptr = ptr;
}
std::string GCInfoTargetServerOnly::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCInfoTargetServerOnly::IsValid() {
    return (m_ptr != nullptr);
}
GCServerOnlyPointEntity GCInfoTargetServerOnly::GetParent() const {
    GCServerOnlyPointEntity value(m_ptr);
    return value;
}
void GCInfoTargetServerOnly::SetParent(GCServerOnlyPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCInfoTargetServerOnly(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoTargetServerOnly>("CInfoTargetServerOnly")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCInfoTargetServerOnly::GetParent, &GCInfoTargetServerOnly::SetParent)
        .addFunction("ToPtr", &GCInfoTargetServerOnly::ToPtr)
        .addFunction("IsValid", &GCInfoTargetServerOnly::IsValid)
        .endClass();
}