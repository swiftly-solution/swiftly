#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRangeFloat::GCRangeFloat(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRangeFloat::GCRangeFloat(void *ptr) {
    m_ptr = ptr;
}
std::vector<float> GCRangeFloat::GetValue() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CRangeFloat", "m_pValue"); std::vector<float> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCRangeFloat::SetValue(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CRangeFloat", "m_pValue"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CRangeFloat", "m_pValue", false, outValue);
}
std::string GCRangeFloat::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRangeFloat::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCRangeFloat(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRangeFloat>("CRangeFloat")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Value", &GCRangeFloat::GetValue, &GCRangeFloat::SetValue)
        .addFunction("ToPtr", &GCRangeFloat::ToPtr)
        .addFunction("IsValid", &GCRangeFloat::IsValid)
        .endClass();
}