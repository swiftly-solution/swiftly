#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPointScriptExtensions_weapon_cs_base::GCCSPointScriptExtensions_weapon_cs_base(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPointScriptExtensions_weapon_cs_base::GCCSPointScriptExtensions_weapon_cs_base(void *ptr) {
    m_ptr = ptr;
}
std::string GCCSPointScriptExtensions_weapon_cs_base::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPointScriptExtensions_weapon_cs_base::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCCSPointScriptExtensions_weapon_cs_base(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPointScriptExtensions_weapon_cs_base>("CCSPointScriptExtensions_weapon_cs_base")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCCSPointScriptExtensions_weapon_cs_base::ToPtr)
        .addFunction("IsValid", &GCCSPointScriptExtensions_weapon_cs_base::IsValid)
        .endClass();
}