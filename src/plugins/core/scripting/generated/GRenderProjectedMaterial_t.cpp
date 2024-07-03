#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GRenderProjectedMaterial_t::GRenderProjectedMaterial_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GRenderProjectedMaterial_t::GRenderProjectedMaterial_t(void *ptr) {
    m_ptr = ptr;
}
std::string GRenderProjectedMaterial_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GRenderProjectedMaterial_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassRenderProjectedMaterial_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRenderProjectedMaterial_t>("RenderProjectedMaterial_t")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GRenderProjectedMaterial_t::ToPtr)
        .addFunction("IsValid", &GRenderProjectedMaterial_t::IsValid)
        .endClass();
}