#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSkyCamera::GCSkyCamera(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSkyCamera::GCSkyCamera(void *ptr) {
    m_ptr = ptr;
}
Gsky3dparams_t GCSkyCamera::GetSkyboxData() const {
    Gsky3dparams_t value(GetSchemaPtr(m_ptr, "CSkyCamera", "m_skyboxData"));
    return value;
}
void GCSkyCamera::SetSkyboxData(Gsky3dparams_t value) {
    SetSchemaValue(m_ptr, "CSkyCamera", "m_skyboxData", false, value);
}
CUtlStringToken GCSkyCamera::GetSkyboxSlotToken() const {
    return GetSchemaValue<CUtlStringToken>(m_ptr, "CSkyCamera", "m_skyboxSlotToken");
}
void GCSkyCamera::SetSkyboxSlotToken(CUtlStringToken value) {
    SetSchemaValue(m_ptr, "CSkyCamera", "m_skyboxSlotToken", false, value);
}
bool GCSkyCamera::GetUseAngles() const {
    return GetSchemaValue<bool>(m_ptr, "CSkyCamera", "m_bUseAngles");
}
void GCSkyCamera::SetUseAngles(bool value) {
    SetSchemaValue(m_ptr, "CSkyCamera", "m_bUseAngles", false, value);
}
GCSkyCamera GCSkyCamera::GetNext() const {
    GCSkyCamera value(*GetSchemaValuePtr<void*>(m_ptr, "CSkyCamera", "m_pNext"));
    return value;
}
void GCSkyCamera::SetNext(GCSkyCamera* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Next' is not possible.\n");
}
std::string GCSkyCamera::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSkyCamera::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCSkyCamera::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCSkyCamera::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSkyCamera(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSkyCamera>("CSkyCamera")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SkyboxData", &GCSkyCamera::GetSkyboxData, &GCSkyCamera::SetSkyboxData)
        .addProperty("SkyboxSlotToken", &GCSkyCamera::GetSkyboxSlotToken, &GCSkyCamera::SetSkyboxSlotToken)
        .addProperty("UseAngles", &GCSkyCamera::GetUseAngles, &GCSkyCamera::SetUseAngles)
        .addProperty("Next", &GCSkyCamera::GetNext, &GCSkyCamera::SetNext)
        .addProperty("Parent", &GCSkyCamera::GetParent, &GCSkyCamera::SetParent)
        .addFunction("ToPtr", &GCSkyCamera::ToPtr)
        .addFunction("IsValid", &GCSkyCamera::IsValid)
        .endClass();
}