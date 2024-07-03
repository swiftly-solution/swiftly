#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSoundInfoHeader::GCSoundInfoHeader(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSoundInfoHeader::GCSoundInfoHeader(void *ptr) {
    m_ptr = ptr;
}
std::string GCSoundInfoHeader::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSoundInfoHeader::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSoundInfoHeader(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundInfoHeader>("CSoundInfoHeader")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCSoundInfoHeader::ToPtr)
        .addFunction("IsValid", &GCSoundInfoHeader::IsValid)
        .endClass();
}