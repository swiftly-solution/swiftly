#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GParticleControlPointConfiguration_t::GParticleControlPointConfiguration_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GParticleControlPointConfiguration_t::GParticleControlPointConfiguration_t(void *ptr) {
    m_ptr = ptr;
}
std::string GParticleControlPointConfiguration_t::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "ParticleControlPointConfiguration_t", "m_name").Get();
}
void GParticleControlPointConfiguration_t::SetName(std::string value) {
    SetSchemaValue(m_ptr, "ParticleControlPointConfiguration_t", "m_name", true, CUtlString(value.c_str()));
}
std::vector<GParticleControlPointDriver_t> GParticleControlPointConfiguration_t::GetDrivers() const {
    CUtlVector<GParticleControlPointDriver_t>* vec = GetSchemaValue<CUtlVector<GParticleControlPointDriver_t>*>(m_ptr, "ParticleControlPointConfiguration_t", "m_drivers"); std::vector<GParticleControlPointDriver_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GParticleControlPointConfiguration_t::SetDrivers(std::vector<GParticleControlPointDriver_t> value) {
    SetSchemaValueCUtlVector<GParticleControlPointDriver_t>(m_ptr, "ParticleControlPointConfiguration_t", "m_drivers", true, value);
}
GParticlePreviewState_t GParticleControlPointConfiguration_t::GetPreviewState() const {
    GParticlePreviewState_t value(GetSchemaPtr(m_ptr, "ParticleControlPointConfiguration_t", "m_previewState"));
    return value;
}
void GParticleControlPointConfiguration_t::SetPreviewState(GParticlePreviewState_t value) {
    SetSchemaValue(m_ptr, "ParticleControlPointConfiguration_t", "m_previewState", true, value);
}
std::string GParticleControlPointConfiguration_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GParticleControlPointConfiguration_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassParticleControlPointConfiguration_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GParticleControlPointConfiguration_t>("ParticleControlPointConfiguration_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GParticleControlPointConfiguration_t::GetName, &GParticleControlPointConfiguration_t::SetName)
        .addProperty("Drivers", &GParticleControlPointConfiguration_t::GetDrivers, &GParticleControlPointConfiguration_t::SetDrivers)
        .addProperty("PreviewState", &GParticleControlPointConfiguration_t::GetPreviewState, &GParticleControlPointConfiguration_t::SetPreviewState)
        .addFunction("ToPtr", &GParticleControlPointConfiguration_t::ToPtr)
        .addFunction("IsValid", &GParticleControlPointConfiguration_t::IsValid)
        .endClass();
}