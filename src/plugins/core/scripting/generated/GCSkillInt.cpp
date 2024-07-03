#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSkillInt::GCSkillInt(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSkillInt::GCSkillInt(void *ptr) {
    m_ptr = ptr;
}
std::vector<int32_t> GCSkillInt::GetValue() const {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CSkillInt", "m_pValue"); std::vector<int32_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCSkillInt::SetValue(std::vector<int32_t> value) {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CSkillInt", "m_pValue"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CSkillInt", "m_pValue", false, outValue);
}
std::string GCSkillInt::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSkillInt::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSkillInt(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSkillInt>("CSkillInt")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Value", &GCSkillInt::GetValue, &GCSkillInt::SetValue)
        .addFunction("ToPtr", &GCSkillInt::ToPtr)
        .addFunction("IsValid", &GCSkillInt::IsValid)
        .endClass();
}