#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPrecipitationBlocker::GCPrecipitationBlocker(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPrecipitationBlocker::GCPrecipitationBlocker(void *ptr) {
    m_ptr = ptr;
}
std::string GCPrecipitationBlocker::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPrecipitationBlocker::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCPrecipitationBlocker::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCPrecipitationBlocker::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPrecipitationBlocker(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPrecipitationBlocker>("CPrecipitationBlocker")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCPrecipitationBlocker::GetParent, &GCPrecipitationBlocker::SetParent)
        .addFunction("ToPtr", &GCPrecipitationBlocker::ToPtr)
        .addFunction("IsValid", &GCPrecipitationBlocker::IsValid)
        .endClass();
}