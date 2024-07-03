#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFiringModeFloat::GCFiringModeFloat(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFiringModeFloat::GCFiringModeFloat(void *ptr) {
    m_ptr = ptr;
}
std::vector<float> GCFiringModeFloat::GetValues() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CFiringModeFloat", "m_flValues"); std::vector<float> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCFiringModeFloat::SetValues(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CFiringModeFloat", "m_flValues"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CFiringModeFloat", "m_flValues", false, outValue);
}
std::string GCFiringModeFloat::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFiringModeFloat::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCFiringModeFloat(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFiringModeFloat>("CFiringModeFloat")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Values", &GCFiringModeFloat::GetValues, &GCFiringModeFloat::SetValues)
        .addFunction("ToPtr", &GCFiringModeFloat::ToPtr)
        .addFunction("IsValid", &GCFiringModeFloat::IsValid)
        .endClass();
}