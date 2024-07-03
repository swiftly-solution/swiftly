#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuncPlat::GCFuncPlat(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuncPlat::GCFuncPlat(void *ptr) {
    m_ptr = ptr;
}
std::string GCFuncPlat::GetNoise() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncPlat", "m_sNoise").String();
}
void GCFuncPlat::SetNoise(std::string value) {
    SetSchemaValue(m_ptr, "CFuncPlat", "m_sNoise", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCFuncPlat::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuncPlat::IsValid() {
    return (m_ptr != nullptr);
}
GCBasePlatTrain GCFuncPlat::GetParent() const {
    GCBasePlatTrain value(m_ptr);
    return value;
}
void GCFuncPlat::SetParent(GCBasePlatTrain value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFuncPlat(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncPlat>("CFuncPlat")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Noise", &GCFuncPlat::GetNoise, &GCFuncPlat::SetNoise)
        .addProperty("Parent", &GCFuncPlat::GetParent, &GCFuncPlat::SetParent)
        .addFunction("ToPtr", &GCFuncPlat::ToPtr)
        .addFunction("IsValid", &GCFuncPlat::IsValid)
        .endClass();
}