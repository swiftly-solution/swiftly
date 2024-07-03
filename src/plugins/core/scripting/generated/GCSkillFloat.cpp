#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSkillFloat::GCSkillFloat(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSkillFloat::GCSkillFloat(void *ptr) {
    m_ptr = ptr;
}
std::vector<float> GCSkillFloat::GetValue() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CSkillFloat", "m_pValue"); std::vector<float> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCSkillFloat::SetValue(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CSkillFloat", "m_pValue"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CSkillFloat", "m_pValue", false, outValue);
}
std::string GCSkillFloat::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSkillFloat::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSkillFloat(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSkillFloat>("CSkillFloat")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Value", &GCSkillFloat::GetValue, &GCSkillFloat::SetValue)
        .addFunction("ToPtr", &GCSkillFloat::ToPtr)
        .addFunction("IsValid", &GCSkillFloat::IsValid)
        .endClass();
}