#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPrecipitation::GCPrecipitation(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPrecipitation::GCPrecipitation(void *ptr) {
    m_ptr = ptr;
}
std::string GCPrecipitation::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPrecipitation::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCPrecipitation::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCPrecipitation::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPrecipitation(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPrecipitation>("CPrecipitation")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCPrecipitation::GetParent, &GCPrecipitation::SetParent)
        .addFunction("ToPtr", &GCPrecipitation::ToPtr)
        .addFunction("IsValid", &GCPrecipitation::IsValid)
        .endClass();
}