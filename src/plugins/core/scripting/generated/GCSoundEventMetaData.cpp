#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSoundEventMetaData::GCSoundEventMetaData(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSoundEventMetaData::GCSoundEventMetaData(void *ptr) {
    m_ptr = ptr;
}
std::string GCSoundEventMetaData::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSoundEventMetaData::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSoundEventMetaData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundEventMetaData>("CSoundEventMetaData")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCSoundEventMetaData::ToPtr)
        .addFunction("IsValid", &GCSoundEventMetaData::IsValid)
        .endClass();
}