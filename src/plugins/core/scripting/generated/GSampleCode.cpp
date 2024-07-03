#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GSampleCode::GSampleCode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GSampleCode::GSampleCode(void *ptr) {
    m_ptr = ptr;
}
std::vector<uint8_t> GSampleCode::GetSubCode() const {
    uint8_t* outValue = GetSchemaValue<uint8_t*>(m_ptr, "SampleCode", "m_subCode"); std::vector<uint8_t> ret; for(int i = 0; i < 8; i++) { ret.push_back(outValue[i]); } return ret;
}
void GSampleCode::SetSubCode(std::vector<uint8_t> value) {
    uint8_t* outValue = GetSchemaValue<uint8_t*>(m_ptr, "SampleCode", "m_subCode"); for(int i = 0; i < 8; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "SampleCode", "m_subCode", false, outValue);
}
std::string GSampleCode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GSampleCode::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassSampleCode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSampleCode>("SampleCode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SubCode", &GSampleCode::GetSubCode, &GSampleCode::SetSubCode)
        .addFunction("ToPtr", &GSampleCode::ToPtr)
        .addFunction("IsValid", &GSampleCode::IsValid)
        .endClass();
}