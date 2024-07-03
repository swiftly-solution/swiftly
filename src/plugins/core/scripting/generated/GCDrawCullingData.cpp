#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCDrawCullingData::GCDrawCullingData(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCDrawCullingData::GCDrawCullingData(void *ptr) {
    m_ptr = ptr;
}
Vector GCDrawCullingData::GetConeApex() const {
    return GetSchemaValue<Vector>(m_ptr, "CDrawCullingData", "m_vConeApex");
}
void GCDrawCullingData::SetConeApex(Vector value) {
    SetSchemaValue(m_ptr, "CDrawCullingData", "m_vConeApex", false, value);
}
std::vector<int8_t> GCDrawCullingData::GetConeAxis() const {
    int8_t* outValue = GetSchemaValue<int8_t*>(m_ptr, "CDrawCullingData", "m_ConeAxis"); std::vector<int8_t> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCDrawCullingData::SetConeAxis(std::vector<int8_t> value) {
    int8_t* outValue = GetSchemaValue<int8_t*>(m_ptr, "CDrawCullingData", "m_ConeAxis"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CDrawCullingData", "m_ConeAxis", false, outValue);
}
int8_t GCDrawCullingData::GetConeCutoff() const {
    return GetSchemaValue<int8_t>(m_ptr, "CDrawCullingData", "m_ConeCutoff");
}
void GCDrawCullingData::SetConeCutoff(int8_t value) {
    SetSchemaValue(m_ptr, "CDrawCullingData", "m_ConeCutoff", false, value);
}
std::string GCDrawCullingData::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCDrawCullingData::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCDrawCullingData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDrawCullingData>("CDrawCullingData")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ConeApex", &GCDrawCullingData::GetConeApex, &GCDrawCullingData::SetConeApex)
        .addProperty("ConeAxis", &GCDrawCullingData::GetConeAxis, &GCDrawCullingData::SetConeAxis)
        .addProperty("ConeCutoff", &GCDrawCullingData::GetConeCutoff, &GCDrawCullingData::SetConeCutoff)
        .addFunction("ToPtr", &GCDrawCullingData::ToPtr)
        .addFunction("IsValid", &GCDrawCullingData::IsValid)
        .endClass();
}