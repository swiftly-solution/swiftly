#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPlayerSprayDecalRenderHelper::GCPlayerSprayDecalRenderHelper(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPlayerSprayDecalRenderHelper::GCPlayerSprayDecalRenderHelper(void *ptr) {
    m_ptr = ptr;
}
std::string GCPlayerSprayDecalRenderHelper::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPlayerSprayDecalRenderHelper::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCPlayerSprayDecalRenderHelper(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayerSprayDecalRenderHelper>("CPlayerSprayDecalRenderHelper")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCPlayerSprayDecalRenderHelper::ToPtr)
        .addFunction("IsValid", &GCPlayerSprayDecalRenderHelper::IsValid)
        .endClass();
}