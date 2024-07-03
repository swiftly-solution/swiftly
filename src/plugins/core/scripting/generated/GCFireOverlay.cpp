#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFireOverlay::GCFireOverlay(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFireOverlay::GCFireOverlay(void *ptr) {
    m_ptr = ptr;
}
std::vector<Vector> GCFireOverlay::GetBaseColors() const {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CFireOverlay", "m_vBaseColors"); std::vector<Vector> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCFireOverlay::SetBaseColors(std::vector<Vector> value) {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CFireOverlay", "m_vBaseColors"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CFireOverlay", "m_vBaseColors", false, outValue);
}
float GCFireOverlay::GetScale() const {
    return GetSchemaValue<float>(m_ptr, "CFireOverlay", "m_flScale");
}
void GCFireOverlay::SetScale(float value) {
    SetSchemaValue(m_ptr, "CFireOverlay", "m_flScale", false, value);
}
int32_t GCFireOverlay::GetGUID() const {
    return GetSchemaValue<int32_t>(m_ptr, "CFireOverlay", "m_nGUID");
}
void GCFireOverlay::SetGUID(int32_t value) {
    SetSchemaValue(m_ptr, "CFireOverlay", "m_nGUID", false, value);
}
std::string GCFireOverlay::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFireOverlay::IsValid() {
    return (m_ptr != nullptr);
}
GCGlowOverlay GCFireOverlay::GetParent() const {
    GCGlowOverlay value(m_ptr);
    return value;
}
void GCFireOverlay::SetParent(GCGlowOverlay value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFireOverlay(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFireOverlay>("CFireOverlay")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BaseColors", &GCFireOverlay::GetBaseColors, &GCFireOverlay::SetBaseColors)
        .addProperty("Scale", &GCFireOverlay::GetScale, &GCFireOverlay::SetScale)
        .addProperty("GUID", &GCFireOverlay::GetGUID, &GCFireOverlay::SetGUID)
        .addProperty("Parent", &GCFireOverlay::GetParent, &GCFireOverlay::SetParent)
        .addFunction("ToPtr", &GCFireOverlay::ToPtr)
        .addFunction("IsValid", &GCFireOverlay::IsValid)
        .endClass();
}