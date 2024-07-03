#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSoundEventEntityAlias_snd_event_point::GCSoundEventEntityAlias_snd_event_point(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSoundEventEntityAlias_snd_event_point::GCSoundEventEntityAlias_snd_event_point(void *ptr) {
    m_ptr = ptr;
}
std::string GCSoundEventEntityAlias_snd_event_point::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSoundEventEntityAlias_snd_event_point::IsValid() {
    return (m_ptr != nullptr);
}
GCSoundEventEntity GCSoundEventEntityAlias_snd_event_point::GetParent() const {
    GCSoundEventEntity value(m_ptr);
    return value;
}
void GCSoundEventEntityAlias_snd_event_point::SetParent(GCSoundEventEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSoundEventEntityAlias_snd_event_point(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundEventEntityAlias_snd_event_point>("CSoundEventEntityAlias_snd_event_point")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCSoundEventEntityAlias_snd_event_point::GetParent, &GCSoundEventEntityAlias_snd_event_point::SetParent)
        .addFunction("ToPtr", &GCSoundEventEntityAlias_snd_event_point::ToPtr)
        .addFunction("IsValid", &GCSoundEventEntityAlias_snd_event_point::IsValid)
        .endClass();
}