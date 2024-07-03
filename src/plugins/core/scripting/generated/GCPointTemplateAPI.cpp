#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPointTemplateAPI::GCPointTemplateAPI(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPointTemplateAPI::GCPointTemplateAPI(void *ptr) {
    m_ptr = ptr;
}
std::string GCPointTemplateAPI::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPointTemplateAPI::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCPointTemplateAPI(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointTemplateAPI>("CPointTemplateAPI")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCPointTemplateAPI::ToPtr)
        .addFunction("IsValid", &GCPointTemplateAPI::IsValid)
        .endClass();
}