#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTestEffect::GCTestEffect(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTestEffect::GCTestEffect(void *ptr) {
    m_ptr = ptr;
}
int32_t GCTestEffect::GetLoop() const {
    return GetSchemaValue<int32_t>(m_ptr, "CTestEffect", "m_iLoop");
}
void GCTestEffect::SetLoop(int32_t value) {
    SetSchemaValue(m_ptr, "CTestEffect", "m_iLoop", false, value);
}
int32_t GCTestEffect::GetBeam() const {
    return GetSchemaValue<int32_t>(m_ptr, "CTestEffect", "m_iBeam");
}
void GCTestEffect::SetBeam(int32_t value) {
    SetSchemaValue(m_ptr, "CTestEffect", "m_iBeam", false, value);
}
std::vector<GCBeam*> GCTestEffect::GetBeam1() const {
    GCBeam** outValue = GetSchemaValue<GCBeam**>(m_ptr, "CTestEffect", "m_pBeam"); std::vector<GCBeam*> ret; for(int i = 0; i < 24; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCTestEffect::SetBeam1(std::vector<GCBeam*> value) {
    GCBeam** outValue = GetSchemaValue<GCBeam**>(m_ptr, "CTestEffect", "m_pBeam"); for(int i = 0; i < 24; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CTestEffect", "m_pBeam", false, outValue);
}
std::vector<float> GCTestEffect::GetBeamTime() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CTestEffect", "m_flBeamTime"); std::vector<float> ret; for(int i = 0; i < 24; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCTestEffect::SetBeamTime(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CTestEffect", "m_flBeamTime"); for(int i = 0; i < 24; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CTestEffect", "m_flBeamTime", false, outValue);
}
float GCTestEffect::GetStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CTestEffect", "m_flStartTime");
}
void GCTestEffect::SetStartTime(float value) {
    SetSchemaValue(m_ptr, "CTestEffect", "m_flStartTime", false, value);
}
std::string GCTestEffect::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTestEffect::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCTestEffect::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCTestEffect::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTestEffect(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTestEffect>("CTestEffect")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Loop", &GCTestEffect::GetLoop, &GCTestEffect::SetLoop)
        .addProperty("Beam", &GCTestEffect::GetBeam, &GCTestEffect::SetBeam)
        .addProperty("Beam1", &GCTestEffect::GetBeam1, &GCTestEffect::SetBeam1)
        .addProperty("BeamTime", &GCTestEffect::GetBeamTime, &GCTestEffect::SetBeamTime)
        .addProperty("StartTime", &GCTestEffect::GetStartTime, &GCTestEffect::SetStartTime)
        .addProperty("Parent", &GCTestEffect::GetParent, &GCTestEffect::SetParent)
        .addFunction("ToPtr", &GCTestEffect::ToPtr)
        .addFunction("IsValid", &GCTestEffect::IsValid)
        .endClass();
}