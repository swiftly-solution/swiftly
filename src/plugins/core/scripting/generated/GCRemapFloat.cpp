#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRemapFloat::GCRemapFloat(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRemapFloat::GCRemapFloat(void *ptr) {
    m_ptr = ptr;
}
std::vector<float> GCRemapFloat::GetValue() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CRemapFloat", "m_pValue"); std::vector<float> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCRemapFloat::SetValue(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CRemapFloat", "m_pValue"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CRemapFloat", "m_pValue", false, outValue);
}
std::string GCRemapFloat::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRemapFloat::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCRemapFloat(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRemapFloat>("CRemapFloat")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Value", &GCRemapFloat::GetValue, &GCRemapFloat::SetValue)
        .addFunction("ToPtr", &GCRemapFloat::ToPtr)
        .addFunction("IsValid", &GCRemapFloat::IsValid)
        .endClass();
}