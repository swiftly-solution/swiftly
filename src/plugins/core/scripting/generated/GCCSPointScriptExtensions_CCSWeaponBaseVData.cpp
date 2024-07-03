#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPointScriptExtensions_CCSWeaponBaseVData::GCCSPointScriptExtensions_CCSWeaponBaseVData(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPointScriptExtensions_CCSWeaponBaseVData::GCCSPointScriptExtensions_CCSWeaponBaseVData(void *ptr) {
    m_ptr = ptr;
}
std::string GCCSPointScriptExtensions_CCSWeaponBaseVData::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPointScriptExtensions_CCSWeaponBaseVData::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCCSPointScriptExtensions_CCSWeaponBaseVData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPointScriptExtensions_CCSWeaponBaseVData>("CCSPointScriptExtensions_CCSWeaponBaseVData")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCCSPointScriptExtensions_CCSWeaponBaseVData::ToPtr)
        .addFunction("IsValid", &GCCSPointScriptExtensions_CCSWeaponBaseVData::IsValid)
        .endClass();
}