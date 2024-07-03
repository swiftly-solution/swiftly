#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvMuzzleFlash::GCEnvMuzzleFlash(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvMuzzleFlash::GCEnvMuzzleFlash(void *ptr) {
    m_ptr = ptr;
}
float GCEnvMuzzleFlash::GetScale() const {
    return GetSchemaValue<float>(m_ptr, "CEnvMuzzleFlash", "m_flScale");
}
void GCEnvMuzzleFlash::SetScale(float value) {
    SetSchemaValue(m_ptr, "CEnvMuzzleFlash", "m_flScale", false, value);
}
std::string GCEnvMuzzleFlash::GetParentAttachment() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvMuzzleFlash", "m_iszParentAttachment").String();
}
void GCEnvMuzzleFlash::SetParentAttachment(std::string value) {
    SetSchemaValue(m_ptr, "CEnvMuzzleFlash", "m_iszParentAttachment", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCEnvMuzzleFlash::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvMuzzleFlash::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCEnvMuzzleFlash::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCEnvMuzzleFlash::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvMuzzleFlash(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvMuzzleFlash>("CEnvMuzzleFlash")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Scale", &GCEnvMuzzleFlash::GetScale, &GCEnvMuzzleFlash::SetScale)
        .addProperty("ParentAttachment", &GCEnvMuzzleFlash::GetParentAttachment, &GCEnvMuzzleFlash::SetParentAttachment)
        .addProperty("Parent", &GCEnvMuzzleFlash::GetParent, &GCEnvMuzzleFlash::SetParent)
        .addFunction("ToPtr", &GCEnvMuzzleFlash::ToPtr)
        .addFunction("IsValid", &GCEnvMuzzleFlash::IsValid)
        .endClass();
}