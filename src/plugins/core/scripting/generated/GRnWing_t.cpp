#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GRnWing_t::GRnWing_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GRnWing_t::GRnWing_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<int32_t> GRnWing_t::GetIndex() const {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "RnWing_t", "m_nIndex"); std::vector<int32_t> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret;
}
void GRnWing_t::SetIndex(std::vector<int32_t> value) {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "RnWing_t", "m_nIndex"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "RnWing_t", "m_nIndex", true, outValue);
}
std::string GRnWing_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GRnWing_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassRnWing_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnWing_t>("RnWing_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Index", &GRnWing_t::GetIndex, &GRnWing_t::SetIndex)
        .addFunction("ToPtr", &GRnWing_t::ToPtr)
        .addFunction("IsValid", &GRnWing_t::IsValid)
        .endClass();
}